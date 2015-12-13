#include "gtest/gtest.h"
#include "CharacterSerializer.h"
#include "Character.h"
#include "SkillType.h"

/**
 * Entry point for the tests
 */
void main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("PAUSE");
}

TEST(TestCharacterSerializer, TestSaveAndLoad){
	// Create the new Character
	Character character("Random", 19, SkillType::Dragon);

	// Save the Character to disk
	CharacterSerializer::GetInstance().SaveCharacter(character);

	// Load the Character
	ASSERT_TRUE(CharacterSerializer::GetInstance().Character("Random"));

	// Check for match
	Character *loadedCharacter= CharacterSerializer::GetInstance().GetPlayer();
	EXPECT_EQ(character.GetName(), loadedCharacter->GetName());
	EXPECT_EQ(character.GetLevel(), loadedCharacter->GetLevel());
	EXPECT_EQ(character.GetSkill().GetSkillType(), loadedCharacter->GetSkill().GetSkillType());

	std::remove("Random.dat"); // Removing the saved character
}

TEST(TestCharacterName, TestCorrectName){
	const Character &player = GetPlayer();
	Skill SkillType = player.getSkill();
	EXPECT_EQ(Skill, "Dragon");//First Skill at the top of the array list.
}

TEST(TestCharacterLevel, TestCorrectLevel){
	const Character &player = GetPlayer();
	unsigned level = player.GetLevel();
	EXPECT_EQ(level, 1);//Since all players start at level one
}
TEST(TestCharacterHealth, TestCorrectHealth){
	const Character &player = GetPlayer();
	unsigned Health = player.GetHealth();
	EXPECT_EQ(Health, 3);//All level 1 players have a health of 3.
}
