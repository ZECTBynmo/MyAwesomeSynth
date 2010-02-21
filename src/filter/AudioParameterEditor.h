/*
 *  AudioParameterEditor.h
 *  NetSynth
 *
 *  Created by Matt Sonic on 12/22/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#ifndef AUDIO_PARAMETER_EDITOR_H
#define AUDIO_PARAMETER_EDITOR_H

class FilterParameterManager;

// All components that read / write filter parameters should inherit from this
//    -gives access to easy wrapper for grabbing parameter manager
class AudioParameterEditor {
public:
	FilterParameterManager* getFilterParameterManager() const throw(); 
};

#endif