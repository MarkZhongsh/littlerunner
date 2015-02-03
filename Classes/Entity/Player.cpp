#include "Player.h"
#include "cocos2d.h"
#include "cocos-ext.h"
//#include "CCActionInterval.h"

using namespace cocos2d::extension;
USING_NS_CC;

Player::Player()
{
	m_bJumping = false;
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

void Player::jump()
{
	if(getSprite() == NULL)
	{
		return ;
	}
	if(m_bJumping)
	{
		return ;
	}
	m_bJumping = true;
	
	CCJumpBy* jump = CCJumpBy::create(2.0f,ccp(0,0),250,1);
	CCCallFunc* jumpCall = CCCallFunc::create(this,callfunc_selector(Player::jumpEnd));

	CCActionInterval* jumpActions = CCSequence::create(jump,jumpCall,NULL);
	getSprite()->runAction(jumpActions);
}

void Player::jumpEnd()
{
	m_bJumping = false;
}
