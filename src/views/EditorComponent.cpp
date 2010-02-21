/*
 *  EditorComponent.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/5/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "FilterNib.h"
#include "FilterParameterManager.h"
#include "EditorComponent.h"
#include "SynthComponent.h"
#include "NewLookAndFeel.h"
#include "Filter.h"

EditorComponent::EditorComponent(Filter* const ownerFilter) 
	: AudioProcessorEditor(ownerFilter) 
{
	filterNib = ownerFilter->getFilterNib();
	filterParameterManager = filterNib->getFilterParameterManager();

	LookAndFeel::setDefaultLookAndFeel( NewLookAndFeel::getInstance() );

	addAndMakeVisible(synthComponent = new SynthComponent(filterNib));

	int minWidth = 800;
	int minHeight = 400;
	resizeLimits.setSizeLimits(minWidth, minHeight, 1200, 800);		
	addAndMakeVisible(resizer = new ResizableCornerComponent(this, &resizeLimits));
	
	float width = filterParameterManager->getLastUIWidth();
	float height = filterParameterManager->getLastUIHeight();
	if (width < minWidth) width = minWidth;
	if (height < minHeight) height = minHeight;
	setSize(width, height);
}

EditorComponent::~EditorComponent() {
	deleteAndZero(resizer);
	deleteAndZero(synthComponent);
	deleteAllChildren();
}

void EditorComponent::paint(Graphics& g) {
	Colour baseColour;
	Colour highlightColour;
	Colour shadowColour;
	Colour outlineColour;
	bool isActive = true; // force active for now (vst doesn't respond well)
	outlineColour = Colour::fromRGBA(255, 255, 255, 50);
	if (isActive) {
		shadowColour = Colour::fromRGB(142, 142, 142);
		baseColour = Colour::fromRGB(165, 165, 165);
		highlightColour = Colour::fromRGB(206, 206, 206);
	} else {
		shadowColour = Colour::fromRGB(200, 200, 200);
		baseColour = Colour::fromRGB(215, 215, 215);
		highlightColour = Colour::fromRGB(236, 236, 236);
	}
	g.fillAll(baseColour);
	ColourGradient highlightGradient = ColourGradient(highlightColour, 0, 0,
													  Colours::transparentWhite, 0, 20, false);
	g.setGradientFill(highlightGradient);
	g.fillRect(0, 0, getWidth(), getHeight());
	ColourGradient shadowGradient = ColourGradient(shadowColour, 0, getHeight(),
												  Colours::transparentWhite, 0, getHeight() - 10, false);
	g.setGradientFill(shadowGradient);
	g.fillRect(0, 0, getWidth(), getHeight());
	g.setColour(outlineColour);
	g.drawRect(0, 1, getWidth(), getHeight() - 1, 1.0);
}

void EditorComponent::resized() {
	synthComponent->setBounds(1, 1, getWidth(), getHeight());
	resizer->setBounds(getWidth() - 16, getHeight() - 16, 16, 16);
	filterParameterManager->setLastUIWidth( getWidth() );
	filterParameterManager->setLastUIHeight( getHeight() );
}


