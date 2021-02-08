/*
  ==============================================================================

    ASHUMGainPanel.cpp
    Created: 7 Feb 2021 1:44:10pm
    Author:  ashum048

  ==============================================================================
*/

#include "ASHUMGainPanel.h"
#include "ASHUMParameters.h"
#include "ASHUMUIDefines.h"

ASHUMGainPanel::ASHUMGainPanel(Dist_Over_BitCrAudioProcessor* inProcessor) 
	:ASHUMPanelBase(inProcessor)
{
	setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
};
ASHUMGainPanel::~ASHUMGainPanel()
{
};

void ASHUMGainPanel::setParameterID(int inParameterID)
{
	/* creates a gain slider and draws it*/

	mSlider = make_unique<ASHUMParameterSlider>(mProcessor->parameters,
												ASHUMParameterID[inParameterID]);

	const float positionFactor = .5f;
	const float sizeFactor = .3f;

	mSlider->setBounds(getWidth()*positionFactor,
					   getHeight()*positionFactor,
					   getWidth()*sizeFactor,
					   getHeight()*sizeFactor);

	addAndMakeVisible(*mSlider);
};

