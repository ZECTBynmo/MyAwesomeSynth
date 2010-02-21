/*
 *  FilterProperty.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/18/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#ifndef FILTER_PROPERTY_H
#define FILTER_PROPERTY_H

#include "includes.h"

// CLASS: FilterProperty 
// PURPOSE: Base class for a filter property that can be adjusted in the editor.
//    This class creates a generic parameter with a value between 0 and 1.

class FilterProperty {
public:	
	FilterProperty();
	~FilterProperty();

	void setIndex(int index_);
	int getIndex();
	
	void setName(String name_);
	String getName();

	void setUnit(String unit_);
	String getUnit();	
	
	void setXMLName(String xmlName_);
	String getXMLName();
	
	void setValue(float value_);
	float getValue(); // returns the property value as a float between 0 and 1.0
	
	// Get parameter text
	virtual String getText();

	juce_UseDebuggingNewOperator	
protected:
	int index;       // Index into properties array
	String name;     // Name as shown in editor
	String unit;     // Units as shown in editor
	String xmlName;  // Name as recorded in XML
	float value;     // Value between 0 and 1
};

#endif