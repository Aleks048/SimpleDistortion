/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "ASHUMUIDefines.h"

//==============================================================================
Dist_Over_BitCrAudioProcessorEditor::Dist_Over_BitCrAudioProcessorEditor (Dist_Over_BitCrAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

	//ashum048:start creating UI
	setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

	mMainPanel = make_unique<ASHUMMainPanel>(&audioProcessor);
	addAndMakeVisible(*mMainPanel);
}

Dist_Over_BitCrAudioProcessorEditor::~Dist_Over_BitCrAudioProcessorEditor()
{
}

//==============================================================================
void Dist_Over_BitCrAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void Dist_Over_BitCrAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
