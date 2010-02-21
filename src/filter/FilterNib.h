/*
 *  FilterNib.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/4/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#ifndef FILTER_NIB_H
#define FILTER_NIB_H

//------------------------------------------------------------------------------
// CLASS: FilterNib
// PURPOSE: Hold references to all managers
//------------------------------------------------------------------------------

#include "includes.h"

class FilterParameterManager;
class FilterManager;

class FilterNib 
{
public:
	FilterNib();
	~FilterNib();
	FilterParameterManager* getFilterParameterManager();
	FilterManager* getFilterManager();
private:
	FilterParameterManager* filterParameterManager;
	FilterManager* filterManager;
};

#endif