/*
  ==============================================================================

    ASHUMDist.h
    Created: 6 Feb 2021 11:17:50am
    Author:  ashum048

  ==============================================================================
*/
#pragma once
class ASHUMDist {
public:
	ASHUMDist();
	~ASHUMDist();

	void  process(float* inAudio,
				  float inThresh,
				  float inGain,
			      float inDryWet,
				  float inDistType,
				  float* outAudio,
				  int numSamplesToRender
		);
private:
	
};