/*
 *  AbstractParameterManager.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/18/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "Filter.h"
#include "FilterProperty.h"
#include "FilterSetting.h"
#include "AbstractParameterManager.h"

// This MUST be called before any properties are set!
void AbstractParameterManager::setFilter(Filter* filter_) {
	filter = filter_;
	filter->addChangeListener(this);
}

AbstractParameterManager::AbstractParameterManager() {
}

AbstractParameterManager::~AbstractParameterManager() {
}

#pragma mark Properties Methods

void AbstractParameterManager::clearProperties() {
	properties.clear(true);
}

int AbstractParameterManager::addProperty(FilterProperty* p) {
	properties.add(p);
	int index = properties.indexOf(p);
	return index;
}

void AbstractParameterManager::setPropertyValueWithIndex(int index, float value) {
	FilterProperty* p = properties[index];
	p->setValue(value);
	jassert(filter != NULL);
	filter->setParameterNotifyingHost(index, value);
}

FilterProperty* AbstractParameterManager::getPropertyWithIndex(int index) {
	FilterProperty* p = properties[index];
	return p;
}

float AbstractParameterManager::getPropertyValueWithIndex(int index) {
	float value = properties[index]->getValue();
	return value;
}

int AbstractParameterManager::getNumProperties() {
	return properties.size();
}

#pragma mark Settings Methods

void AbstractParameterManager::clearSettings() {
	settings.clear(true);
}

int AbstractParameterManager::addSetting(FilterSetting* s) {
	settings.add(s);
	int index = settings.indexOf(s);
	return index;
}

void AbstractParameterManager::setSettingValueWithIndex(int index, float value) {
	FilterSetting* s = settings[index];
	s->setValue(value);
}

FilterSetting* AbstractParameterManager::getSettingWithIndex(int index) {
	FilterSetting* s = settings[index];
	return s;
}

float AbstractParameterManager::getSettingValueWithIndex(int index) {
	float value = settings[index]->getValue();
	return value;
}

int AbstractParameterManager::getNumSettings() {
	return settings.size();
}

#pragma mark ChangeListener methods

void AbstractParameterManager::changeListenerCallback (void* source) {
	filter->getCallbackLock().enter();
	// Record filter parameters to a temporary array then exit the lock
	Array <float> params;
	int numParams = filter->getNumParameters();
	params.ensureStorageAllocated(numParams);
	for (int i = 0; i < numParams; ++i) {
		// setUnchecked would be faster!
		params.add(filter->getParameter(i) );
	}
	filter->getCallbackLock().exit();
	for (int i = 0; i < numParams; ++i) {
		properties[i]->setValue(params[i]); 
	}
	sendChangeMessage(this);
}
