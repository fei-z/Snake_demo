#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SnakeNode.h"
class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	SnakeNode *snake;
	Texture2D *texture;
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	Vec2 dir = Vec2(0, 1);

	int speed = 2;
	void update(float dt);
	void moveSnake(float dt);
	void update3s(float dt);
};

#endif // __HELLOWORLD_SCENE_H__
