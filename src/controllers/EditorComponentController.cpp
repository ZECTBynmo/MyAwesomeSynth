/*
 *  EditorComponentController.cpp
 *  NetSynth
 *
 *  Created by Matt Sonic on 12/7/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "EditorComponentController.h"

EditorComponentController::EditorComponentController() {
}

EditorComponentController::~EditorComponentController() {
	filter->removeChangeListener(this);
}

void EditorComponentController::changeListenerCallback(void* source) {
	// Update parameters from filter
	filter->getCallbackLock().enter();
	//const float newGain = filter->getParameter(0);
	filter->getCallbackLock().exit();
	//gainSlider->setValue(newGain, false);
}

void EditorComponentController::sliderValueChanged(Slider*) {
	//filter->setParameterNotifyingHost(0, (float)gainSlider->getValue());
}