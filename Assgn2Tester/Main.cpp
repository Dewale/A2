#include "gtest/gtest.h"

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

	std::remove("Random.dat"); // Remove the saved character
}
