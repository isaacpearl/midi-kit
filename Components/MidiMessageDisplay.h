#pragma once

#include <juce_graphics/juce_graphics.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_gui_extra/juce_gui_extra.h>

namespace Gui
{
    class MidiMessageDisplay : public juce::TextEditor
    {
        public:
            void paint(juce::Graphics& g) override
            {
                auto bounds = juce::Component::getLocalBounds().toFloat();
                g.fillAll (juce::Colours::black);
            }

            void logMessage (const juce::String& m)
            {
                (*this).moveCaretToEnd();
                (*this).insertTextAtCaret (m + juce::newLine);
            }
        private:
    };
}
