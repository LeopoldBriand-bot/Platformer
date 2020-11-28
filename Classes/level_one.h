#pragma once

#ifndef __LEVEL_ONE_SCENE_H__
#define __LEVEL_ONE_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
using namespace cocos2d;

class LevelOne : public Layer
{
    private: 
        TMXTiledMap *_tileMap;
        TMXLayer *_tiles;
        TMXLayer* _background;
        TMXLayer* _foreground;
        ValueVector getAnimation(const char* format, int count);

    public:
        virtual bool init();
        static Scene* scene();
        void setViewPointCenter(Point position);
        Player player;

        // implement the "static create()" method manually
        CREATE_FUNC(LevelOne);
};

#endif // __LEVEL_ONE_SCENE_H__