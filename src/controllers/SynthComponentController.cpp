/*
 *  SynthController.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 2/6/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#include "FilterNib.h"
#include "FilterParameterManager.h"
#include "Filter.h"
#include "SynthComponentController.h"

SynthComponentController::SynthComponentController(FilterNib* filterNib_) 
: filterNib (filterNib_)
{
	filterParameterManager = filterNib->getFilterParameterManager();
}

SynthComponentController::~SynthComponentController() 
{
	// all component references deleted by contentComponent
	filterParameterManager->removeChangeListener(this);
}

void SynthComponentController::awake() 
{
	filterParameterManager->addChangeListener(this);
	
	gainSlider->setValue( filterParameterManager->getGain(), false );
}

#pragma mark SliderListener methods
void SynthComponentController::sliderValueChanged (Slider* slider) 
{
	if (slider == gainSlider) {
		filterParameterManager->setGain( gainSlider->getValue() );
	}
}

#pragma mark ChangeListener methods
void SynthComponentController::changeListenerCallback (void* source)
{
	if (source == filterParameterManager ) {
		float newGain = filterParameterManager->getGain();
		gainSlider->setValue(newGain, false);
	} 
}