#include "./Classes/level_one.h"
#include <iostream>
#include <vector>
#include "Player.h"

using namespace cocos2d;

Scene* LevelOne::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();

    // 'layer' is an autorelease object
    LevelOne *layer = LevelOne::create();

    // add layer as a child to scene
    scene->addChild(layer);


    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LevelOne::init()
{
    // ###################################################
    // Instanciate tilemap
    // ###################################################

    if (!Layer::init())
    {
        return false;
    }
    // instanciate a new tiledMap with levelone.tmx as model
    _tileMap = new TMXTiledMap();
    _tileMap->initWithTMXFile("res/levelone.tmx");
    // pickup foreground tiles
    _foreground = _tileMap->layerNamed("tiles");
    // add the node to scene tree
    this->addChild(_tileMap);

    // get all tiled objects
    TMXObjectGroup *objectGroup = _tileMap->objectGroupNamed("objects");
    
    //get spawnpoint object from objects
    auto spawnPoints = objectGroup->objectNamed("spawnpoint");


    // ###################################################
    // Create player
    // ###################################################

    auto player = new Player();

    player->setPosX(spawnPoints.at("x").asInt());
    player->setPosY(spawnPoints.at("y").asInt());    
    player->setPosition();
    this->addChild(player->getSprite());

    // ###################################################
    // Add controls
    // ###################################################

    auto listener = EventListenerKeyboard::create();

    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_Q:
            player->moveLeft();
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            player->moveRight();
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_Z:
            player->jump();
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            player->crouch();
            break;
        }
        this->setViewPointCenter(player->getPos());
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, player->getSprite());

    return true;
}

void LevelOne::setViewPointCenter(Point position) {

    //call director to get window size
    Size winSize = Director::getInstance()->getWinSize();

    int x = MAX(position.x, winSize.width / 2);
    int y = MAX(position.y, winSize.height / 2);
    x = MIN(x, (_tileMap->getMapSize().width * this->_tileMap->getTileSize().width) - winSize.width / 2);
    y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height) - winSize.height / 2);
    
    // center view without move edges
    Point actualPosition = Vec2(x, y);
    Point centerOfView = Vec2(winSize.width / 2, winSize.height / 2);
    Point viewPoint = centerOfView - actualPosition;
    this->setPosition(viewPoint);
}

