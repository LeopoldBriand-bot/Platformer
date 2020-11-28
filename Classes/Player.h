#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Player
{
public:

    // ###################################################
    // Declarations
    // ###################################################

    Player();
    ~Player();

    // ###################################################
    // Getters
    // ###################################################

    Sprite* getSprite();
    EventListenerKeyboard* getListener();
    int getPosX();
    int getPosY();
    Vec2 getPos();

    // ###################################################
    // Setters
    // ###################################################

    void setPosX(int newPos);
    void setPosY(int newPos);
    void setPosition();
    

    // ###################################################
    // Methods
    // ###################################################

    void moveLeft();
    void moveRight();
    void jump();
    void fall();
    void land();
    void hurt();
    void crouch();

    // ###################################################
    // Non-inherited external methods
    // ###################################################

    //std::function<void(Vec2)> centerCameraOnOnbject;

private:
    SpriteFrameCache* _cacher;
    Sprite* _sprite;
    int _posX;
    int _posY;
    Animation* _moveAnimation;
    void createMoveAnimation();

};

#endif // __PLAYER_H__

