# SimpleDistortion
Implementation of Distortion effect with juce

This is an implementation of 4 types of dirtortion effects.
  1) clipping
  2) sin
  3) tanh
  4) pow3

All the DSP is in the Dist.h file.

Parameters.h , PluginEnums.h, Defines.h are unitls used for data organization.

All the Panels files are UI. They inherit from BasePanel.h. MainPanel.h renders all the other panels and controls them.

ParameterComboBox.h and ParameterSlider.h are used to connect UI to the audio processor parameters.

PluginEditor.h and PluginProcessor.h are provided by JUCE and modified only slightly.

