/**
* Declaration of CharacterSerializer class.
* Singleton class for saving and loading of Character data.
*/

#pragma once

#include <string>
#include "Character.h"

class CharacterSerializer
{
public:
	~CharacterSerializer();

	/**
	* Returns the CharacterSerializer instance.
	*
	* @return the instance of the CharacterSerializer. 
	*/
	static CharacterSerializer &GetInstance();

	/**
	* A member functions for saving Character data.
	* 
	* @param Character - a constant reference to an Character object
	*/
	void SaveCharacter(const Character &Character);

	/**
	* A member functions for loading Character data.
	*
	* @param CharacterName - a constant string that represents the Character's name
	* @return a boolean value indicating success
	*/
	bool LoadCharacter(const std::string &CharacterName);

	/**
	* Returns the current player Character loaded.
	* 
	* @return the loaded player Character
	*/
	Character *GetPlayer() const;

private:
	/** Private constructor for the CharacterSerializer class. */
	CharacterSerializer();
	/** Delete the copy constructor so that it won't be used. */
	CharacterSerializer(CharacterSerializer const&) = delete;
	/** Delete the assignment operator so that it won't be used. */
	void operator=(CharacterSerializer const&) = delete;

	/** A pointer to the current player Character. */
	Character *_currentPlayer;
};
