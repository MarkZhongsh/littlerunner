#ifndef TOLLGATESCENE_H_H
#define TOLLGATESCENE_H_H

#include "cocos2d.h"
#include "../Entity/Player.h"
#include "cocos-ext.h"


class TollgateScene : public cocos2d::CCLayer
{
public:
	TollgateScene();
	~TollgateScene();
	virtual bool init();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(TollgateScene);
	virtual void update(float delta);
	void createJumpBtn();

	void jumpBtnEvents(CCObject* pSender,cocos2d::extension::CCControlEvent event);

private:
	void initBG();
private:
	cocos2d::CCSprite* m_bgSprite1;
	cocos2d::CCSprite* m_bgSprite2;
	Player* m_player;
};
#endif
