/*
  ==============================================================================

    ASHUMParameterSlider.h
    Created: 7 Feb 2021 3:07:46pm
    Author:  ashum048

	ashum048: used to assign sliders to different parameters on the AudioProcessorValueTreeState
  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
using namespace std;

class ASHUMParameterSlider: public juce::Slider
{
public:
	ASHUMParameterSlider(juce::AudioProcessorValueTreeState& stateToControl,
		const juce::String& parameterID);
	~ASHUMParameterSlider();
private:
	unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mAttachement;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ASHUMParameterSlider);
};