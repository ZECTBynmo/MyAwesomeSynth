/*
 *  SynthSound.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/3/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#ifndef SYNTH_SOUND_H
#define SYNTH_SOUND_H

#include "includes.h"

class FilterNib;

class SynthSound : public SynthesiserSound 
{
public:
	SynthSound (FilterNib* filterNib_,
				const BitArray& midiNotes);	
	~SynthSound();
		
	bool appliesToNote (const int midiNoteNumber);
	bool appliesToChannel (const int midiChannel);
	
	juce_UseDebuggingNewOperator
private:	
	friend class SynthVoice;
	
	FilterNib* filterNib;
	BitArray midiNotes;
};

#endif
