/*
* Implementation of CharacterSerializer class
*/

#include "CharacterSerializer.h"
#include "Character.pb.h"

#include <fstream>
#include <iostream>

CharacterSerializer::CharacterSerializer() :
	_currentPlayer(nullptr)
{}

CharacterSerializer::~CharacterSerializer(){
	if (_currentPlayer) delete _currentPlayer;
}

CharacterSerializer &CharacterSerializer::GetInstance(){
	static CharacterSerializer instance;
	return instance;
}

/*
* This method saves data using Google Protocol Buffers. 
*/
void CharacterSerializer::SaveCharacter(const Character &data){
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	proto::Avatar avatar;
}


/*
* Loads data using Google Protocol Buffers.
*/
bool CharacterSerializer::LoadCharacter(const std::string &CharacterName){
	
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	proto::Character character;

	if (_currentPlayer) delete _currentPlayer;
	_currentPlayer = new Character(CharacterName, 1, CharacterClass::GetClassType(CharacterName));
	return true;
}

Character *CharacterSerializer::GetPlayer() const{
	return _currentPlayer;
}
