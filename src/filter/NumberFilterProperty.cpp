/*
 *  NumberFilterProperty.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/1/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#include "NumberFilterProperty.h"

NumberFilterProperty::NumberFilterProperty() 
: start(0),
end(1)
{ 
}
	
NumberFilterProperty::~NumberFilterProperty() { }
	
void NumberFilterProperty::setScaledRange(float start_, float end_) 
{
	// Set the range of the filter property. E.g. 3.5 to 10.9
	start = start_;
	end = end_;
}

float NumberFilterProperty::getValueInScaledRange() 
{
	// Return the value of filter parameter, scaled according to start and end of the range 
	float v = (value * (end - start)) + start;
	if (v < start) v = start;
	else if (v > end) v = end;
	return v;
	/*
	 value   x - start
	 ---  =  --------   
	 1      end - start  

	 x - start = value * (end - start)
	 x = (value * (end - start)) + start
	*/
}

void NumberFilterProperty::setValueFromScaledRange(float scaled) 
{
	// Set the parameter value by translating from a scaled range value to a normalized value
	float v = ((scaled - start) / (end - start));
	if (v < 0) v = 0;
	else if (v > 1) v = 1;
	value = v;
	/*
	 x      scaled - start  
	 ---  =  --------   
	 1      end - start  
	 	 
	 x * (end - start) = (scaled - start)
	 x = (scaled - start)
	     ----------------
 		   (end - start)
	*/
	
}

String NumberFilterProperty::getText() 
{ 
	return String(getValueInScaledRange(), 2) + T(" ") + unit; 
}

