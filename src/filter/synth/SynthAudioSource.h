/*
 *  SynthAudioSource.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/24/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#ifndef SYNTH_AUDIO_SOURCE_H
#define SYNTH_AUDIO_SOURCE_H

#include "includes.h"

class FilterNib;
class FilterParameterManager;

class SynthAudioSource : public AudioSource
{
public:
	SynthAudioSource (FilterNib* filterNib_, 
					  MidiKeyboardState& keyboardState_);
	~SynthAudioSource();
	void prepareToPlay (int samplesPerBlockExpected,
						double sampleRate);
	void releaseResources();
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill);
	void processBlock(AudioSampleBuffer& buffer,
					  MidiBuffer& midiMessages); // implemented to mirror AudioProcessor
private:
	FilterNib* filterNib;
	FilterParameterManager* filterParameterManager;
	
	MidiMessageCollector midiCollector;
	MidiKeyboardState& keyboardState;
	MidiBuffer* midiBuffer;
	Synthesiser synth;
};

#endif