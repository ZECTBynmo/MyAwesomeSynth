/*
 *  SoundBank.cpp
 *  NetSynth
 *
 *  Created by Matt Sonic on 12/25/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "SoundBank.h"

SoundBank::SoundBank() {
}

SoundBank::~SoundBank() {
}

void SoundBank::addSound(const Sound* newSound) {
	sounds.add(newSound);
}

void SoundBank::removeSound(const int index) {
	sounds.remove(index);
}