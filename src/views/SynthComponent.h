/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  20 Feb 2010 1:19:58 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SYNTHCOMPONENT_SYNTHCOMPONENT_70E5AD0C__
#define __JUCER_HEADER_SYNTHCOMPONENT_SYNTHCOMPONENT_70E5AD0C__

//[Headers]     -- You can add your own extra header files here --
#include "includes.h"
class SynthComponentController;
class FilterNib;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SynthComponent  : public Component
{
public:
    //==============================================================================
    SynthComponent (FilterNib* filterNib_);
    ~SynthComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	FilterNib* filterNib;
    SynthComponentController* synthComponentController;
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    MidiKeyboardComponent* midiKeyboard;
    Slider* gainSlider;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    SynthComponent (const SynthComponent&);
    const SynthComponent& operator= (const SynthComponent&);
};


#endif   // __JUCER_HEADER_SYNTHCOMPONENT_SYNTHCOMPONENT_70E5AD0C__
