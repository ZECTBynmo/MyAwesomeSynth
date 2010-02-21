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

//[Headers] You can add your own extra header files here...
#include "FilterNib.h"
#include "FilterManager.h"
#include "SynthComponentController.h"
//[/Headers]

#include "SynthComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SynthComponent::SynthComponent (FilterNib* filterNib_)
    : midiKeyboard (0),
      gainSlider (0)
{
    //[Constructor_pre]
	filterNib = filterNib_;
    //[/Constructor_pre]

    addAndMakeVisible (midiKeyboard = new MidiKeyboardComponent (filterNib->getFilterManager()->getKeyboardState(),
                                                                 MidiKeyboardComponent::horizontalKeyboard));
    midiKeyboard->setName (T("midi keyboard"));

    addAndMakeVisible (gainSlider = new Slider (T("gain slider")));
    gainSlider->setRange (0, 1, 0);
    gainSlider->setSliderStyle (Slider::Rotary);
    gainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    gainSlider->setColour (Slider::thumbColourId, Colour (0xffa6a6ff));
    gainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
    synthComponentController = new SynthComponentController(filterNib);
	synthComponentController->synthComponent = this;
	synthComponentController->gainSlider = gainSlider;

	gainSlider->addListener(synthComponentController);
	synthComponentController->awake();
    //[/Constructor]
}

SynthComponent::~SynthComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (midiKeyboard);
    deleteAndZero (gainSlider);

    //[Destructor]. You can add your own custom destruction code here..
	deleteAndZero (synthComponentController);
    //[/Destructor]
}

//==============================================================================
void SynthComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (Font (T("Adobe Garamond Pro"), 50.6000f, Font::bold));
    g.drawText (T("My Awesome Synth"),
                -4, 12, proportionOfWidth (1.0000f), 52,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (12.0f, 73.0f, (float) (getWidth() - 27), (float) (getHeight() - 131), 10.0000f);

    g.setColour (Colour (0xff6a6a6a));
    g.drawRoundedRectangle (12.0f, 73.0f, (float) (getWidth() - 27), (float) (getHeight() - 131), 10.0000f, 1.8000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SynthComponent::resized()
{
    midiKeyboard->setBounds (16, getHeight() - 9 - 40, getWidth() - 37, 40);
    gainSlider->setBounds (24, 88, getWidth() - 51, getHeight() - 153);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SynthComponent" componentName=""
                 parentClasses="public Component" constructorParams="FilterNib* filterNib_"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330000013" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="-4 12 100% 52" fill="solid: ff000000" hasStroke="0" text="My Awesome Synth"
          fontname="Adobe Garamond Pro" fontsize="50.6" bold="1" italic="0"
          justification="36"/>
    <ROUNDRECT pos="12 73 27M 131M" cornerSize="10" fill="solid: ff000000" hasStroke="1"
               stroke="1.79999995, mitered, butt" strokeColour="solid: ff6a6a6a"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="midi keyboard" id="4a8c7fe932fc5db1" memberName="midiKeyboard"
                    virtualName="" explicitFocusOrder="0" pos="16 9Rr 37M 40" class="MidiKeyboardComponent"
                    params="filterNib-&gt;getFilterManager()-&gt;getKeyboardState(),&#10;MidiKeyboardComponent::horizontalKeyboard"/>
  <SLIDER name="gain slider" id="7ec19df4b4ad1e60" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="24 88 51M 153M" thumbcol="ffa6a6ff"
          rotarysliderfill="7fffffff" min="0" max="1" int="0" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
