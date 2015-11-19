#include <gtest\gtest.h>
#include "CharacterSerializer.h"
#include "Character.h"
#include "SkillType.h"

TEST(Test, SerializerTest)
{
	CharacterSerializer::GetInstance().SaveCharacter(Character("Barbarian", 1, SkillType::Babarian));
	CharacterSerializer::GetInstance().LoadCharacter("Barbarian");
	EXPECT_EQ(1, 1);
}
TEST(Test, NameTest){
	const Character &player = GetPlayer();
	unsigned Health = player.GetHealth();
	EXPECT_EQ(Health, 3);
}
TEST(Test, LevelTest){
	const Character &player = GetPlayer();
	unsigned level = player.GetLevel();
	EXPECT_EQ(level, 1);
}
TEST(Test, NameTest){
	const Character &player = GetPlayer();
	SkillType skillType = player.GetClass();
	EXPECT_EQ(Class, "Mage");
}

