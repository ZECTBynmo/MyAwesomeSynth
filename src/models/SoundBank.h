/*
 *  SoundBank.h
 *  NetSynth
 *
 *  Created by Matt Sonic on 12/25/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#ifndef SOUND_BANK_H
#define SOUND_BANK_H

#include "Sound.h"
#include "includes.h"

class SoundBank {
public:
	SoundBank();
	~SoundBank();
	int getNumSounds() const throw() { return sounds.size(); }
	Sound* getSound(const int index) const throw() { return sounds[index]; }
	void addSound(const Sound* newSound);
	void removeSound(const int index);
	
	template <class ElementComparator>
	void sortSounds (ElementComparator& comparator) const throw() {
		sounds.sort(comparator);
	}
	
	juce_UseDebuggingNewOperator
	
	OwnedArray<Sound> sounds; // manages all sound references
};

#endif