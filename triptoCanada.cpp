#include "library.h"

int MPHtoKPHconvert(double const x, double const y)
{
	if (x <= y)
	{;
		int const z = (x * 1.609344 + 0.5);
		cout << x << " mph is " << z << " kph." << endl;
		MPHtoKPHconvert(x + 5,y);
		return 0;
	}
}

int KmplToMpg(double const x, double const y)
{
	if(x <= y)
	{
		double const z = (x / 1.609344 * 3.78541);
		cout << x << " kmpl is " << z << " mpg.";
		cout << endl;
		KmplToMpg(x + 5, y);
		return 0;
	}
}

int FuelPrice(double const x, double const y, double const efficiency)
{
	if(efficiency <= y)
	{
		int const fuelprice = (x / efficiency * 1.276 + 0.5);
		cout << "If I am planning to take a " << x << " km road trip, " << endl;
		cout << "in Canada, in a car with a fuel efficiency of " << efficiency << endl;
		cout << " kmpl, I need to spend " << fuelprice << "CA$ for fuel." <<endl;
		FuelPrice(x,y,efficiency+5);
		return 0;
	}
}

void main()
{
	FuelPrice(5000,40,20);
}
