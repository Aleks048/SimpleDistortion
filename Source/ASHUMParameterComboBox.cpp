/*
  ==============================================================================

    ASHUMParameterComboBox.cpp
    Created: 7 Feb 2021 3:08:10pm
    Author:  ashum048

  ==============================================================================
*/

#include "ASHUMParameterComboBox.h"


ASHUMParameterComboBox::ASHUMParameterComboBox(juce::AudioProcessorValueTreeState& stateToControl,
	const juce::String& parameterID):
	ComboBox(parameterID)
{
	mAttachment = make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>
		(stateToControl, parameterID, *this);
};

ASHUMParameterComboBox::~ASHUMParameterComboBox() 
{

};