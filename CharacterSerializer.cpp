/**
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

/**
* This method saves data using Google Protocol Buffers. 
*/
void CharacterSerializer::SaveCharacter(const Character &data){
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	proto::Character character;
	
	character.set_level(data.GetLevel());
	character.set_name(data.GetName());
	character.set_xp(data.GetXp());
	switch(data.GetSkill().GetSkillType()){
		case SkillType::Dragon:
		character.set_type(proto::Character::SkillType::Avatar_SkillType_DRAGON);
		break;
	case SkillType::Babarian:
		character.set_type(proto::Character::SkillType::Avatar_SkillType_BABARIAN);
		break;
	case SkillType::Archer:
		character.set_type(proto::Character::SkillType::Avatar_SkillType_ARCHER);
		break;
	default:
		break;
	}
	
	//Writing the character back to the disk.
	std::fstream output(data.GetName() + ".dat", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!character.SerializeToOstream(&output)){
		std::cerr << "Failed to write cache to disk." << std::endl;
		return;
	}
}


/**
* Loads data using Google Protocol Buffers.
*/
bool CharacterSerializer::LoadCharacter(const std::string &CharacterName){
	
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	proto::Character character;
	//Loading a character
	std::fstream input(charcterName + ".dat", std::ios::in | std::ios::binary);
	if (!input){
		return false;
	}
	else if (!character.ParseFromIstream(&input)){
		std::cerr << "Failed to parse file." << std::endl;
		return false;
	}
	SkillType type;
	switch (character.type()){
	case proto::Character::SkillType::Character_SkillType_DRAGON:
		type = SkillType::Dragon;
		break;
	case proto::Character::SkillType::Character_SkillType_BABARIAN:
		type = SkillType::Babarian;
		break;
	case proto::Character::SkillType::Character_SkillType_ARCHER:
		type = SkillType::Archer;
		break;
	default:
		break;
	}
	
	if (_currentPlayer) delete _currentPlayer;
	_currentPlayer = new Character(character.name(), character.level(), type, character.xp());
	return true;
}

Character *CharacterSerializer::GetPlayer() const{
	return _currentPlayer;
}
