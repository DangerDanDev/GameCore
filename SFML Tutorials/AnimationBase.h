#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

//////////////////////
// Animation set base class
// used as a parent for both sprite sheet animations
// and multi image file animation sets
//////////////////////
class AnimationBase
{
public:
	AnimationBase(sf::RectangleShape &sprite, float fps);

public:
	////////////////////////////
	// Restarts the animation
	////////////////////////////
	void restart();

	////////////////////////////
	// Computes how long we have been
	// on the current frame and determines
	// if it is yet time to move to the next frame
	///////////////////////////
	virtual void update(float deltaTime);

	///////////////////////////
	// Instructs the animation set to display a specific frame
	//////////////////////////
	virtual void setFrame(int frame) = 0;

	////////////////////////////
	// Goes to the next frame in the animation
	////////////////////////////
	void nextFrame();

	/////////////////////////
	// Gets the frame number that this animation set is on
	/////////////////////////
	int getCurrentFrame();

	////////////////////////////////
	// Gets an immutable reference to my uv coordinates
	////////////////////////////////
	const sf::IntRect& getUVRect();

protected:

	////////////////////////////
	// The entity who is using this animation set
	////////////////////////////
	sf::RectangleShape& sprite;

	////////////////////////
	// Rect representing the UV coords of my current frame
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

	///////////////////////
	// the current frame I'm on out of the total number of frames
	//////////////////////
	int currentFrame;

	////////////////////////
	// The amount of time to spend on each frame
	///////////////////////
	float timePerFrame;

	///////////////////////
	// The time that has been spent thus far on the current frame
	///////////////////////
	float timeOnFrame = 0;
};

