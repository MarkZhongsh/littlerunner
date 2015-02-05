#ifndef PLAYER_H_H_
#define PLAYER_H_H_

#include "cocos2d.h"
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();
	virtual bool init();
	CREATE_FUNC(Player);
	void jump();
	void jumpEnd();
	void hit();
	int getHP();
	//获取碰撞范围
	cocos2d::CCRect getBoundingBox();
private:
	bool m_bJumping;
	int m_hp;
};

#endif
