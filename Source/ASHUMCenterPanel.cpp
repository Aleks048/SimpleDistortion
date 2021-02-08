/*
  ==============================================================================

    ASHUMCenterPanel.cpp
    Created: 7 Feb 2021 1:58:35pm
    Author:  ashum048

  ==============================================================================
*/

#include "ASHUMCenterPanel.h"
#include "ASHUMUIDefines.h"
#include "ASHUMParameters.h"

ASHUMCenterPanel::ASHUMCenterPanel(Dist_Over_BitCrAudioProcessor* inProcessor) 
	:ASHUMPanelBase(inProcessor)
{
	setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);

	mDriveType = make_unique<ASHUMParameterComboBox>
					(mProcessor->parameters, ASHUMParameterID[kParameter_DriveType]);
	mDriveType->setBounds(100, 100, 100, 100);

	for (int i = 0; i < sizeof(mDistTypeNames) / sizeof(*mDistTypeNames); i++) {
		mDriveType->addItem(mDistTypeNames[i], i+1);
	}

	mDriveType->setSelectedItemIndex((int)mProcessor->getParameter(kParameter_DriveType), 
									  juce::dontSendNotification);
	addAndMakeVisible(*mDriveType);

};
ASHUMCenterPanel::~ASHUMCenterPanel() 
{
};

void ASHUMCenterPanel::setThreshSlider(int threshID)
{
	mThreshSlider = make_unique<ASHUMParameterSlider>(mProcessor->parameters,
		ASHUMParameterID[threshID]);

	const float positionFactor = .5f;
	const float sizeFactor = .3f;

	mThreshSlider->setBounds(getWidth()*positionFactor,
		getHeight()*positionFactor,
		getWidth()*sizeFactor,
		getHeight()*sizeFactor);

	addAndMakeVisible(*mThreshSlider);
};

void ASHUMCenterPanel::addDistTypeListener(juce::ComboBox::Listener* inListener)
{
	mDriveType->addListener(inListener);
};
void ASHUMCenterPanel::removeDistTypeListener(juce::ComboBox::Listener* inListener)
{
	mDriveType->removeListener(inListener);
};



void ASHUMCenterPanel::setThreshSliderVisible(bool shouldBeVisible)
{
	/* different distortion types don't use threshold so we hide itd*/
	if (shouldBeVisible && !mThreshSlider->isShowing()) {
		mThreshSlider->setVisible(true);
	}
	else if (!shouldBeVisible && mThreshSlider->isShowing()) {
		mThreshSlider->setVisible(false);
	}
};

juce::String ASHUMCenterPanel::getComboBoxID() {
	return mDriveType->getComponentID();
};
