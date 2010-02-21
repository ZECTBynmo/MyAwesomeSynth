/*
 *  AudioParameterEditor
 *  NetSynth
 *
 *  Created by Matt Sonic on 12/22/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "AudioParameterEditor.h"
#include "FilterParameterManager.h"

FilterParameterManager* AudioParameterEditor::getFilterParameterManager() const throw() 
{ 
	return (FilterParameterManager*) FilterParameterManager::getInstance(); 
}


