#include "Animation.h"

using std::cout;
using std::endl;

Animation::Animation(sf::RectangleShape &sprite, std::string filePath, float fps, int numFrames, sf::Vector2i rowsByCols)
	:AnimationBase(sprite, fps)
{

	this->texture = loadFromFile(filePath);

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
	this->uvRect.width = this->frameSize.x;
	this->uvRect.height = this->frameSize.y;

	cout << "Frame Width: " << frameSize.x << " Frame Height: " << frameSize.y << endl;

	this->restart();
}

const sf::Texture* Animation::getTexture()
{
	return &this->texture;
}

const sf::Vector2i Animation::getFrameSize()
{
	return this->frameSize;
}

void Animation::setFrame(int frame)
{
	sf::Vector2i coords = origin;

	//loop through the texture until we find the UV coords for 
	//our current frame
	for (int i = 0; i < frame; i++)
	{
		//shift one animation frame to the right
		coords.x += this->frameSize.x;

		//if we've gone off the edge, start the next row
		if (coords.x >= texture.getSize().x)
		{
			coords.y += frameSize.y;
			coords.x = 0;
		}
	}

	//finally, utilize our computed texture coords
	this->uvRect.left = coords.x;
	this->uvRect.top = coords.y;

	this->sprite.setTextureRect(this->uvRect);

	AnimationBase::setFrame(frame);
}
