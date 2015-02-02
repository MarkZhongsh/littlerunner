#include "Entity.h"

USING_NS_CC;

Entity::Entity()
{
	m_sprite = NULL;
}

Entity::~Entity()
{

}

CCSprite* Entity::getSprite()
{
	return m_sprite;
}

void Entity::bindSprite(CCSprite* sprite)
{
//	if(m_sprite != NULL)
//	{
//		m_sprite->release();
//		this->
//	}

	this->addChild(sprite);
	m_sprite = sprite;
}
