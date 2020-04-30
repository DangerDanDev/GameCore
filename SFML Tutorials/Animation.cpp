#include "Animation.h"

using std::cout;
using std::endl;

Animation::Animation(std::string filePath, float fps, int numFrames, sf::Vector2i rowsByCols)
{

	this->texture.loadFromFile(filePath);
	
	this->fps = fps;
	this->timePerFrame = 1.f / fps;

	//the number of frames is equal to the number of rows * columns
	this->rows = rowsByCols.x;
	this->cols = rowsByCols.y;
	this->numFrames = numFrames;

	//figure out the size of each frame; it is equal to
	//the number width of the texture divided by the number of columns
	int frameWidth = this->texture.getSize().x / this->cols;
	//times the height of the texture divided by the number of rows
	int frameHeight = this->texture.getSize().y / this->rows;

	//this is my frame size now
	this->frameSize = sf::Vector2i(frameWidth, frameHeight);

	this->uvRect.left = 0;
	this->uvRect.top = 0;
	this->uvRect.width = this->frameSize.x;
	this->uvRect.height = this->frameSize.y;

	this->restart();

	cout << "UVRect dimensions: X: " + uvRect.left << ", Y: " << uvRect.top << ", Width: " << uvRect.width << ", Height: " << uvRect.height << endl;
	
}

sf::IntRect Animation::getUVRect()
{
	return this->uvRect;
}

const sf::Texture* Animation::getTexture()
{
	return &this->texture;
}

void Animation::update(float deltaTime)
{
	timeOnFrame += deltaTime;

	//if it is time to switch frames
	if (timeOnFrame >= timePerFrame)
	{
		//go to the next frame
		nextFrame();

		//reset the timer
		timeOnFrame -= timePerFrame;
	}
}

void Animation::nextFrame()
{
	currentFrame++;
	this->uvRect.left += this->frameSize.x;

	//if we've gone off the right side of the sprite sheet
	if (uvRect.left >= this->getTexture()->getSize().x)
	{
		uvRect.left = 0;
		this->uvRect.top += this->frameSize.y;
	}

	//if we've hit the end of the sprite sheet
	if (uvRect.top >= this->getTexture()->getSize().y)
	{
		//then it's time to restart
		uvRect.top = origin.y;
		uvRect.left = origin.x;
		//currentFrame = 0;
	}

	cout << "Current Frame: " << currentFrame << endl;
}

void Animation::restart()
{
	uvRect.left = origin.x;
	uvRect.top = origin.y;

	currentFrame = 0;
}