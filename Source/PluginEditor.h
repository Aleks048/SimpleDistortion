/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "ASHUMMainPanel.h"
using namespace std;

//==============================================================================
/**
*/
class Dist_Over_BitCrAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Dist_Over_BitCrAudioProcessorEditor (Dist_Over_BitCrAudioProcessor&);
    ~Dist_Over_BitCrAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Dist_Over_BitCrAudioProcessor& audioProcessor;

	unique_ptr<ASHUMMainPanel> mMainPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Dist_Over_BitCrAudioProcessorEditor)
};
