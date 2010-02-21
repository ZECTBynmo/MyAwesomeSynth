/*
 *  SynthController.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 2/6/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#ifndef SYNTH_COMPONENT_CONTROLLER_H
#define SYNTH_COMPONENT_CONTROLLER_H

#include "includes.h"

class FilterNib;
class FilterParameterManager;

class SynthComponentController : public SliderListener,
public ChangeListener
{
public:
	SynthComponentController(FilterNib* filterNib);
	~SynthComponentController();	
	void awake ();
	// SliderListener methods
	void sliderValueChanged (Slider* slider);
	// ChangeListener methods
	void changeListenerCallback (void* source);
	
	// Outlets
	Component *synthComponent;
	Slider* gainSlider;
private:
	FilterNib* filterNib;
	FilterParameterManager* filterParameterManager;
};

#endif