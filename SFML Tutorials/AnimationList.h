#pragma once
#include "AnimationBase.h"

#include "SFML/Graphics.hpp"
#include <vector>

using std::vector;
using std::string;

class AnimationList :
	public AnimationBase
{
public:
	AnimationList(sf::RectangleShape& sprite, float fps, 
		vector<string> files);

	///////////////////////////////
	// Inherited via AnimationBase
	// Sets the frame to the corrosponding image in our list of images
	///////////////////////////////
	virtual void setFrame(int frame) override;

	void addFrame(string fileName);

private:
	//////////////////////////////
	// A list of every image 
	// that is used as a frame
	//////////////////////////////
	vector<sf::Texture> textures;
};

