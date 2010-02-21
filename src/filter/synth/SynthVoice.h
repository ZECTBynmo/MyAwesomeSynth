/*
 *  SynthVoice.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 1/3/10.
 *  Copyright 2010 SonicTransfer. All rights reserved.
 *
 */

#ifndef SYNTH_VOICE_H
#define SYNTH_VOICE_H

#include "includes.h"

class FilterNib;
class FilterManager;

class SynthVoice : public SynthesiserVoice
{
public:
	SynthVoice(FilterNib* filterNib_);
	~SynthVoice();
	// SynthesiserVoice methods
	bool canPlaySound (SynthesiserSound* sound);
	void startNote (const int midiNoteNumber,
					const float velocity,
					SynthesiserSound* sound,
					const int currentPitchWheelPosition);
	void stopNote (const bool allowTailOff);
	void pitchWheelMoved (const int newValue);
	void controllerMoved (const int controllerNumber,
						  const int newValue);
	void renderNextBlock (AudioSampleBuffer& outputBuffer,
						  int startSample,
						  int numSamples);
	
	juce_UseDebuggingNewOperator
private:
	FilterNib* filterNib;
	FilterManager* filterManager;
	
	double level;
	double tailOff;
	double phase;
	double phaseIncr;	
};

#endif