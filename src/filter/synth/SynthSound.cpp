/*
 *  SynthSound.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/3/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#include "FilterNib.h"
#include "SynthSound.h"

SynthSound::SynthSound (FilterNib* filterNib_,
					  const BitArray& midiNotes_)
: filterNib (filterNib_), 
midiNotes (midiNotes_)
{
}

SynthSound::~SynthSound() 
{
}

bool SynthSound::appliesToNote (const int midiNoteNumber)
{
	return midiNotes [midiNoteNumber];
}

bool SynthSound::appliesToChannel (const int midiChannel)
{
	return true;
}
