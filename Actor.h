
#pragma once

#include <SFML\Graphics.hpp>

class Actor
{
public:
	Actor() {} //Constructor 
	~Actor() {} //Deconstructor

	/**
	* Draws a new frame given an sfml window object.
	*
	* @param window - a reference to a window that serves as a target for 2D drawing.
	*/
	virtual void Draw(sf::RenderWindow &window) = 0;

	/**
	* Sets the actor's position in the window.
	* 
	* @param xPosition - a constant reference to a floating point value which represents
	* the x axis
	* @param yPosition - a constant reference to a floating point value which represents
	* the y axis
	*/
	virtual void SetPosition(const float &xPosition, const float &yPosition) { _position = sf::Vector2f(xPosition, yPosition); };

	/**
	* Returns the actor's dimensions.
	* 
	* @return a 2D SFML vector describing the actor's dimensions
	*/
	sf::Vector2f GetDimensions() const { return _dimensions; }

protected:

	/** A 2D vector containing the dimensions of the actor. */
	sf::Vector2f _dimensions;
	/** A 2D vector containing the position of the actor. */
	sf::Vector2f _position;
};
