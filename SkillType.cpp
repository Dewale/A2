

#include "SkillType.h"

SkillType::SkillType(const ClassType &t) :
_skillType(t)
{
  if (__skillType == SkillType.Dragon){
		_rock = Skill("Claw of Death", Skill::SkillType::Rock);
		_paper = Skill("One kill Bite", Skill::SkillType::Paper);
		_scissors = Skill("Ultimate Stomp", Skill::SkillType::Scissors);
		_weapon = Weapon("Fire Breath",);
		_name = "Drago"
	}
	if (__skillType == SkillType.Barbarian){
		_rock = Skill("Sword", Skill::SkillType::Rock);
		_paper = Skill("Punch", Skill::SkillType::Paper);
		_scissors = Skill("Kick", Skill::SkillType::Scissors);
		_weapon = Weapon("Excalibur");
		_name = "Link"
	}
	if (__skillType == SkillType.Archer){
		_rock = Skill("Arrow of Death", Skill::SkillType::Rock);
		_paper = Skill("Bow Srike ", Skill::SkillType::Paper);
		_scissors = Skill("Rain of Death ", Skill::SkillType::Scissors);
		_weapon = Weapon("Bow and Arrow");
		_name = "Legolas";
	}
}

SkillType::~SkillType()
{}

SkillType SkillType::GetSkillType() const
{
	return _skillType;
}

Skill SkillType::GetRockSkill() const
{
	return _rock;
}

Skill SkillType::GetPaperSkill() const
{
	return _paper;
}

Skill SkillType::GetScissorsSkill() const
{
	return _scissors;
}
Weapon SkillType::GetWeapon() const {
	return _weapon;
}

std::string SkillType::GetSkillTypeName() const
{
	return _name;
}
