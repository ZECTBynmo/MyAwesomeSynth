/*
 *  FilterNib.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/4/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#include "FilterParameterManager.h"
#include "FilterManager.h"
#include "FilterNib.h"

#define ns_DeclareManager(classname, instancename, methodname) \
\
classname* FilterNib::methodname() \
{ \
   if (instancename == NULL) { \
       instancename = new classname(this); \
   } \
   return instancename; \
} \

FilterNib::FilterNib()
{
	filterParameterManager = NULL;
	filterManager = NULL;
}

FilterNib::~FilterNib()
{
	delete filterParameterManager;
	delete filterManager;
}

ns_DeclareManager(FilterParameterManager, filterParameterManager, getFilterParameterManager)
ns_DeclareManager(FilterManager, filterManager, getFilterManager)


