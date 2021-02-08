/*
  ==============================================================================

    ASHUMPanelBase.h
    Created: 7 Feb 2021 1:43:49pm
    Author:  ashum048

	ashum048: base class. All panels inherit from it
  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"

class ASHUMPanelBase : public juce::Component {
public:
	ASHUMPanelBase(Dist_Over_BitCrAudioProcessor* inPocessor);
	~ASHUMPanelBase();

	void paint(juce::Graphics& g) override;
protected:
	juce::String mDistTypeNames[4] { "Clip", "Sin","Tanh","Pow3"};

	Dist_Over_BitCrAudioProcessor* mProcessor;
};