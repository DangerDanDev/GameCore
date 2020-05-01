#include "AnimationList.h"
#include <iostream>

using std::cout;
using std::endl;

AnimationList::AnimationList(sf::RectangleShape& sprite, float fps, vector<string> files)
	:AnimationBase(sprite, fps)
{
	numFrames = files.size();
	cout << "Number of frames: " << files.size() << endl;

	//items are pushed in at the back of a vector, so we iterate backwards for
	//this loop
	for (int i = files.size() - 1; i >= 0; i--)
	{
		addFrame(files.at(i));
	}
	
	this->frameSize = sf::Vector2i(textures[0].getSize().x, textures[0].getSize().y);
	this->uvRect.width = frameSize.x;
	this->uvRect.height = frameSize.y;
}

void AnimationList::setFrame(int frame)
{
	this->sprite.setTexture(&textures.at(frame));
	AnimationBase::setFrame(frame);
}

void AnimationList::addFrame(string fileName)
{
	textures.push_back(this->loadFromFile(fileName));
}
