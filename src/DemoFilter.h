/*
 *  DemoFilter.h
 *  juceplugin3
 *
 *  Created by Matt Sonic on 12/4/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */
#ifndef DEMO_FILTER_H
#define DEMO_FILTER_H

class DemoFilter : public AudioProcessor, 
				   public ChangeBroadcaster 
{
public:
	DemoFilter();
	~DemoFilter();
	const String getName() const;
	void prepareToPlay(double sampleRate, int estimatedSamplesPerBlock);
	void releaseResources();
	void processBlock(AudioSampleBuffer& buffer,
					  MidiBuffer& midiMessages);
	const String getInputChannelName(const int channelIndex) const;
	const String getOutputChannelName(const int channelIndex) const;
	bool isInputChannelStereoPair(int index) const;
	bool isOutputChannelStereoPair(int index) const;
	bool acceptsMidi() const;
	bool producesMidi() const;
	AudioProcessorEditor* createEditor();
	int getNumParameters();
	const String getParameterName(int parameterIndex);
	float getParameter(int parameterIndex);
	const String getParameterText(int parameterIndex);
	void setParameter(int parameterIndex, float newValue);
	int getNumPrograms() { return 0; }
	int getCurrentProgram() { return 0; }
	void setCurrentProgram(int index) { }
	const String getProgramName(int index) { return String::empty; }
	void changeProgramName(int index, const String& newName) { }
	void getStateInformation(MemoryBlock& destData);
	void setStateInformation(const void* data, int sizeInBytes);
	
	juce_UseDebuggingNewOperator
private:
	float gain;
};

#endif
