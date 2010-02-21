/*
 *  FilterManager.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/3/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#include "FilterNib.h"
#include "SynthAudioSource.h"
#include "Filter.h"
#include "FilterManager.h"

void FilterManager::setFilter(Filter* filter_) 
{
	filter = filter_;
	filter->addChangeListener(this);
}

FilterManager::FilterManager(FilterNib* filterNib_) 
: filterNib (filterNib_)
{
}

FilterManager::~FilterManager() 
{
	//clearSingletonInstance();
}

MidiKeyboardState& FilterManager::getKeyboardState() 
{
	return filter->keyboardState;
}

AudioPlayHead::CurrentPositionInfo FilterManager::getPositionInfo() 
{
	return positionInfo;
}

#pragma mark ChangeListener methods
void FilterManager::changeListenerCallback (void* source) 
{
	if (source == filter) {
		filter->getCallbackLock().enter();
		const AudioPlayHead::CurrentPositionInfo newPositionInfo (filter->lastPosInfo);
		filter->getCallbackLock().exit();

		positionInfo = newPositionInfo;
		
		sendChangeMessage(this);
	}
}


