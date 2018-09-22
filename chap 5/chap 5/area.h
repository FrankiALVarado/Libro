int area(int length, int width) 
{
	if (length <= 0 || width <= 0) error("area() pre-condition");
	int a = length * width;
	if (a <= 0) error("area() post-condition");
	return a;
}

double area(double length, double width)
{
	if (length <= 0 || width <= 0) error("valor no positivo");
	return length * width;
}



int framed_area(int x, int y) // calculate area within frame
{
	constexpr int frame_width = 2;
	if (x - frame_width <= 0 || y - frame_width <= 0)
		error("non-positive area() argument called by framed_area()");
	return area(x - frame_width, y - frame_width);
}

double cuadrado(double l)
{
	return l * l;
}

double ctok(double c) // converts Celsius to Kelvin
{
	if (c < -273.15)
		error("temperatura imposible, menor que la del cero absoluto");

	double k = c + 273.15;
	return k;
}

double ktoc(double k) // kelvin a celsius
{
	if (k < 0)
		error("grados kelvin no pueden ser negativos");
	double c = k - 273.15;
	return c;
}

double ctof(double c)
{
	if (c < -273.15)
		error("temperatura imposible, menor que la del cero absoluto");

	double f = (c * 1.8) + 32;
	return f;
}
double ftoc(double f)
{
	 if (f <-459.67)
		 error("temperatura imposible, menor que la del cero absoluto");

	 double c = (f - 32) / 1.8;
	 return c;
}