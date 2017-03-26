#pragma once

#include "cocos2d.h"
USING_NS_CC;
#include<list>
using namespace std;

struct node
{
	list<Vec2> arrPos;
	Sprite *spr;
	node *next;
	node *last;
	void push_front(Vec2 pos){
		arrPos.push_front(pos);//Ĭ��ͷ������
	}
	Vec2 popPos(){
		Vec2 p = arrPos.back();
		return p;
	}
	void pop_back(){
		arrPos.pop_back();
	}
	Vec2 getPos(){
		return spr->getPosition();
	}
	void setPos(Vec2 pos){
		spr->setPosition(pos);
	}

	void init(Vec2 offsetPos,bool isHead = false){
		if (isHead){
			spr->setZOrder(100);
			setPos(offsetPos);
		}
		else{
			Vec2 lastPos = last->getPos();
			Vec2 pos = lastPos + offsetPos;
			spr->setZOrder(last->spr->getZOrder() - 1);
			setPos(pos);
			int len = ccpDistance(lastPos, pos);
			Vec2 nornalize = (lastPos - pos).getNormalized();
			for (int i = 1; i <= len; i++){
				push_front(lastPos + nornalize * i);
			}
		}
	}
};
class SnakeNode
{
private:
	Vec2 pos = Vec2(400,400); //��ʼ���꣬��ͷ��
	int snakeSize = 10; //����ÿ������ļ��
	node *m_head = NULL;  //��ͷ
	node *m_tail = NULL; //��β
	
public:
	float scaleX = 1;//�Ŵ�
	bool is_head(node* obj);
	bool is_tail(node* obj);
	void push(Sprite*spr);

	void updateWithVec2(Vec2 dir);
};
