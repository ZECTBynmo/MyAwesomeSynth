/*
 *  SynthAudioSource.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/24/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "FilterNib.h"
#include "FilterParameterManager.h"
#include "SynthAudioSource.h"
#include "SynthSound.h"
#include "SynthVoice.h"

#define kNumVoices 8

SynthAudioSource::SynthAudioSource (FilterNib* filterNib_,
									MidiKeyboardState& keyboardState_)
: filterNib (filterNib_),
keyboardState (keyboardState_)
{
	filterParameterManager = filterNib->getFilterParameterManager();
		
    BitArray synthNotes;
	
    for (int i = 0; i < 128; ++i) {
        synthNotes.setBit (i);
	}
	
    synth.addSound (new SynthSound (filterNib, synthNotes));
	
	for (int i = kNumVoices; --i >= 0;) {
		synth.addVoice ( new SynthVoice(filterNib) );
	}
}

SynthAudioSource::~SynthAudioSource() 
{
}

void SynthAudioSource::prepareToPlay (int samplesPerBlockExpected,
									  double sampleRate) {
    keyboardState.reset();
	midiCollector.reset(sampleRate);
	synth.setCurrentPlaybackSampleRate(sampleRate);
}

void SynthAudioSource::releaseResources() {
}

void SynthAudioSource::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) {
	bufferToFill.clearActiveBufferRegion();
	midiCollector.removeNextBlockOfMessages(*midiBuffer, bufferToFill.numSamples);
	keyboardState.processNextMidiBuffer(*midiBuffer, 0, bufferToFill.numSamples, true);
	synth.renderNextBlock(*bufferToFill.buffer, *midiBuffer, 0, bufferToFill.numSamples);
}

void SynthAudioSource::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages) {
	// implemented to mirror AudioProcessor
	midiBuffer = &midiMessages;

	AudioSourceChannelInfo bufferToFill;
	bufferToFill.buffer = &buffer;
	bufferToFill.startSample = 0;
	bufferToFill.numSamples = buffer.getNumSamples();
	getNextAudioBlock(bufferToFill);
}
