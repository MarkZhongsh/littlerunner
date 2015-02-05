#include "MonsterSelector.h"
#include "../Entity/Monster.h"

USING_NS_CC;
bool MonsterSelector::init()
{
//	if(!CCNode::init())
//	{
//		return false;
//	}

	bool bRet = false;
	do
	{
		createMonter();
		this->scheduleUpdate();
		bRet = true;
	}while(!bRet);


	return true;

}

void MonsterSelector::update(float dt)
{
	CCObject* obj;
	CCARRAY_FOREACH(m_monterArr,obj)
	{
		Monster* monster = (Monster*)obj;
		if(monster->isAlive())
		{
			monster->setPositionX(monster->getPositionX()-4);
			
			if(monster->getPositionX() < 0)
			{
				monster->hide();
			}
			else if(m_player)
			{
				if(monster->isCollideWithPlayer(m_player))
				{
					m_player->hit();
					monster->hide();
				}
			}
		}
		else
		{
			monster->show();
		}
	}
	
}


void MonsterSelector::createMonter()
{
	m_monterArr = CCArray::create();
	m_monterArr->retain();

	for(int i = 0;i < MONSTER_MAX; i++)
	{
		Monster* monster = Monster::create();
		monster->bindSprite(CCSprite::create("monster.png"));

		this->addChild(monster);
		m_monterArr->addObject(monster);
	}
}

void MonsterSelector::bindPlayer(Player* player)
{
	m_player = player;
}

