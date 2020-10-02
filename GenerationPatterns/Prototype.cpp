#include "Prototype.h"

Rectangle::Rectangle(int height, int width) : width(width), height(height){}

ICloneable* Rectangle::clone() const
{
	return new Rectangle(this->height, this->width);
}

void Rectangle::get_info() const
{
	std::cout << "Rectangle height = " << this->height << " width = " << this->width << std::endl;
}

Circle::Circle(int radius) : radius(radius){}

ICloneable* Circle::clone() const
{
	return new Circle(this->radius);
}

void Circle::get_info() const
{
	std::cout << "Circle radius = " << this->radius << std::endl;
}