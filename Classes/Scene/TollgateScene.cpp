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

		this->scheduleUpdate();
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


void TollgateScene::update(float delta)
{
    int posX1 = m_bgSprite1->getPositionX();
    int posX2 = m_bgSprite2->getPositionX();

    int speed = 1;
    posX1 -= speed;
    posX2 -= speed;

    CCSize bg1Size = m_bgSprite1->getContentSize();
    if(posX1 < -bg1Size.width/2)
    {
        posX1 = bg1Size.width/2 + bg1Size.width-1;
    }

    CCSize bg2Size = m_bgSprite2->getContentSize();
    if(posX2 < -bg2Size.width/2)
    {
        posX2 = bg2Size.width/2 + bg2Size.width-1;
    }

    m_bgSprite1->setPositionX(posX1);
    m_bgSprite2->setPositionX(posX2);

}
