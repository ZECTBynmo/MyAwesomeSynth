/*
 *  FilterParameterManager.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/20/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "FilterNib.h"
#include "FilterParameterManager.h"
#include "NumberFilterProperty.h"
#include "FilterProperty.h"
#include "FilterSetting.h"

FilterParameterManager::FilterParameterManager(FilterNib* filterNib_) 
: filterNib (filterNib_)
{
	clearProperties();
	clearSettings();

	int index;
	
	// Properties
	gain = new FilterProperty();
	gain->setName( T("Gain") );
	gain->setXMLName( T("gainLevel") );
	gain->setValue( 1.0f );
	gain->setUnit( T("db") );
	index = addProperty(gain);
	gain->setIndex(index);	
	
	//--------------------------------------------
	lastUIWidth = new FilterSetting();
	lastUIWidth->setXMLName( T("lastUIWidth") );
	lastUIWidth->setValue( 600 );
	index = addSetting(lastUIWidth);
	lastUIWidth->setIndex(index);	

	lastUIHeight = new FilterSetting();
	lastUIHeight->setXMLName( T("lastUIHeight") );
	lastUIHeight->setValue( 600 );
	index = addSetting(lastUIHeight);
	lastUIHeight->setIndex(index);	

}

FilterParameterManager::~FilterParameterManager() {
	// OwnedArray handles deletions
	//clearSingletonInstance();
}

#pragma mark Properties
void FilterParameterManager::setGain(float g) {
	setPropertyValueWithIndex( gain->getIndex(), g );
}
float FilterParameterManager::getGain() {
	return getPropertyValueWithIndex( gain->getIndex() );
}

#pragma mark Settings
void FilterParameterManager::setLastUIHeight(float h) {
	setSettingValueWithIndex( lastUIHeight->getIndex(), h );
}
float FilterParameterManager::getLastUIHeight() {
	return getSettingValueWithIndex( lastUIHeight->getIndex() );
}

void FilterParameterManager::setLastUIWidth(float w) {
	setSettingValueWithIndex( lastUIWidth->getIndex(), w );
}
float FilterParameterManager::getLastUIWidth() {
	return getSettingValueWithIndex( lastUIWidth->getIndex() );
}
