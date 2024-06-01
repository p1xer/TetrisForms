#pragma once
using namespace System::Drawing;
const int HEIGHT = 20;
const int WIDTH = 10;

public ref class IShapes
{
	void virtual RotateRight() = 0;
	void virtual RotateLeft() = 0;
	void virtual MoveRight() = 0;
	void virtual MoveLeft() = 0;
	void virtual FallDown() = 0;
	void virtual Move() = 0;
};

public ref class Shapes : IShapes
{
protected:
	Color color;
	Point startpoint;
	int state;
	int countstate;
	array <array<Point>^>^ pointcoords;
	int size;

public:
	void virtual RotateRight()
	{
		state++;
		if (state >= countstate)
		{
			state = 0;
		}
	}
	void virtual RotateLeft()
	{
		state--;
		if (state < 0)
		{
			state = countstate - 1;
		}
	}
	void virtual MoveRight()
	{
		startpoint.X++; // Горизонтальна координата
	}
	void virtual MoveLeft()
	{
		startpoint.X--;
	}
	void virtual FallDown()
	{
		startpoint.Y = 0; //Обчислити
	}
	void virtual Move()
	{
		startpoint.Y--; // Y вертикальна. Зменшення йде вниз
	}
};

ref class ShapeI : Shapes
{
	ShapeI()
	{
		color = Color::Cyan;
		state = 0;
		countstate = 4;
		size = 4;
		startpoint.X = WIDTH / 2 - size / 2;
		startpoint.Y = HEIGHT + size - 2;
		//pointcoords инициализация

	}
};


