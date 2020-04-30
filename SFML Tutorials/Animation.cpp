#include "Animation.h"

using std::cout;
using std::endl;

Animation::Animation(std::string filePath, float fps, int rows, int cols, bool lastFrameEmpty)
{

	if (this->texture.loadFromFile(filePath))
	{
		this->fps = fps;
		this->timePerFrame = 1.f / fps;

		//the number of frames is equal to the number of rows * columns
		this->rows = rows;
		this->cols = cols;
		this->numFrames = rows * cols;

		//figure out the size of each frame; it is equal to
		//the number width of the texture divided by the number of columns
		int frameWidth = this->texture.getSize().x / this->cols;
		//times the height of the texture divided by the number of rows
		int frameHeight = this->texture.getSize().y / this->rows;

		if (!lastFrameEmpty)
			this->numFrames--;

		//this is my frame size now
		this->frameSize = sf::Vector2i(frameWidth, frameHeight);

		this->uvRect.left = 0;
		this->uvRect.top = 0;
		this->uvRect.width = this->frameSize.x;
		this->uvRect.height = this->frameSize.y;

		cout << "UVRect dimensions: X: " + uvRect.left << ", Y: " << uvRect.top << ", Width: " << uvRect.width << ", Height: " << uvRect.height << endl;
	}
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
	this->uvRect.left += this->frameSize.x;
	//this->uvRect.top += this->frameSize.y;

	//if we've gone off the right side of the sprite sheet
	if (uvRect.left >= this->getTexture()->getSize().x)
	{
		uvRect.left = 0;
		this->uvRect.top += this->frameSize.y;
	}

	//if we've hit the end of the sprite sheet
	if (uvRect.top >= this->getTexture()->getSize().y)
	{
		uvRect.top = 0;
		uvRect.left = 0;
	}
}