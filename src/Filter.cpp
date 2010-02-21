/*
 *  Filter.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/4/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "FilterNib.h"
#include "FilterParameterManager.h"
#include "FilterManager.h"
#include "Filter.h"
#include "FilterProperty.h"
#include "FilterSetting.h"
#include "EditorComponent.h"
#include "SynthAudioSource.h"

// special callback
AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
	return new Filter();
}

FilterNib* Filter::getFilterNib() 
{
	return filterNib;
}

Filter::Filter() { 
	filterNib = new FilterNib();
	filterManager = filterNib->getFilterManager();
	filterParameterManager = filterNib->getFilterParameterManager();
	
	filterManager->setFilter(this);
	filterParameterManager->setFilter(this);

	synthAudioSource = new SynthAudioSource(filterNib, keyboardState);
	
    zeromem (&lastPosInfo, sizeof (lastPosInfo));
    lastPosInfo.timeSigNumerator = 4;
    lastPosInfo.timeSigDenominator = 4;
    lastPosInfo.bpm = 120;
	
	setLatencySamples(6000); // control plugin latency
}

Filter::~Filter() { 
	delete synthAudioSource;
	delete filterNib;
}

const String Filter::getName() const {
	return T("My Demo Filter");
}

void Filter::prepareToPlay(double sampleRate, 
						   int estimatedSamplesPerBlock) { 
	synthAudioSource->prepareToPlay(estimatedSamplesPerBlock, sampleRate);
}

void Filter::releaseResources() { 
	synthAudioSource->releaseResources();
}

void Filter::processBlock(AudioSampleBuffer& buffer,
							  MidiBuffer& midiMessages) 
{
	keyboardState.processNextMidiBuffer(midiMessages, 0, 
										buffer.getNumSamples(), true);
    
	synthAudioSource->processBlock(buffer, midiMessages);
	
	float gain = filterParameterManager->getGain();
	for (int channel = 0; channel < getNumInputChannels(); channel++) {
		buffer.applyGain(channel, 0, buffer.getNumSamples(), gain );
	}
	
	// clear any excess channels
	for (int i = getNumInputChannels(); i < getNumOutputChannels(); i++) {
		buffer.clear(i, 0, buffer.getNumSamples());
	}

}

const String Filter::getInputChannelName(const int channelIndex) const {
	return String(channelIndex + 1);
}

const String Filter::getOutputChannelName(const int channelIndex) const {
	return String(channelIndex + 1);
}

bool Filter::isInputChannelStereoPair(int index) const { return false; }

bool Filter::isOutputChannelStereoPair(int index) const { return false; }

bool Filter::acceptsMidi() const { return true; }

bool Filter::producesMidi() const { return true; }

AudioProcessorEditor* Filter::createEditor() {
	return new EditorComponent(this);
}

int Filter::getNumParameters() { 
	return filterParameterManager->getNumProperties(); 
}

const String Filter::getParameterName(int parameterIndex) {
	FilterProperty* fp = filterParameterManager->getPropertyWithIndex(parameterIndex);
	return fp->getName();
}

float Filter::getParameter(int parameterIndex) {
	FilterProperty* fp = filterParameterManager->getPropertyWithIndex(parameterIndex);
	return fp->getValue();
}

const String Filter::getParameterText(int parameterIndex) {
	FilterProperty* fp = filterParameterManager->getPropertyWithIndex(parameterIndex);
	return fp->getText();
}

void Filter::setParameter(int parameterIndex, float newValue) {
	FilterProperty* fp = filterParameterManager->getPropertyWithIndex(parameterIndex);
	float oldValue = fp->getValue();
	if (oldValue != newValue) {
		fp->setValue(newValue);
		sendChangeMessage(this);
	}
}

void Filter::getStateInformation(MemoryBlock& destData) {
	// Record settings
	XmlElement xmlState(T("MYPLUGINSETTINGS"));
	xmlState.setAttribute(T("pluginVersion"), 1);
	FilterProperty* p;
	for (int i = 0; i < filterParameterManager->getNumProperties(); ++i) {
		p = filterParameterManager->getPropertyWithIndex(i);
		xmlState.setAttribute(p->getXMLName(), p->getValue());
	}
	FilterSetting* s;
	for (int i = 0; i < filterParameterManager->getNumSettings(); ++i) {
		s = filterParameterManager->getSettingWithIndex(i);
		xmlState.setAttribute(s->getXMLName(), s->getValue());
	}
	copyXmlToBinary(xmlState, destData);
}

void Filter::setStateInformation(const void* data, int sizeInBytes) {
	// Read settings
	XmlElement* const xmlState = getXmlFromBinary(data, sizeInBytes);
	if (xmlState != 0) {
		if (xmlState->hasTagName(T("MYPLUGINSETTINGS"))) {
			FilterProperty* p;
			for (int i = 0; i < filterParameterManager->getNumProperties(); ++i) {
				p = filterParameterManager->getPropertyWithIndex(i);
				p->setValue( (float) xmlState->getDoubleAttribute( p->getXMLName(), p->getValue() ) );
			}
				
			FilterSetting* s;
			for (int i = 0; i < filterParameterManager->getNumSettings(); ++i) {
				s = filterParameterManager->getSettingWithIndex(i);
				s->setValue( (float) xmlState->getDoubleAttribute( s->getXMLName(), s->getValue() ) );
			}
			sendChangeMessage(this);
		}
		delete xmlState;
	}
}

