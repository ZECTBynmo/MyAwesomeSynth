/*
 *  FilterProperty.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/18/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "FilterProperty.h"

FilterProperty::FilterProperty() {
}

FilterProperty::~FilterProperty() {
}

void FilterProperty::setIndex(int index_) { 
	index = index_; 
}
int FilterProperty::getIndex() { 
	return index; 
}

void FilterProperty::setName(String name_) { 
	name = name_; 
} 
String FilterProperty::getName() { 
	return name; 
}

void FilterProperty::setUnit(String unit_) {
	unit = unit_;
}
String FilterProperty::getUnit() {
	return unit;
}

void FilterProperty::setXMLName(String xmlName_) { 
	xmlName = xmlName_; 
} 
String FilterProperty::getXMLName() { 
	return xmlName; 
}

void FilterProperty::setValue(float value_) { 
	value = value_; 
}
float FilterProperty::getValue() { 
	return value; 
}

String FilterProperty::getText() { 
	// Get parameter text
	String text = String(value, 2);
	if (unit != String::empty) text += T(" ") + unit;
	return text; 
}
