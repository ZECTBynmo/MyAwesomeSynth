/*
 *  NumberFilterProperty.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/1/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#ifndef NUMBER_FILTER_PROPERTY_H
#define NUMBER_FILTER_PROPERTY_H

#include "FilterProperty.h"
#include "includes.h"

// CLASS: NumberFilterProperty
// PURPOSE: A numeric filter property with an adjustable range.

class NumberFilterProperty : public FilterProperty 
{
public:
	NumberFilterProperty();	
	~NumberFilterProperty();
	
	// Set the range of the filter property. E.g. 3.5 to 10.9
	void setScaledRange(float start_, float end_);
	
	// Return the value of filter parameter, scaled according to start and end of the range 
	float getValueInScaledRange();
	
	// Set the parameter value by translating from a scaled range value to a normalized value
	void setValueFromScaledRange(float scaled);
	
	virtual String getText();
	
	juce_UseDebuggingNewOperator	
private:
	float start;
	float end;
};

#endif