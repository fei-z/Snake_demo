#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    
	snake = new SnakeNode();
	texture = TextureCache::getInstance()->addImage("default.png");
	for (int i = 0; i < 3; i++){
		auto spr = Sprite::createWithTexture(texture);
		snake->push(spr);
		spr->setZOrder(300 - i);
		addChild(spr);
		
	}

	scheduleUpdate();
	schedule(schedule_selector(HelloWorld::update3s),0.3f);
    return true;
}

void HelloWorld::update(float dt){

	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		dir = Vec2(0, 1);
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		dir = Vec2(0, -1);
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		dir = Vec2(-1, 0);
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		dir = Vec2(1, 0);
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		speed = 2;
		schedule(schedule_selector(HelloWorld::moveSnake), 0.004f);
	}
	else {
		speed = 1;
		schedule(schedule_selector(HelloWorld::moveSnake), 0.01f);
	}


}
void HelloWorld::moveSnake(float dt){

	snake->updateWithVec2(dir / 2 );
	
	
}
void HelloWorld::update3s(float dt){
	auto spr = Sprite::createWithTexture(texture);
	spr->setOpacity(0);
	auto fadein = FadeIn::create(1);
	spr->runAction(fadein);
	snake->push(spr);
	addChild(spr);
}
