/*
  ==============================================================================

    ASHUMPanelBase.cpp
    Created: 7 Feb 2021 1:43:49pm
    Author:  ashum048

  ==============================================================================
*/

#include "ASHUMPanelBase.h"
ASHUMPanelBase::ASHUMPanelBase(Dist_Over_BitCrAudioProcessor* inProcessor) 
	:mProcessor(inProcessor)
{

};

ASHUMPanelBase::~ASHUMPanelBase() {

};

void ASHUMPanelBase::paint(juce::Graphics& g) {
	/*
	here we define the style of the panels that will be drawn later
	*/
	g.setColour(juce::Colours::beige);
	g.fillAll();

	g.setColour(juce::Colours::black);
	g.drawRect(0, 0, getWidth(), getHeight());
}