#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Animation
{
public:
	Animation(std::string filePath, float fps,int numFrames, sf::Vector2i rowsByCols);

public:
	sf::IntRect getUVRect();

	const sf::Texture* getTexture();

	void update(float deltaTime);

private:
	/////////////////////////
	// Sets the UV coords to the next frame in the animation
	/////////////////////////
	void nextFrame();

	/////////////////////////
	// Restarts the animation
	/////////////////////////
	void restart();

private:
	////////////////////////
	// My main texture//////
	////////////////////////
	sf::Texture texture;

	////////////////////////
	// Rect representing the coords of my current frame
	///////////////////////
	sf::IntRect uvRect;

	///////////////////////
	// The coordinates  on the sprite sheet where this animation starts
	///////////////////////
	sf::Vector2i origin;

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

	///////////////////////
	// the current frame I'm on out of the total number of frames
	//////////////////////
	int currentFrame = 0;

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

