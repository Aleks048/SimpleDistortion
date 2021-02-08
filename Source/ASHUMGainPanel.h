/*
  ==============================================================================

    ASHUMGainPanel.h
    Created: 7 Feb 2021 1:44:10pm
    Author:  ashum048

	ashum: gain panel
  ==============================================================================
*/

#pragma once
#include "ASHUMPanelBase.h"
#include "ASHUMParameterSlider.h"

class ASHUMGainPanel : public ASHUMPanelBase {
public:
	ASHUMGainPanel(Dist_Over_BitCrAudioProcessor* inProcessor);
	~ASHUMGainPanel();

	void setParameterID(int inParameterID);
private:
	unique_ptr<ASHUMParameterSlider> mSlider;
};