#include "AnimationBase.h"
#include <iostream>

using std::cout;
using std::endl;

AnimationBase::AnimationBase(sf::RectangleShape &sprite, float fps)
	: sprite(sprite),fps(fps), currentFrame(0), timePerFrame(1.f/fps), numFrames(0)
{
}

int AnimationBase::getCurrentFrame()
{
	return this->currentFrame;
}

const sf::IntRect & AnimationBase::getUVRect()
{
	return this->uvRect;
}

sf::Texture AnimationBase::loadFromFile(std::string file)
{
	sf::Texture tex;
	tex.loadFromFile(file);

	return tex;
}

void AnimationBase::update(float deltaTime)
{
	timeOnFrame += deltaTime;

	cout << deltaTime << endl;

	//if it is time to switch frames
	if (timeOnFrame >= timePerFrame)
	{
		//go to the next frame
		nextFrame();
	}
}

void AnimationBase::restart()
{
	this->setFrame(0);
}

void AnimationBase::setFrame(int frame)
{
	this->currentFrame = frame;
	this->timeOnFrame = 0;
}

void AnimationBase::nextFrame()
{
	setFrame((currentFrame + 1) % numFrames);
}