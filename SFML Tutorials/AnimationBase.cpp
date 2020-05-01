#include "AnimationBase.h"

AnimationBase::AnimationBase(float fps)
	: fps(fps), currentFrame(0), timePerFrame(0), numFrames(0)
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

void AnimationBase::update(float deltaTime)
{
	timeOnFrame += deltaTime;

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

void AnimationBase::nextFrame()
{
	setFrame((currentFrame + 1) % numFrames);
}