/*
 *  EditorComponentController.h
 *  NetSynth
 *
 *  Created by Matt Sonic on 12/7/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#ifndef EDITOR_COMPONENT_CONTROLLER_H
#define EDITOR_COMPONENT_CONTROLLER_H

#include "Filter.h"
#include "FilterParameterManager.h"

class EditorComponentController : public ChangeListener,
								  public SliderListener 
{
public:
	EditorComponentController();
	~EditorComponentController();
	void changeListenerCallback(void* source); 
	void sliderValueChanged(Slider*); 
	Filter* filter;
};

#endif
