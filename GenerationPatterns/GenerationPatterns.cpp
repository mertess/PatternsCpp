// GenerationPatterns.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "FactoryMethod.h"
#include "AbstractFactory.h"
#include "Prototype.h"
#include "Builder.h"

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
	//AbstractFactory
	{
		Hero* hero = new Hero(new BlackSwordFlyFactory());
		hero->move();
		std::cout << hero->get_name_sword() << std::endl;
		delete hero;
	}
	//PrototypePattern
	{
		ICloneable* figure = new Rectangle(10, 5);
		figure->get_info();
		auto cloneRect = figure->clone();
		cloneRect->get_info();
		delete figure;
		delete cloneRect;
		figure = new Circle(5);
		figure->get_info();
		auto cloneCircle = figure->clone();
		cloneCircle->get_info();
		delete figure;
		delete cloneCircle;
	}
	//BuilderPattern
	{
		DocumentCreator* creator = new DocumentCreator(new ExcelDocumentBuilder());
		auto doc = creator->createDocument();
		std::cout << doc->Title << " " << doc->Type << " " << doc->Body << std::endl;
		delete doc;
		delete creator;
		creator = new DocumentCreator(new PdfDocumentBuilder());
		doc = creator->createDocument();
		std::cout << doc->Title << " " << doc->Type << " " << doc->Body << std::endl;
		delete doc;
		delete creator;
	}
	return 0;
}