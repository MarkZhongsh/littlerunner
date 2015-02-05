#ifndef MONSTER_H_H_
#define MONSTER_H_H_

#include "cocos2d.h"
#include "Entity.h"
#include "Player.h"

class Monster : public Entity
{
public:
	Monster();
	~Monster();
	CREATE_FUNC(Monster);
	virtual bool init();
public:
	void show();
	void hide();
	void reset();
	bool isAlive();
	bool isCollideWithPlayer(Player* player);

private:
	bool m_isAlive;
};

#endif
