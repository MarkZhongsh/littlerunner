#include "TollgateScene.h"

USING_NS_CC; 

TollgateScene::TollgateScene()
{
}

TollgateScene::~TollgateScene()
{
}

CCScene* TollgateScene::scene()
{
	CCScene* scene = CCScene::create();
	TollgateScene* layer = TollgateScene::create();
	CCLOG("create tollgatescene layer");
	scene->addChild(layer);
	return scene;
}

bool TollgateScene::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	bool bRet = false;
	do
	{
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		m_player = Player::create();
		m_player->bindSprite(CCSprite::create("player.jpg"));
		m_player->setPosition(ccp(200,visibleSize.height / 4));
		this->addChild(m_player,1);
		initBG();

		bRet = true;
	}while(!bRet);
	return bRet;
}


void TollgateScene::initBG()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	m_bgSprite1 = CCSprite::create("bg.jpg");

	m_bgSprite1->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
	this->addChild(m_bgSprite1,0);
	
	m_bgSprite2 = CCSprite::create("bg.jpg");
	m_bgSprite2->setPosition(ccp(visibleSize.width+visibleSize.width/2,visibleSize.height/2));
	m_bgSprite2->setFlipX(true);
	this->addChild(m_bgSprite2,0);
}



