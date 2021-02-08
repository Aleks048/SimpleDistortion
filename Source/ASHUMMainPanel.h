/*
  ==============================================================================

    ASHUMMainPanel.h
    Created: 7 Feb 2021 1:44:48pm
    Author:  ashum048

	ashum048: main panel that contains all other panels
  ==============================================================================
*/

#pragma once
#include "ASHUMPanelBase.h"
#include "ASHUMGainPanel.h"
#include "ASHUMCenterPanel.h"

using namespace std;

class ASHUMMainPanel : 
	public ASHUMPanelBase,
	public juce::ComboBox::Listener
{
public:
	ASHUMMainPanel(Dist_Over_BitCrAudioProcessor* inProcessor);
	~ASHUMMainPanel();

	void comboBoxChanged(juce::ComboBox* comboboxThatHasChanged) override;
private:
	unique_ptr<ASHUMGainPanel> mInputGainPanel;
	unique_ptr<ASHUMGainPanel> mOutputGainPanel;
	unique_ptr<ASHUMCenterPanel> mCenterPanel;
};
