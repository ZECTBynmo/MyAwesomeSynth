/*
 *  SynthVoice.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/3/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#include "FilterNib.h"
#include "FilterManager.h"
#include "SynthSound.h"
#include "SynthVoice.h"

const double PI = double_Pi;
const double twoPI = double_Pi*2;

SynthVoice::SynthVoice(FilterNib* filterNib_)
: filterNib (filterNib_),
tailOff (0.0),
phase(0.0),
phaseIncr(0.0)
{
	filterManager = filterNib->getFilterManager();
}

SynthVoice::~SynthVoice()
{
}

bool SynthVoice::canPlaySound (SynthesiserSound* sound)
{
	return dynamic_cast <const SynthSound*> (sound) != 0;
}

void SynthVoice::startNote (const int midiNoteNumber,
						   const float velocity,
						   SynthesiserSound* sound_,
						   const int currentPitchWheelPosition)
{
	level = velocity * 0.15;
	tailOff = 0.0;
	
	double frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber); 
	double frqRad = twoPI / getSampleRate(); // refactor this
	phaseIncr = frequency * frqRad;
	phase = 0;
}

void SynthVoice::stopNote (const bool allowTailOff)
{
	clearCurrentNote();
	phaseIncr = 0.0;
}

void SynthVoice::pitchWheelMoved (const int newValue)
{
}

void SynthVoice::controllerMoved (const int controllerNumber,
								 const int newValue)
{
}

void SynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer,
								 int startSample,
								 int numSamples)
{
	if (phaseIncr != 0.0)
	{
		while (--numSamples >= 0)
		{
			float currentSample = (float) level * sin(phase);
			for (int i = outputBuffer.getNumChannels(); --i >= 0;) {
				*outputBuffer.getSampleData (i, startSample) += currentSample;
			}
			phase += phaseIncr;
			if (phase >= twoPI) phase -= twoPI;
			++startSample;
		}
	}
}