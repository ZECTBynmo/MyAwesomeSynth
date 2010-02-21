/*
 *  FilterParameterManager.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/20/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#ifndef FILTER_PARAMETER_MANAGER_H
#define FILTER_PARAMETER_MANAGER_H

#include "AbstractParameterManager.h"

class FilterNib;
class FilterProperty;
class NumberFilterProperty;
class FilterSetting;

class FilterParameterManager : public AbstractParameterManager
{
public:
	FilterParameterManager(FilterNib* filterNib_);
	~FilterParameterManager();
	// properties
	void setGain(float);
	float getGain();

	// settings
	void setLastUIHeight(float);
	float getLastUIHeight();

	void setLastUIWidth(float);
	float getLastUIWidth();

	juce_UseDebuggingNewOperator	
private:
	FilterProperty* gain;
	
	FilterSetting* lastUIWidth;
	FilterSetting* lastUIHeight;

	FilterNib* filterNib;
};

#endif