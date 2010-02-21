/*
 *  DemoFilter.cpp
 *  juceplugin3
 *
 *  Created by Matt Sonic on 12/4/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "includes.h"
#include "DemoFilter.h"
#include "DemoEditorComponent.h"

// special callback
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
	return new DemoFilter();
}

DemoFilter::DemoFilter() {
	gain = 1.0f;
}

DemoFilter::~DemoFilter() { }

const String DemoFilter::getName() const {
	return T("My Demo Filter");
}

void DemoFilter::prepareToPlay(double sampleRate, 
							   int estimatedSamplesPerBlock) { }

void DemoFilter::releaseResources() { }

void DemoFilter::processBlock(AudioSampleBuffer& buffer,
							  MidiBuffer& midiMessages) {
	for (int channel = 0; channel < getNumInputChannels(); channel++) {
		buffer.applyGain(channel, 0, buffer.getNumSamples(), gain);
	}
	for (int i = getNumInputChannels(); i < getNumOutputChannels(); i++) {
		buffer.clear(i, 0, buffer.getNumSamples());
	}
}

const String DemoFilter::getInputChannelName(const int channelIndex) const {
	return String(channelIndex + 1);
}

const String DemoFilter::getOutputChannelName(const int channelIndex) const {
	return String(channelIndex + 1);
}

bool DemoFilter::isInputChannelStereoPair(int index) const { return false; }

bool DemoFilter::isOutputChannelStereoPair(int index) const { return false; }

bool DemoFilter::acceptsMidi() const { return true; }

bool DemoFilter::producesMidi() const { return true; }

AudioProcessorEditor* DemoFilter::createEditor() {
	return new DemoEditorComponent(this);
}

int DemoFilter::getNumParameters() { return 1; }

const String DemoFilter::getParameterName(int parameterIndex) {
	if (parameterIndex == 0) return T("gain");
	return String::empty;
}

float DemoFilter::getParameter(int parameterIndex) {
	return (parameterIndex == 0) ? gain : 0.0f;
}

const String DemoFilter::getParameterText(int parameterIndex) {
	if (parameterIndex == 0) return String(gain, 2);
	return String::empty;
}

void DemoFilter::setParameter(int parameterIndex, float newValue) {
	if (parameterIndex == 0) {
		if (gain != newValue) {
			gain = newValue;
			sendChangeMessage(this);
		}
	}
}

void DemoFilter::getStateInformation(MemoryBlock& destData) {
	XmlElement xmlState(T("MYPLUGINSETTINGS"));
	xmlState.setAttribute(T("pluginVersion"), 1);
	xmlState.setAttribute(T("gainLevel"), gain);
	copyXmlToBinary(xmlState, destData);
}

void DemoFilter::setStateInformation(const void* data, int sizeInBytes) {
	XmlElement* const xmlState = getXmlFromBinary(data, sizeInBytes);
	if (xmlState != 0) {
		if (xmlState->hasTagName(T("MYPLUGINSETTINGS"))) {
			gain = (float) xmlState->getDoubleAttribute(T("gainLevel"), gain);
			sendChangeMessage(this);
		}
		delete xmlState;
	}
}