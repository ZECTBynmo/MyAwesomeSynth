/*
 *  FilterManager.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/3/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#ifndef FILTER_MANAGER_H
#define FILTER_MANAGER_H

//------------------------------------------------------------------------------
// CLASS: FilterManager
// PURPOSE: Singleton manager for the main audio filter
//------------------------------------------------------------------------------

#include "includes.h"

class FilterNib;
class Filter;
class Sound;

class FilterManager : public ChangeListener,
					  public ChangeBroadcaster
{
public:
	FilterManager(FilterNib* filterNib_);
	~FilterManager();
	
	void setFilter(Filter* filter_); // MUST be called before other methods!
	
	MidiKeyboardState& getKeyboardState();
	
	AudioPlayHead::CurrentPositionInfo getPositionInfo();
	
	// ChangeListener methods
	void changeListenerCallback (void* source);	
	
	juce_UseDebuggingNewOperator	
private:
	Filter* filter; // outlet
	AudioPlayHead::CurrentPositionInfo positionInfo;
	
	FilterNib* filterNib;
};

#endif