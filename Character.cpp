/*
* Implements the Character class.
*/

#include "Character.h"

/*
* Base constructor for the Character class
*/
Character::Character(const std::string &n, const unsigned &l, const ClassType t) : 
	Actor(),
	_name(n),
	_level(l),
	_health(3 + (l - 1) * 2),
	_class(t),
	_numWins(0),
	_numLosses(0),
	_xp(0),
	_levelup(false)

{
	_sprite_image.create(10, 10, sf::Color::Red);
	_sprite_texture.loadFromImage(_sprite_image);
	_sprite = sf::Sprite(_sprite_texture);
}

/*
* Copy constructor for the Character class
*/
Character::Character(const Character &a) :
	Actor(),
	_name(a.GetName()),
	_level(a.GetLevel()),
	_health(a.GetHealth()),
	_class(a.GetClass()),
	_sprite_image(a._sprite_image)
{
	_sprite_texture.loadFromImage(_sprite_image);
	_sprite = sf::Sprite(_sprite_texture);
}

/*
* Returns the Character's name
*/
std::string Character::GetName() const{
	return _name;
}

/*
* Returns the Character's level
*/
unsigned Character::GetLevel() const
{
	return _level;
}

/*
* Returns the Character's health
*/
unsigned Character::GetHealth() const
{
	return _health; 
}

/* 
* Returns the Character's class
*/
CharacterClass Character::GetClass() const
{
	return _class;
}
/*
* Returns the Character's number of wins
*/
unsigned Character::GetWins() const
{
	return _numWins;
}
/*
* Returns the Character's number of losses
*/
unsigned Character::GetLosses() const
{
	return _numLosses;
}

/**
* This method also increases the XP by 50 and updates the Character's level.
*/
void Character::Incrementwins() 
{
	 _numWins++;
	 _xp += 50;
	 UpdateLevel();
}

/**
* This method also decreases XP by 25 or sets it to zero.
*/
void Character::IncrementLosses() {
	_numLosses++;
	if (_xp > 25) {
		_xp -= 25;
	}
	else {
		_xp = 0;
	}
}

/*
* Returns the Character's current XP.
*/
unsigned Character::GetXp() const{
	return _xp;
}

/*
* Updates the current level of player.
*/
void Character::UpdateLevel(){
	if (_xp >= (_level*_level) * 50)
	{
		_level++;
		_levelup = true;
	}

}

bool Character::GetLevelUp() const{
	return _levelup;
}

/*
* Deals damage taken while in match.
*/
void Character::TakeDamage(const unsigned &damage)
{
	if (damage > _health)
	{
		_health = 0;
	}
	else
	{
		_health = _health - damage;
	}
}

/**
* Position override that also sets the sprite position.
*/
void Character::SetPosition(const float &xPosition, const float &yPosition)
{ 
	sf::Vector2f pos(xPosition, yPosition);
	_position = pos;
	_sprite.setPosition(pos);
};

/**
* The Draw implementation for the Character class which draws the Character's sprite.
*/
void Character::Draw(sf::RenderWindow &window)
{
	window.draw(_sprite);
}
