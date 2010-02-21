/*
 *  FilterSetting.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/18/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#ifndef FILTER_SETTING_H
#define FILTER_SETTING_H

#include "includes.h"

// CLASS: FilterSetting
// PURPOSE: Store a filter setting that is recorded in the XML file.
//    This value is not adjustable in the editor.
// SEE: FilterProperty

class FilterSetting  {
public:
	FilterSetting() { }
	~FilterSetting() { }
	
	void setIndex(int index_);
	int getIndex();
	
	void setXMLName(String xmlName_);
	String getXMLName();
	
	void setValue(float value_);
	float getValue();

	juce_UseDebuggingNewOperator	
private:
	int index;       // Index into settings array
	String xmlName;  // Name as recorded in XML
	float value;
};

#endif