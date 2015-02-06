#ifndef FLOWWORD_H_H_
#define FLOWWORD_H_H_

#include "cocos2d.h"

class FlowWord : public cocos2d::CCNode
{
public:
	CREATE_FUNC(FlowWord);
	virtual bool init();
	void showWord(const char* text,cocos2d::CCPoint pos);
private:
	cocos2d::CCLabelTTF* m_flowLabel;
	void flowEnd();
};
#endif
