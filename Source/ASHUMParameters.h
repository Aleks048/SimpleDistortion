/*
  ==============================================================================

    parameters.h
    Created: 6 Feb 2021 1:28:54pm
    Author:  ashum048

	ashum048: all the data used to init and access processor parameters is stored here

  ==============================================================================
*/

#pragma once
enum ASHUMParameters {
	kParameter_InputGain = 0,
	kParameter_Threshold,
	kParameter_DryWet,
	kParameter_OutputGain,
	kParameter_DriveType,

	kParameter_TotalNumParameters
};
static juce::String ASHUMParameterID[kParameter_TotalNumParameters]
{
	"Input Gain",
	"Threschold",
	"Dry Wet",
	"Output Gain",
	"Drive type",
};
static float ASHUMParameterDefaultVal[kParameter_TotalNumParameters]
{
	.5f,
	-6.f,
	.5f,
	.5f,
	.2f
};
static float ASHUMParameterDefaultRange[kParameter_TotalNumParameters][2]
{
	{0.f,1.f},
	{-24.f,6.f},
	{0.f,1.f},
	{0.f,1.f},
	{0.f,3.f}
};