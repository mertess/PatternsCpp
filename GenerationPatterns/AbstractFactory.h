#pragma once
#include <string>
#include <iostream>

#pragma region AbstractObjects

class AbstractSword
{
public:
	AbstractSword(std::string sword_name, int damage);
	virtual void attack() const = 0;
	virtual std::string get_name() const = 0;
protected:
	std::string sword_name;
	int damage;
};

class AbstractMovement
{
public:
	virtual void move() const = 0;
};

#pragma endregion

class IHeroFactory
{
public:
	virtual AbstractSword* createSword() const = 0;
	virtual AbstractMovement* createMovement() const = 0;
};

#pragma region ImplementObjects

class BlackSword : public AbstractSword
{
public:
	using AbstractSword::AbstractSword;
	void attack() const override;
	std::string get_name() const override;
};

class FlyMovement : public AbstractMovement
{
public:
	void move() const override;
};

#pragma endregion

#pragma region ImplFactory

class BlackSwordFlyFactory : public IHeroFactory
{
public:
	AbstractSword* createSword() const override;
	AbstractMovement* createMovement() const override;
};

#pragma endregion

class Hero
{
public:
	Hero(IHeroFactory* hero_factory);
	std::string get_name_sword() const;
	void move() const;
private:
	AbstractSword* sword = nullptr;
	AbstractMovement* movement = nullptr;
};