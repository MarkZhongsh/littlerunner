#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}


bool Player::init()
{
	if(!Entity::init())
	{
		return false;
	}
	return true;
}


