#include "FactoryMethod.h"

AbstractObject::AbstractObject(std::string name) : name(name){}

AbstractFactory::AbstractFactory(std::string factory_name) : factory_name(factory_name){}

std::string Object1::get_name()
{
	return this->name;
}

std::string Object2::get_name()
{
	return this->name;
}

AbstractObject* Factory1::create_object()
{
	return new Object1("obj1");
}

AbstractObject* Factory2::create_object()
{
	return new Object2("obj2");
}

std::string Factory1::get_name()
{
	return this->factory_name;
}

std::string Factory2::get_name()
{
	return this->factory_name;
}