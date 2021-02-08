/*
  ==============================================================================

    ASHUMDist.cpp
    Created: 6 Feb 2021 11:17:50am
    Author:  ashum048

	ashum048: all DSP regarding distortion is happening here
  ==============================================================================
*/

#include "ASHUMDist.h"
#include "JuceHeader.h"
#include "ASHUMParameters.h"
#include "ASHUMPluginEnums.h"

ASHUMDist::ASHUMDist() 
{

}

ASHUMDist::~ASHUMDist()
{

}

void ASHUMDist::process(float* inAudio,
	float inThresh,
	float inInputGain,
	float inDryWet,
	float inDistType,
	float* outAudio,
	int numSamplesToRender
) 
	
{
	/*
	sample by sample processing. called for each buffer block
	*/

	//map to have integer valued distortion type
	int inDistTypeMapped = (int)juce::jmap(inDistType, 0.f, 1.f, 
								ASHUMParameterDefaultRange[kParameter_DriveType][0], 
								ASHUMParameterDefaultRange[kParameter_DriveType][1]);
	
	//expanding the input gain to get more drastic results
	float inGainMapped = juce::jmap(inInputGain, 0.f, 1.f, 0.f, 2.5f);

	const float wet = inDryWet;
	const float dry = 1.f - inDryWet;

	for (int i = 0; i < numSamplesToRender; i++) {
		float distSample=0.f;

		switch (inDistTypeMapped) {
			case kClippingDist: {
				if ((inAudio[i]) < inThresh) {
					distSample = inAudio[i]* inGainMapped;
				}
				else {
					distSample = inThresh* inGainMapped;
				}
				break;
			}
			case kSinDist: {
				distSample = sin(inGainMapped*inAudio[i]);
				break;
			}
			case kTanhDist: {
				distSample = tanh(inGainMapped * inAudio[i]);
				break;
			}
			case kPow3Dist: {
				distSample = pow(inAudio[i],3)*inGainMapped;
				break;
			}
			default: {
				jassert("Wrong distortion type type.");
			}
		}

		outAudio[i] = inAudio[i] * dry + distSample*wet;
	}
}