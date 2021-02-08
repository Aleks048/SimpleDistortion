/*
  ==============================================================================

    ASHUMParameterSlider.cpp
    Created: 7 Feb 2021 3:07:46pm
    Author:  ashum048

  ==============================================================================
*/

#include "ASHUMParameterSlider.h"

ASHUMParameterSlider::ASHUMParameterSlider(juce::AudioProcessorValueTreeState& stateToControl,
	const juce::String& parameterID):
	Slider(parameterID)
{
	setSliderStyle(Slider::LinearVertical);
	setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);

	setRange(0.f, 1.f,.001f);

	mAttachement = make_unique <juce::AudioProcessorValueTreeState::SliderAttachment>
												(stateToControl, parameterID, *this);
};
ASHUMParameterSlider::~ASHUMParameterSlider() 
{
};