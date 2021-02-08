/*
  ==============================================================================

    ASHUMCenterPanel.h
    Created: 7 Feb 2021 1:58:35pm
    Author:  ashum048

	ashum048: center panel where type of distortion and threschold can be chosen
  ==============================================================================
*/

#pragma once
#include "ASHUMPanelBase.h"
#include "ASHUMParameterSlider.h"
#include "ASHUMParameterComboBox.h"
using namespace std;

class ASHUMCenterPanel : 
	public ASHUMPanelBase
{
public:
	ASHUMCenterPanel(Dist_Over_BitCrAudioProcessor* inProcessor);
	~ASHUMCenterPanel();
	void setThreshSlider(int threshID);

	void addDistTypeListener(juce::ComboBox::Listener* inListener);
	void removeDistTypeListener(juce::ComboBox::Listener* inListener);

	void setThreshSliderVisible(bool shouldBeVisible);

	juce::String getComboBoxID();
private:
	unique_ptr<ASHUMParameterSlider> mThreshSlider;
	unique_ptr<ASHUMParameterComboBox> mDriveType;
};