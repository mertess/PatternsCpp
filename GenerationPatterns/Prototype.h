#pragma once
#include <iostream>

class ICloneable
{
public:
	virtual ICloneable* clone() const = 0;
	virtual void get_info() const = 0;
};

class Rectangle : public ICloneable
{
public:
	Rectangle(int height, int width);
	ICloneable* clone() const override;
	void get_info() const override;
private:
	int height;
	int width;
};

class Circle : public ICloneable
{
public:
	Circle(int radius);
	ICloneable* clone() const override;
	void get_info() const override;
private:
	int radius;
};