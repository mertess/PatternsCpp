#pragma once
#include <string>

class AbstractObject
{
public:
	AbstractObject(std::string name);
	virtual std::string get_name() = 0;
protected:
	std::string name;
};

class AbstractFactory
{
public:
	AbstractFactory(std::string factory_name);
	virtual AbstractObject* create_object() = 0;
	virtual std::string get_name() = 0;
protected:
	std::string factory_name;
};

class Object1 : public AbstractObject
{
public:
	using AbstractObject::AbstractObject;
	std::string get_name() override;
};

class Object2 : public AbstractObject
{
public:
	using AbstractObject::AbstractObject;
	std::string get_name() override;
};

class Factory1 : public AbstractFactory
{
public:
	using AbstractFactory::AbstractFactory;
	AbstractObject* create_object() override;
	std::string get_name() override;
};

class Factory2 : public AbstractFactory
{
public:
	using AbstractFactory::AbstractFactory;
	AbstractObject* create_object() override;
	std::string get_name() override;
};