#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <string>

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);

    addAndMakeVisible(MidiMonitor);
    MidiMonitor.setMultiLine (true);
    MidiMonitor.setReturnKeyStartsNewLine (true);
    MidiMonitor.setReadOnly (true);
    MidiMonitor.setScrollbarsShown (true);
    MidiMonitor.setCaretVisible (false);
    MidiMonitor.setPopupMenuEnabled (true);
    MidiMonitor.setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x32ffffff));
    MidiMonitor.setColour (juce::TextEditor::outlineColourId, juce::Colour (0x1c000000));
    MidiMonitor.setColour (juce::TextEditor::shadowColourId, juce::Colour (0x16000000));
    setSize (600, 400);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

void AudioPluginAudioProcessorEditor::timerCallback()
{
    std::queue<juce::MidiMessageMetadata>* midiMessages = processorRef.getMidiMessages();
    juce::MidiMessageMetadata rawMsg = midiMessages->front();
    midiMessages->pop();
    if (!rawMsg) {
        return;
    } else {
        juce::MidiMessage msg = rawMsg.getMessage();
        MidiMonitor.logMessage(msg.getNoteNumber()); 
    }
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Isaac's plugin with a text editor component", getLocalBounds(), juce::Justification::centred, 1);
}
void AudioPluginAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    MidiMonitor.setBounds (area.reduced (8));
    //MidiMonitor.logMessage(area.toString());
}
