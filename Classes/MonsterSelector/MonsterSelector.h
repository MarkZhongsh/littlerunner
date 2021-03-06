#ifndef MONSTERSELECTOR_H_H_
#define MONSTERSELECTOR_H_H_

#include "cocos2d.h"
#include "../Entity/Player.h"
#define MONSTER_MAX 5

class MonsterSelector : public cocos2d::CCNode
{
public:
	CREATE_FUNC(MonsterSelector);
	virtual bool init();
	virtual void update(float dt);
	void bindPlayer(Player* player);
private:
	void createMonter();
private:
	cocos2d::CCArray* m_monterArr;
	Player* m_player;
};
#endif
