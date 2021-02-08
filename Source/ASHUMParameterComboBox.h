/*
  ==============================================================================

    ASHUMParameterComboBox.h
    Created: 7 Feb 2021 3:08:10pm
    Author:  ashum048

	ashum048: used to assign comboBoxes to different parameters on the AudioProcessorValueTreeState
  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
using namespace std;

class ASHUMParameterComboBox :
	public juce::ComboBox {

public:
	ASHUMParameterComboBox(juce::AudioProcessorValueTreeState& stateToControl,
		const juce::String& parameterID);
	~ASHUMParameterComboBox();
private:
	unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ASHUMParameterComboBox);
};