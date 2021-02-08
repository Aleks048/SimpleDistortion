# SimpleDistortion
Implementation of Distortion effect with juce

The reason I am proud of this project is because through this project I was able to create a finished audio effect with dynamic UI. 

This is an implementation of 4 types of dirtortion effects.
  1) clipping
  2) sin
  3) tanh
  4) pow3

### The structure of the project:
    .
    ├── Parameter Control                  # The files are used to connect UI to the audio processor parameters.
    │     ├── ASHUMParameterComboBox.h
    │     └── ASHUMParameterSlider.h
    ├── Panels                             # All the Panel files are UI. They inherit from BasePanel.h. MainPanel.h renders all the other panels and controls them.
    │     ├── ASHUMPanelBase.h
    │     ├── ASHUMMainPanel.h            
    │     ├── ASHUMGainPanel.h
    │     └── ASHUMCenterPanel.h
    ├── Parameter Control
    │     ├── ASHUMParameterComboBox.h
    │     └── ASHUMParameterSlider.h
    ├── utils                              # unitls used for data organization
    │     ├── ASHUMParameters.h
    │     ├── ASHUMPluginEnums.h
    │     └── ASHUMUIDefines.h
    ├── DSP                                # All the all the DSP files.
    │     └── ASHUMUIDist.h
    ├── Source                             # PluginEditor.h and PluginProcessor.h are provided by JUCE and modified only slightly.
    │     ├── PluginProcessor.h
    │     └── PluginEditor.h
    └── README.md




