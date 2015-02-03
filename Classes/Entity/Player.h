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
private:
	bool m_bJumping;
};

#endif
