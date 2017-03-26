#include "SnakeNode.h"

void SnakeNode::push(Sprite*spr){
	node *newNode = new node;
	newNode->spr = spr;
	if (m_head == NULL){
		m_head = newNode;
		m_head->init(pos, true);
		m_head->next = NULL;
		m_head->last = NULL;
		m_tail = m_head;
		m_tail->next = NULL;
	}
	else{
		m_tail->next = newNode;
		newNode->last = m_tail;
		m_tail = newNode;
		m_tail->init(Vec2(snakeSize, 0));
		m_tail->next = NULL;
	}
}
bool SnakeNode::is_head(node* obj){
	if (obj == m_head){
		return true;
	}
	return false;
}
bool SnakeNode::is_tail(node* obj){
	if (obj == m_tail){
		return true;
	}
	return false;
}

void SnakeNode::updateWithVec2(Vec2 dir){
	for (node * n = m_head; n != NULL; n = n->next){
		//n->spr->setScaleX(snake->scaleX);
		if (is_head(n)){
			m_head->setPos(m_head->getPos() + dir);
			if (m_head->next != NULL){
				Vec2 headPos = m_head->getPos();
				Vec2 nextPos = m_head->next->getPos();
				Vec2 normalize = (nextPos - headPos).getNormalized();
				m_head->next->push_front(headPos + normalize);
			}
		}
		else{
			if (n->arrPos.size() != 0){
				Vec2 pos = n->popPos();
				n->setPos(pos);
				if (n->next != NULL){
					Vec2 myPos = n->getPos();
					Vec2 nextPos = n->next->getPos();
					Vec2 normalize = (nextPos - myPos).getNormalized();
					n->next->push_front(myPos + normalize);
				}
				n->pop_back();
			}
		}
	}
}