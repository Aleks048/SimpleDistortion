/*
  ==============================================================================

    ASHUMMainPanel.cpp
    Created: 7 Feb 2021 1:44:48pm
    Author:  ashum048

  ==============================================================================
*/

#include "ASHUMMainPanel.h"
#include "ASHUMUIDefines.h"
#include "ASHUMParameters.h"
#include "ASHUMPluginEnums.h"

ASHUMMainPanel::ASHUMMainPanel(Dist_Over_BitCrAudioProcessor* inProcessor)
	:ASHUMPanelBase(inProcessor)
{
	setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

	int widthPos = 0;
	int heightPos = 0;
	
	mInputGainPanel = make_unique<ASHUMGainPanel>(inProcessor);
	mInputGainPanel->setTopLeftPosition(widthPos, heightPos);
	mInputGainPanel->setParameterID(kParameter_InputGain);
	widthPos += GAIN_PANEL_WIDTH;
	addAndMakeVisible(*mInputGainPanel);

	mCenterPanel = make_unique<ASHUMCenterPanel>(inProcessor);
	mCenterPanel->setTopLeftPosition(widthPos, heightPos);
	mCenterPanel->setThreshSlider(kParameter_Threshold);
	widthPos += CENTER_PANEL_WIDTH;
	mCenterPanel->addDistTypeListener(this);
	addAndMakeVisible(*mCenterPanel);

	mOutputGainPanel = make_unique<ASHUMGainPanel>(inProcessor);
	mOutputGainPanel->setTopLeftPosition(widthPos, heightPos);
	mOutputGainPanel->setParameterID(kParameter_OutputGain);
	addAndMakeVisible(*mOutputGainPanel);

};
ASHUMMainPanel::~ASHUMMainPanel() {
	mCenterPanel->removeDistTypeListener(this);
};
void ASHUMMainPanel::comboBoxChanged(juce::ComboBox* comboboxThatHasChanged) {
	if (comboboxThatHasChanged->getComponentID() == mCenterPanel->getComboBoxID()) {
		/*when type of distortion has changed*/
		DistTypes distType = (DistTypes)comboboxThatHasChanged->getSelectedItemIndex();
		if (distType == DistTypes::kClippingDist) {
			mCenterPanel->setThreshSliderVisible(true);
		}
		else {
			mCenterPanel->setThreshSliderVisible(false);
		}
	}
}