#pragma once

#include <string>

enum SkillType {Dragon, Barbarian, Archer };

struct Skill {
	enum SkillType { Rock, Paper, Scissors };
	std::string name;
	SkillType type;

	Skill() {}//SkillType constructor
	Skill(std::string n, SkillType t) : name(n), type(t) {}
};

struct Weapon{
	std::string name;

	Weapon() {} 
	Weapon(std::string n) : name(n){}
};

class SkillType
{
public:
	
	SkillType(const SkillTypeType &t);
	~SkillType();//SkillType deconstructor

	static SkillType GetSkillType(const std::string &SkillTypeName);

	/**
	* Returns the skill type 
	*
	*@return the name of the character
	*/
	SkillType GetSkillType() const;
	
	/**
	* Returns the Rock skill type 
	*
	*@return the rock skill type to the Character
	*/
	Skill GetRockSkill() const;

	/**
	* Returns the paper skill type 
	*
	*@return the paper skill type to the Character
	*/
	Skill GetPaperSkill() const;

	/**
	* Returns the scissors skill type 
	*
	*@return the scissors skill type to the Character
	*/
	Skill GetScissorsSkill() const;

protected:
	/** Skill Type name. */
	std::string GetSkillTypeName() const;
};

private:

	const SkillType _skillType;
	Skill _rock;
	Skill _paper;
	Skill _scissors;
	Weapon _weapon;
	std::string _name;
};
