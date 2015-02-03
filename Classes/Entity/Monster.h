#ifndef MONSTER_H_H_
#define MONSTER_H_H_

#include "cocos2d.h"
#include "Entity.h"

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

private:
	bool m_isAlive;
};

#endif
