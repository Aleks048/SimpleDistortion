/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "ASHUMParameters.h"

//==============================================================================
; Dist_Over_BitCrAudioProcessor::Dist_Over_BitCrAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
		parameters(*this,nullptr)
#endif
{
	initializeDSP();

	initializeParameters();
}

Dist_Over_BitCrAudioProcessor::~Dist_Over_BitCrAudioProcessor()
{
}

//==============================================================================
const juce::String Dist_Over_BitCrAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Dist_Over_BitCrAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Dist_Over_BitCrAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Dist_Over_BitCrAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Dist_Over_BitCrAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Dist_Over_BitCrAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Dist_Over_BitCrAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Dist_Over_BitCrAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Dist_Over_BitCrAudioProcessor::getProgramName (int index)
{
    return {};
}

void Dist_Over_BitCrAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Dist_Over_BitCrAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void Dist_Over_BitCrAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Dist_Over_BitCrAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Dist_Over_BitCrAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
	
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

		//ashum048: called by juice for each sample
		mDist->process(
			channelData,
			getParameter(kParameter_Threshold),
			getParameter(kParameter_InputGain),
			getParameter(kParameter_DryWet),
			getParameter(kParameter_DriveType),
			channelData,
			buffer.getNumSamples()
		);
    }
}

//==============================================================================
bool Dist_Over_BitCrAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Dist_Over_BitCrAudioProcessor::createEditor()
{
    return new Dist_Over_BitCrAudioProcessorEditor (*this);
}

//==============================================================================
void Dist_Over_BitCrAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Dist_Over_BitCrAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Dist_Over_BitCrAudioProcessor();
}

void Dist_Over_BitCrAudioProcessor::initializeDSP() {
	/*
	ashum048: this is where we init all the DSP classes
	*/
	mDist = make_unique<ASHUMDist>();
}

void Dist_Over_BitCrAudioProcessor::initializeParameters() {
	/*
	ashum048: create the parameters in the processor that the DAW can control
	*/
	for (int i = 0; i < kParameter_TotalNumParameters; i++) {
		if (i == kParameter_DriveType) {
			parameters.createAndAddParameter(make_unique<juce::AudioParameterInt>(
				ASHUMParameterID[i],//ID
				ASHUMParameterID[i],//Name
				(int)ASHUMParameterDefaultRange[i][0],//min
				(int)ASHUMParameterDefaultRange[i][1],//max
				(int)ASHUMParameterDefaultVal[i],//Default
				ASHUMParameterID[i],//Label
				nullptr,
				nullptr)
			);
		}
		else {
			parameters.createAndAddParameter(make_unique<juce::AudioProcessorValueTreeState::Parameter>(
				ASHUMParameterID[i],//ID
				ASHUMParameterID[i],//Name
				ASHUMParameterID[i],//Label
				juce::NormalisableRange<float>(
					ASHUMParameterDefaultRange[i][0],
					ASHUMParameterDefaultRange[i][1]),//Range
				ASHUMParameterDefaultVal[i],//Default
				[](float val) {
					stringstream ss;
					ss << fixed << setprecision(2) << val;
					return ss.str();
				},
				nullptr)
			);
		}
	}
	parameters.state = juce::ValueTree("Foo");//we need to name the state or it would crash
}
