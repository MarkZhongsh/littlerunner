#ifndef ENTITY_H_H_
#define ENTITY_H_H_


#include "cocos2d.h"

class Entity : public cocos2d::CCNode
{
public:
	Entity();
	~Entity();
	cocos2d::CCSprite* getSprite();
	void bindSprite(cocos2d::CCSprite* sprite);
private:
	cocos2d::CCSprite* m_sprite;
};
#endif
