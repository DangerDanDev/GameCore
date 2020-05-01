#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "AnimationBase.h"

///////////////////////
// Base class for the different AnimationSet classes
///////////////////////
class Animation : public AnimationBase
{
public:
	Animation(sf::RectangleShape &sprite, std::string filePath, 
		float fps,int numFrames, sf::Vector2i rowsByCols);

public:

	////////////////////////////////
	// The sprite sheet used for this animation
	////////////////////////////////
	const sf::Texture* getTexture();

	////////////////////////////////
	// 
	////////////////////////////////
	const sf::Vector2i getFrameSize();

	virtual void setFrame(int frame) override;

private:
	////////////////////////
	// My main texture//////
	////////////////////////
	sf::Texture texture;

	///////////////////////
	// The coordinates  on the sprite sheet where this animation starts
	///////////////////////
	sf::Vector2i origin;

	////////////////////////
	// The number of rows in this animation's sprite sheet
	///////////////////////
	int rows;

	///////////////////////
	// Number of columns in this animations sprite sheet
	///////////////////////
	int cols;
};

