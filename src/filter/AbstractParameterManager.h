/*
 *  AbstractParameterManager.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/18/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#ifndef ABSTRACT_PARAMETER_MANAGER_H
#define ABSTRACT_PARAMETER_MANAGER_H

#include "includes.h"

class Filter;
class FilterProperty;
class FilterSetting;

// Abstract class that manages all filter properties and settings

class AbstractParameterManager : public ChangeBroadcaster,
								 public ChangeListener // filter listener
{
public:
	AbstractParameterManager();
	~AbstractParameterManager();

	void clearProperties();
	void setPropertyValueWithIndex(int index, float value);
	FilterProperty* getPropertyWithIndex(int index);
	float getPropertyValueWithIndex(int index);
	int getNumProperties();
	
	void clearSettings();
	void setSettingValueWithIndex(int index, float value);
	FilterSetting* getSettingWithIndex(int index);
	float getSettingValueWithIndex(int index);
	int getNumSettings();
	
	void setFilter(Filter* filter_);	

	// ChangeListener methods
	void changeListenerCallback (void* source);	
	
	juce_UseDebuggingNewOperator	
protected:
	int addProperty(FilterProperty*); // returns index 
	int addSetting(FilterSetting*);   // returns index
private:
	OwnedArray<FilterProperty> properties;
	OwnedArray<FilterSetting> settings; 
	Filter* filter;
};

#endif