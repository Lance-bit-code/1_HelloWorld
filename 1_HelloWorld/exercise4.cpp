#include<iostream>
#include<string>

using namespace std;

static void update(double x, double &max, double &min)
{
	//calculate the max and min so far
	if (x > max)
	{
		max = x;
	}

	else if (x < min)
		{
			min = x;
		}
}

static string deleteString(string input, string stringToDelete)
{
	size_t pos;
	while ((pos = input.find(stringToDelete)) != string::npos)
	{
		input.erase(pos, sizeof(stringToDelete));
	}
	return input;
}

static double unitConversion(string input)
{
	//delete blank
	input = deleteString(input, " ");
	//
	string units[] = { "cm","m","in","ft" };
	double ratio[] = { 0.01,1,0.0254,0.3048 };

	for (int i = 0; i < sizeof(units); i++)
	{
		string numberString = deleteString(input, units[i]);
		if (input != numberString)
		{
			double number = stod(numberString);
			number *= ratio[i];
			return number;
			break;
		}
		if (i == 4 && input == numberString)
		{
			return -1;
		}
	}
}

int main()
{
	string input;
	double max;
	double min;
	bool firstInput = 1;

	while (true)
	{
		cin >> input;

		if ( input == "|" )
		{
			break;
		}
		else 
		{
			if (firstInput == 1)
			{
				double inputDouble = unitConversion(input);

				if (inputDouble == -1)
				{
					break;
				}
				else
				{
					max = inputDouble;
					min = inputDouble;
					firstInput = 0;
				}
			}
			else
			{
				double inputDouble = unitConversion(input);
				if (inputDouble == -1)
				{
					break;
				}
				else
				{
					update(inputDouble, max, min);
				}		
			}
			
			cout << "Max so far is: " << max << endl;
			cout << "Min so far is: " << min << endl;
		}
	}

	return 0;
}