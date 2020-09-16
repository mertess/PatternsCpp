// GenerationPatterns.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "FactoryMethod.h"

int main()
{
	//FactoryMethod
	{
		AbstractFactory* factory = new Factory1("Factory1");
		std::cout << factory->get_name() << std::endl;
		AbstractObject* obj1 = factory->create_object();
		std::cout << obj1->get_name() << std::endl;
		delete factory;
		delete obj1;

		factory = new Factory2("Factory2");
		std::cout << factory->get_name() << std::endl;
		AbstractObject* obj2 = factory->create_object();
		std::cout << obj2->get_name() << std::endl;
		delete factory;
		delete obj2;
	}
	return 0;
}