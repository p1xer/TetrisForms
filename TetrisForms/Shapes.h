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
		startpoint.Y++; // Y вертикальна. Збільшується вниз
	}
};

public ref class ShapeGenerator
{
private:
	array<Shapes^>^ shapes_array;
public:
	ShapeGenerator()
	{
		//ініціалізація shapes_array фігурами
	}
	Shapes GetNextShape()
	{
		//випадкове від 1 до 7 і повертати фігуру
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
		startpoint.Y = size - 2;
		//pointcoords инициализация
		pointcoords = gcnew array <array<Point>^> {
			gcnew array<Point> {Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1)},
			gcnew array<Point> {Point(2, 0), Point(2, 1), Point(2, 2), Point(2, 3)},
			gcnew array<Point> {Point(0, 2), Point(1, 2), Point(2, 2), Point(3, 2)},
			gcnew array<Point> {Point(1, 0), Point(1, 1), Point(1, 2), Point(1, 3)}
		};

	}
};

ref class ShapeL_LEFT : Shapes
{
	ShapeL_LEFT()
	{
		color = Color::Blue;
		state = 0;
		countstate = 4;
		size = 4;
		startpoint.X = WIDTH / 2 - size / 2;
		startpoint.Y = size - 2;
		//pointcoords инициализация
		pointcoords = gcnew array <array<Point>^> {
			gcnew array<Point> {Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 2)},
				gcnew array<Point> {Point(0, 1), Point(0, 2), Point(1, 1), Point(1, 2)},
				gcnew array<Point> {Point(0, 1), Point(1, 2), Point(2, 2), Point(3, 2)},
				gcnew array<Point> {Point(1, 0), Point(1, 1), Point(1, 2), Point(1, 3)}
		};

	}
};

//ref class ShapeI : Shapes
//{
//	ShapeI()
//	{
//		color = Color::Cyan;
//		state = 0;
//		countstate = 4;
//		size = 4;
//		startpoint.X = WIDTH / 2 - size / 2;
//		startpoint.Y = size - 2;
//		//pointcoords инициализация
//		pointcoords = gcnew array <array<Point>^> {
//			gcnew array<Point> {Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1)},
//				gcnew array<Point> {Point(2, 0), Point(2, 1), Point(2, 2), Point(2, 3)},
//				gcnew array<Point> {Point(0, 2), Point(1, 2), Point(2, 2), Point(3, 2)},
//				gcnew array<Point> {Point(1, 0), Point(1, 1), Point(1, 2), Point(1, 3)}
//		};
//
//	}
//};
// 
public ref class GameArea 
{
private:
	int width;
	int height;
	array <int, 2>^ area;
public:
	GameArea()
	{
		width = WIDTH;
		height = HEIGHT;

		area = gcnew array<int, 2>(width, height);
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				area[i,j] = 0;
			}
		}
	}
	GameArea(int width_, int height_)
	{
		width = width_;
		height = height_;

		area = gcnew array<int, 2>(width, height);
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				area[i, j] = 0;
			}
		}
	}
	void delAllFullRows()
	{
		int delcount = 0;
		int j = 0;
		while(!isEmptyRow(j))
		{
			if (isFullRow(j))
			{
				zeroRow(j);
				delcount++;
			}
			else
			{
				if (delcount != 0)
				{
					FallRow(j, delcount);
				}
			}

			if (j + 1 < height)
			{
				j++;
			}
			else
			{
				return;
			}
		}
	}
	bool isEmptyRow(int row)
	{
		for (int i = 0; i < width; i++)
		{
			if (area[i, row] != 0)
			{
				return false;
			}
		}
		return true;
	}
	void FallRow(int row, int move_count)
	{
		for (int i = 0; i < width; i++)
		{
			area[i, row + move_count] = area[i, row];
			area[i, row] = 0;
		}
	}
	bool isFullRow(int row)
	{
		for (int i = 0; i < width; i++)
		{
			if (area[i, row] == 0)
			{
				return false;
			}
		}
		return true;
	}
	void zeroRow(int row)
	{
		for (int i = 0; i < width; i++)
		{
			area[i, row] = 0;
		}
	}


	bool isCoordsFree(int x_, int y_)
	{
		if (x_ < width && x_ >= 0 && y_ < height && y_ >= 0)
		{
			if (area[x_, y_] == 0)
			{
				return true;
			}
		}
		return false;
	}

	void FillCoords(int x_, int y_, int value)
	{
		if (x_ < width && x_ >= 0 && y_ < height && y_ >= 0)
		{
			area[x_, y_] = value;
		}
	}

	bool isNoSpace()
	{
		if (isEmptyRow(height))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

};
//Зробити класи для усіх фігур
//Зробити інтерфейс в формі

