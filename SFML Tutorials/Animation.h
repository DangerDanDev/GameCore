#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Animation
{
public:
	Animation(std::string filePath, float fps, int rows, int cols, bool lastFrameEmpty = false);

public:
	sf::IntRect getUVRect();

	const sf::Texture* getTexture();

	void update(float deltaTime);

private:
	/////////////////////////
	// Sets the UV coords to the next frame in the animation
	/////////////////////////
	void nextFrame();

private:
	////////////////////////
	// My main texture//////
	////////////////////////
	sf::Texture texture;

	////////////////////////
	// Rect representing the coords of my current frame
	///////////////////////
	sf::IntRect uvRect;

	////////////////////////
	// The width and height of each frame
	////////////////////////
	sf::Vector2i frameSize;

	/////////////////////////
	// Frames per second this animation should display at
	////////////////////////
	float fps;

	////////////////////////
	// Number of animations in the frame
	////////////////////////
	int numFrames;

	////////////////////////
	// The number of rows in this animation's sprite sheet
	///////////////////////
	int rows;

	///////////////////////
	// Number of columns in this animations sprite sheet
	///////////////////////
	int cols;

	////////////////////////
	// The amount of time to spend on each frame
	///////////////////////
	float timePerFrame;

	///////////////////////
	// The time that has been spent thus far on the current frame
	///////////////////////
	float timeOnFrame;
};

