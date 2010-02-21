/*
 *  FilterSetting
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/18/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "FilterSetting.h"

void FilterSetting::setIndex(int index_) { 
	index = index_; 
}
int FilterSetting::getIndex() { 
	return index; 
}

void FilterSetting::setXMLName(String xmlName_) { 
	xmlName = xmlName_; 
} 
String FilterSetting::getXMLName() { 
	return xmlName; 
}

void FilterSetting::setValue(float value_) { 
	value = value_; 
}
float FilterSetting::getValue() { 
	return value; 
}
