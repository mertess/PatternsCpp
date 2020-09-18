#include "AbstractFactory.h"

AbstractSword::AbstractSword(std::string sword_name, int damage) : sword_name(sword_name), damage(damage) {}

void BlackSword::attack() const
{
	std::cout << "Black sword attack to damage = " << this->damage << std::endl;
}

std::string BlackSword::get_name() const
{
	return this->sword_name;
}

void FlyMovement::move() const
{
	std::cout << "Fly" << std::endl;
}

AbstractSword* BlackSwordFlyFactory::createSword() const
{
	return new BlackSword("BlackSword", 50);
}

AbstractMovement* BlackSwordFlyFactory::createMovement() const
{
	return new FlyMovement();
}

Hero::Hero(IHeroFactory* factory)
{
	this->sword = factory->createSword();
	this->movement = factory->createMovement();
}

void Hero::move() const
{
	this->movement->move();
}

std::string Hero::get_name_sword() const
{
	return this->sword->get_name();
}

