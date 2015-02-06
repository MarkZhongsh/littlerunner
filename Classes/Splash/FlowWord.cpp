#include "FlowWord.h"

USING_NS_CC;

bool FlowWord::init()
{
	m_flowLabel = CCLabelTTF::create("","Arial",35);
	m_flowLabel->setColor(ccc3(255,0,0));
	m_flowLabel->setAnchorPoint(ccp(1,0));
	m_flowLabel->setVisible(false);

	this->addChild(m_flowLabel);
	return true;
}

void FlowWord::showWord(const char* text,CCPoint pos)
{
	m_flowLabel->setString(text);
	m_flowLabel->setPosition(pos);
	m_flowLabel->setVisible(true);

	CCActionInterval* scaleLarge = CCScaleTo::create(0.2f,2.5f,2.5f);
	CCActionInterval* scaleSmall = CCScaleTo::create(0.2f,0.5f,2.5f);

	CCCallFunc* callFunc = CCCallFunc::create(this,callfunc_selector(FlowWord::flowEnd));

	CCActionInterval* actions = CCSequence::create(scaleLarge,scaleSmall,callFunc,NULL);
	m_flowLabel->runAction(actions);
}

void FlowWord::flowEnd()
{
	m_flowLabel->setVisible(false);
	m_flowLabel->removeFromParentAndCleanup(true);
}

