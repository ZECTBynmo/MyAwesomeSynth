/*
 *  NewLookAndFeel.h
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/7/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#ifndef NEW_LOOK_AND_FEEL_H
#define NEW_LOOK_AND_FEEL_H

#include "includes.h"

class NewLookAndFeel : public LookAndFeel,
					   public DeletedAtShutdown 
{
public:
	NewLookAndFeel();
	~NewLookAndFeel();
	void fillResizableWindowBackground (Graphics& g, int /*w*/, int /*h*/,
										const BorderSize& /*border*/, 
										ResizableWindow& window);
	void drawGlassLozenge (Graphics& g,
							const float x, const float y,
							const float width, const float height,
							const Colour& colour,
							const float outlineThickness,
							const float cornerSize,
							const bool flatOnLeft,
							const bool flatOnRight,
							const bool flatOnTop,
						    const bool flatOnBottom,
						    const bool isMouseOverButton,
						    const bool isButtonDown) throw();
	void drawButtonBackground (Graphics& g,
							   Button& button,
							   const Colour& backgroundColour,
							   bool isMouseOverButton,
							   bool isButtonDown);

	juce_DeclareSingleton (NewLookAndFeel, false)
};

#endif