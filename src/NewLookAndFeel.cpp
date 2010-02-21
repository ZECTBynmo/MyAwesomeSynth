/*
 *  NewLookAndFeel.cpp
 *  MyAwesomeSynth
 *
 *  Created by Matt Sonic on 12/7/09.
 *  Copyright 2009 SonicTransfer. All rights reserved.
 *
 */

#include "NewLookAndFeel.h"

juce_ImplementSingleton (NewLookAndFeel)

static void createRoundedPath (Path& p,
                               const float x, const float y,
                               const float w, const float h,
                               const float cs,
                               const bool curveTopLeft, const bool curveTopRight,
                               const bool curveBottomLeft, const bool curveBottomRight) throw()
{
    const float cs2 = 2.0f * cs;
	
    if (curveTopLeft)
    {
        p.startNewSubPath (x, y + cs);
        p.addArc (x, y, cs2, cs2, float_Pi * 1.5f, float_Pi * 2.0f);
    }
    else
    {
        p.startNewSubPath (x, y);
    }
	
    if (curveTopRight)
    {
        p.lineTo (x + w - cs, y);
        p.addArc (x + w - cs2, y, cs2, cs2, 0.0f, float_Pi * 0.5f);
    }
    else
    {
        p.lineTo (x + w, y);
    }
	
    if (curveBottomRight)
    {
        p.lineTo (x + w, y + h - cs);
        p.addArc (x + w - cs2, y + h - cs2, cs2, cs2, float_Pi * 0.5f, float_Pi);
    }
    else
    {
        p.lineTo (x + w, y + h);
    }
	
    if (curveBottomLeft)
    {
        p.lineTo (x + cs, y + h);
        p.addArc (x, y + h - cs2, cs2, cs2, float_Pi, float_Pi * 1.5f);
    }
    else
    {
        p.lineTo (x, y + h);
    }
	
    p.closeSubPath();
}

static const Colour createBaseColour (const Colour& buttonColour,
                                      const bool hasKeyboardFocus,
                                      const bool isMouseOverButton,
                                      const bool isButtonDown) throw()
{
    const float sat = hasKeyboardFocus ? 1.3f : 0.9f;
    const Colour baseColour (buttonColour.withMultipliedSaturation (sat));
	
    if (isButtonDown)
        return baseColour.contrasting (0.1f);
    //else if (isMouseOverButton)
    //    return baseColour.contrasting (0.1f);
	
    return baseColour;
}

NewLookAndFeel::NewLookAndFeel() {
	NewLookAndFeel::setColour(TextButton::buttonColourId, Colour::fromRGB(220, 220, 220));
}

NewLookAndFeel::~NewLookAndFeel() {
}

void NewLookAndFeel::fillResizableWindowBackground (Graphics& g, int /*w*/, int /*h*/,
													const BorderSize& /*border*/, 
													ResizableWindow& window)
{
	g.fillAll (window.getBackgroundColour());
}

void NewLookAndFeel::drawGlassLozenge (Graphics& g,
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
									   const bool isButtonDown) throw()
{
    if (width <= outlineThickness || height <= outlineThickness)
        return;
	
    const float cs = cornerSize < 0 ? jmin (width * 0.5f, height * 0.5f) : cornerSize;
	
    Path outline;
    createRoundedPath (outline, x, y, width, height, cs,
					   ! (flatOnLeft || flatOnTop),
					   ! (flatOnRight || flatOnTop),
					   ! (flatOnLeft || flatOnBottom),
					   ! (flatOnRight || flatOnBottom));

    {
		ColourGradient cg;
		if (isButtonDown) {
			cg  = ColourGradient(colour, 0, y,
				 			     colour.darker (0.1f), 0, y + height, false);
		} else { 
			cg  = ColourGradient(colour.darker(0.1f), 0, y,
							     colour, 0, y + height, false);
		}

		
        g.setGradientFill (cg);
        g.fillPath (outline);
    }
 
    {
        const float leftIndent = flatOnLeft ? 0.0f : cs * 0.4f;
        const float rightIndent = flatOnRight ? 0.0f : cs * 0.4f;
		
        Path highlight;
        createRoundedPath (highlight,
                           x + leftIndent,
                           y + cs * 0.1f,
                           width - (leftIndent + rightIndent),
                           height * 0.2f, cs * 0.2f,
                           ! (flatOnLeft || flatOnTop),
                           ! (flatOnRight || flatOnTop),
                           ! (flatOnLeft || flatOnBottom),
                           ! (flatOnRight || flatOnBottom));
		
		if (!isButtonDown) {
			g.setGradientFill (ColourGradient (colour.brighter (2.0f), 0, y + height * 0.06f,
											   Colours::transparentWhite, 0, y + height * 0.2f, false));
		} else {
			g.setGradientFill (ColourGradient (colour.darker (0.3f), 0, y + height * 0.06f,
											   Colours::transparentBlack, 0, y + height * 0.2f, false));
		}
		g.fillPath (highlight);
    }
	
    {
        const float leftIndent = flatOnLeft ? 0.0f : cs * 0.4f;
        const float rightIndent = flatOnRight ? 0.0f : cs * 0.4f;
		
        Path shadow;
        createRoundedPath (shadow,
                           x + leftIndent,
                           y + height * 0.85f + cs * 0.1f,
                           width - (leftIndent + rightIndent),
                           height * 0.2f, cs * 0.2f,
                           ! (flatOnLeft || flatOnTop),
                           ! (flatOnRight || flatOnTop),
                           ! (flatOnLeft || flatOnBottom),
                           ! (flatOnRight || flatOnBottom));
		
		if (!isButtonDown) {
			g.setGradientFill (ColourGradient (Colours::transparentWhite, 0, y + height * 0.85f,
											   colour.darker (0.4f), 0, y + height, false));
		} 
		g.fillPath (shadow);
    }
    
	g.setColour(Colour::fromRGBA(0, 0, 0, 150));
    g.strokePath (outline, PathStrokeType (outlineThickness));
}

void NewLookAndFeel::drawButtonBackground (Graphics& g,
										   Button& button,
										   const Colour& backgroundColour,
										   bool isMouseOverButton,
										   bool isButtonDown)
{
    const int width = button.getWidth();
    const int height = button.getHeight();
	
    //const float outlineThickness = button.isEnabled() ? ((isButtonDown || isMouseOverButton) ? 1.2f : 0.7f) : 0.4f;
	const float outlineThickness = 0.7f;
    const float halfThickness = outlineThickness * 0.5f;
	
    const float indentL = button.isConnectedOnLeft()   ? 0.1f : halfThickness;
    const float indentR = button.isConnectedOnRight()  ? 0.1f : halfThickness;
    const float indentT = button.isConnectedOnTop()    ? 0.1f : halfThickness;
    const float indentB = button.isConnectedOnBottom() ? 0.1f : halfThickness;
	
    const Colour baseColour (createBaseColour (backgroundColour,
                                               button.hasKeyboardFocus (true),
                                               isMouseOverButton, isButtonDown)
							 .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f));
	
	drawGlassLozenge (g,
                      indentL,
                      indentT,
                      width - indentL - indentR,
                      height - indentT - indentB,
                      baseColour,
					  outlineThickness, 
					  6.0f,
                      button.isConnectedOnLeft(),
                      button.isConnectedOnRight(),
                      button.isConnectedOnTop(),
                      button.isConnectedOnBottom(),
					  isMouseOverButton,
					  isButtonDown);
}
