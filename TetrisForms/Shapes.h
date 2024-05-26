#pragma once
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

};


