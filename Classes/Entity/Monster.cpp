#include "Monster.h"

USING_NS_CC;

Monster::Monster()
{
	m_isAlive = false;
}

Monster::~Monster()
{

}

bool Monster::init()
{
	if(Entity::init())
	{
		return true;
	}
	return false;
}

void Monster::show()
{
	if(getSprite() != NULL)
	{
		this->setVisible(true);
		m_isAlive = true;
	}
}

void Monster::hide()
{
	if(getSprite() != NULL)
	{
		this->setVisible(false);
		reset();
		m_isAlive = false;
	}
}

void Monster::reset()
{
	if(getSprite() != NULL)
	{
		setPosition(ccp(800+CCRANDOM_0_1()*2000,200-CCRANDOM_0_1()*100));
	}
}

bool Monster::isAlive()
{
	return m_isAlive;
}

bool Monster::isCollideWithPlayer(Player* player)
{
	CCRect entityRect = player->getBoundingBox();
	CCPoint monsterPos = getPosition();

	return entityRect.containsPoint(monsterPos);
}
