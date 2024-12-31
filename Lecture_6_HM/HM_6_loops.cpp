#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{

	//Task 1
	//a1, a1 + d, a1 + 2d, Е, a1 + (n - 1)d, Е, де a1 - це перший член прогрес≥њ, d = an + 1 - an

	int a1, d, n;

	cout << "Enter [a1] for Arithmetic progression : ";
	cin >> a1;
	cout << "Enter [d] as a step : ";
	cin >> d;
	cout << "Enter [n] of the last element of the arithmetic progression  : ";
	cin >> n;

	//while (n != 0)
	//{
	//	cout << a1 << endl;
	//	a1 = a1 + d;
	//	n -= 1;
	//}

	for (n; n != 0; n -= 1)
	{
		cout << a1 << endl;
		a1 = a1 + d;
	}


	//Task 2 geometery figures creation

	int h, w;
	cout << "Enter h or cube: ";
	cin >> h;
	cout << "Enter w or cube: ";
	cin >> w;

	//triangle
	for (int i = 0; i < h; i++) // height
	{
		for (int j = i; j < w; j++) //wight 
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl << endl;

	//reverse triangle
	for (int i = 1; i <= h; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl << endl;

	//Cube
	for (int i = 0; i < h; i++) // height limit creation
	{
		for (int j = 0; j < w; j++) //wight limit creation
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl << endl;

	//diamond
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < i; j++) // adding a space before * 
		{
			cout << " ";
		}
		for (int j = 0; j < w; j++) // adding *
		{
			cout << "*";
		}
		cout << endl;
	}

	//Task 3
	char user_input;
	int isdigitSum = 0;
	bool stopLoop = true;

	while (stopLoop)
	{
		cout << "[Press '.' for exit]\n";
		cout << "Enter a char: ";
		cin >> user_input;

		if (user_input == '.')
		{
			stopLoop = false;
			cout << "Program was stoped\n\n\n";
			continue;
		}
		if (islower(user_input))
		{
			cout << "Char was converted to uppercase: " << static_cast<char>(toupper(user_input)) << endl << endl << endl;
		}
		else if (isdigit(user_input))
		{
			cout << "Entered char is digit";
			isdigitSum += user_input - '0';
			cout << "Sum of all entered digits is = " << isdigitSum << endl << endl << endl;
		}
		else
		{
			cout << "Input is neither a letter nor a digit. ERROR: " << endl << endl << endl;
		}
	}

	// Task 4
	int fiboNum;
	int temp;
	cout << "Task 4\n";
	cout << "Enter the Fibonacci number fiboNum ";
	cin >> fiboNum;

	if (fiboNum < 1)
	{
		cout << "Enter a positive integer for the Fibonacci sequence.\n";
	}
	else
	{
		int a = 1, b = 1;
		if (fiboNum == 1)
		{
			cout << "The 1st Fibonacci number is: " << a << endl << endl << endl;
		}
		else if (fiboNum == 2)
		{
			cout << "The 2nd Fibonacci number is: " << b << endl << endl << endl;
		}
		else
		{
			for (int i = 3; i <= fiboNum; ++i)
			{
				temp = a + b;
				a = b;
				b = temp;
			}
			cout << "The " << fiboNum << "-th Fibonacci number is: " << b << endl << endl << endl;
		}
	}

	// Task 5
	int factorialNum;
	cout << "Task 5\n";
	cout << "Enter a positive integer for factorial calculation: ";
	cin >> factorialNum;

	if (factorialNum < 1)
	{
		cout << "Please enter a positive integer for factorial calculation.\n";
	}
	else
	{
		long long result = 1;
		for (int i = 1; i <= factorialNum; ++i)
		{
			result *= i;
		}
		cout << "The factorial of " << factorialNum << " is: " << result << endl << endl << endl;
	}



}