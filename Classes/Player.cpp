#include "Player.h"
#include <iomanip>

// ###################################################
// Declarations
// ###################################################

Player::Player()
{
	// cache all .plist frames in cacher
	_cacher = SpriteFrameCache::getInstance();
	_cacher->addSpriteFramesWithFile("res/Sprites/p1.plist");

	//init sprite with a standing frame
	_sprite = new Sprite;
	_sprite->initWithSpriteFrameName("p1_stand.png");

	_moveAnimation = new Animation;
	_moveAnimation = new Animation;
	createMoveAnimation();
}

Player::~Player()
{
}


// ###################################################
// Initializers
// ###################################################

void Player::createMoveAnimation()
{
	const int kNumberOfFrames = 8;
	Vector<SpriteFrame*> frames;
	for (int i = 1; i < kNumberOfFrames; i++)
	{
		std::stringstream ss;
		ss << "p1_walk/p1_walk0" << i << ".png";
		auto sprite = _cacher->getSpriteFrameByName(ss.str());
		frames.pushBack(_cacher->getSpriteFrameByName(ss.str()));
	}

	// play the animation
	const float delay = 0.1f;
	const unsigned int loop = 1;
	_moveAnimation->initWithSpriteFrames(frames, delay, loop);
}

// ###################################################
// Getters
// ###################################################

Sprite* Player::getSprite()
{
	return _sprite;
}

int Player::getPosX()
{
	return _posX;
}

int Player::getPosY()
{
	return _posY;
}
Vec2 Player::getPos()
{
	return Vec2(_posX, _posY);
}


// ###################################################
// Setters
// ###################################################

void Player::setPosX(int newPos)
{
	_posX = newPos;
}

void Player::setPosY(int newPos)
{
	_posY = newPos;
}
void Player::setPosition()
{
	_sprite->setPosition(getPos());
}

// ###################################################
// Methods
// ###################################################

void Player::moveLeft() {
	_sprite->setFlipX(true);
	_posX -= 35;
	auto movement = MoveTo::create(0.6, getPos());
	_sprite->runAction(Spawn::create(Animate::create(_moveAnimation), movement, nullptr));
}

void Player::moveRight() {
	_sprite->setFlipX(false);
	_posX += 35;
	auto movement = MoveTo::create(0.6, getPos());
	_sprite->runAction(Spawn::create(Animate::create(_moveAnimation), movement,0.5f, nullptr));
	
}

void Player::jump() {

}

void Player::fall() {

}

void Player::land() {

}

void Player::crouch() {

}

