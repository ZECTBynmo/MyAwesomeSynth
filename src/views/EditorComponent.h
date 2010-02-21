/*
 *  EditorComponent.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/5/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */
#ifndef EDITOR_COMPONENT_H
#define EDITOR_COMPONENT_H

#include "includes.h"

class NewLookAndFeel;
class Filter;
class FilterParameterManager;
class FilterNib;
class SynthComponent;

class EditorComponent : public AudioProcessorEditor
{
public:
	EditorComponent(Filter* const ownerFilter);
	~EditorComponent();
	void paint(Graphics& g);
	void resized();
private:
	SynthComponent* synthComponent;						
	ResizableCornerComponent* resizer;
	ComponentBoundsConstrainer resizeLimits;
    
	FilterNib* filterNib;
	FilterParameterManager* filterParameterManager;
	Filter* getFilter() const throw() { return (Filter*) getAudioProcessor(); }
};
#endif
