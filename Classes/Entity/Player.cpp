#include "Player.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "../Splash/FlowWord.h"
//#include "CCActionInterval.h"

using namespace cocos2d::extension;
USING_NS_CC;

Player::Player()
{
	m_bJumping = false;
	m_hp = 1000;
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
	//getSprite()->runAction(jumpActions);
	this->runAction(jumpActions);
}

void Player::jumpEnd()
{
	m_bJumping = false;
}

void Player::hit()
{
	if(getSprite() == NULL)
	{
		return ;
	}

	FlowWord* flowWord = FlowWord::create();
	this->addChild(flowWord);
	flowWord->showWord("-15",getSprite()->getPosition());

	CCMoveBy* backMove = CCMoveBy::create(0.1f,ccp(-20,0));
	CCMoveBy* forwardMove = CCMoveBy::create(0.1f,ccp(20,0));
	CCRotateBy* backRotate = CCRotateBy::create(0.1f,-5,0);
	CCRotateBy forwardRotate = CCRotateBy::create(0.1f,-5,0);
	m_hp -= 15;
	if(m_hp < 0)
	{
		m_hp = 0;
	}

}

CCRect Player::getBoundingBox()
{
	CCSize size = getSprite()->getContentSize();
	CCPoint entityPos = getPosition();

	CCLOG("%f,%f",entityPos.x,entityPos.y);
	return CCRect(entityPos.x/2,entityPos.y/2,size.width,size.height);
}

int Player::getHP()
{
	return m_hp;
}
