#pragma once
ref class GPoint
{
public:

	property double X
	{
		double get() { return x; }
		void set(double value) { x = value; }
	}
	property double Y
	{
		double get() { return y; }
		void set(double value) { y = value; }
	}

	GPoint(double x, double y)
	{
		this->X = x;
		this->Y = y;
	}

private:
	double x;
	double y;
};

