/**
* A Character extends Actor. It contains character attributes that are used by human and AI players.
*/
#pragma once

#include "Actor.h"
#include "CharacterClass.h"

class Character : public Actor 
{
public:
	
	Character(const Character &a);
	/** Character class deconstructor. */
	~Character() {}

	/**
	* Returns the Character's name.
	*
	* @return the name of the Character
	*/
	std::string GetName() const;

	/**
	* Returns the Character's level.
	* 
	* @return the level of the Character, represented as an unsigned number
	*/
	unsigned GetLevel() const;

	/**
	* Returns the Character's health.
	* 
	* @return the health of the Character, represented as an unsigned number
	*/
	unsigned GetHealth() const;

	/**
	* Returns the Character's class object.
	*
	* @return the CharacterClass specification of the Character.
	*/
	CharacterClass GetClass() const;
	
	/**
	* Returns the Character's number of wins.
	* 
	* @return the number of times the Character has won
	*/
	unsigned Character::GetWins() const;
	
	/**
	* Returns the Character's number of Losses.
	* 
	* @return the number of times the Character has lost
	*/
	unsigned Character::GetLosses() const;
	
	/**
	* Updates the number of wins.
	* This method increments the number of wins for the Character.
	*/
	void Character::Incrementwins();

	/**
	* Updates the number of losses.
	* This method increments the number of losses for the Character.
	*/
	void Character::IncrementLosses();

	/**
	* Returns the Character's current XP.
	* 
	* @return the current XP (experience) that the Character has as an unsigned number
	*/
	unsigned Character::GetXp() const;

	/**
	* Updates the level.
	*/
	void Character::UpdateLevel();
	
	/**
	* Determines if the level needs to be updated.
	*
	* @return a boolean value indicating whether the Character can level up
	*/
	bool Character::GetLevelUp() const;

	/**
	* Deals damage taken while playing a round.
	*/
	void TakeDamage(const unsigned &damage);

	/**
	* Actor Interface: draws the Character.
	*/
	void Draw(sf::RenderWindow &window) override;

	/**
	* Actor Interface: specifies the position of the Character.
	*/
	void SetPosition(const float &xPosition, const float &yPosition) override;

protected:
	/** Name of the Character. */
	const std::string _name;
	/** The Character's current level. */
	unsigned _level;
	/** The amount of health that the Character has. */
	unsigned _health;
	/** The number of wins that the Character has achieved. */
	unsigned _numWins;
	/** The number of losses that the Character has suffered. */
	unsigned _numLosses;
	/** The amount XP (experience) that the Character currently has; cannot be less than zero. */
	unsigned _xp;
	/** Contains whether the Character has leveled up. */
	bool _levelup;
	/** The sprite that represents the Character. */
	sf::Sprite _sprite;
	/** The image used for the Character's sprite. */
	sf::Image _sprite_image;
	/** The texture that the Character's image uses. */
	sf::Texture _sprite_texture;
	/** The Character's class. */
	const CharacterClass _class;
};
