#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ios>
#include <cassert>

using namespace std;

enum WinPosEnum { NORMAL, MAX, MIN, LEFT, RIGHT };
enum F_WinPosEnum { F_NORMAL, F_MAX, F_MIN, F_LEFT, F_RIGHT };
enum class WinPosEnum_class { F_NORMAL, F_MAX, F_MIN, F_LEFT, F_RIGHT };

void calculate_foo(const char *cow_name, int start_weight, int end_weight, int num_days)
{
	int weight_gain_per_day = (end_weight - start_weight) / num_days;

	if (start_weight < 0) printf("invalide start weight");
	if (end_weight < 0) printf("invalide end weight");
	if (end_weight < start_weight) printf("cow lost weight");

	printf("%s weighed %d and gained %d per day\n", cow_name, start_weight, weight_gain_per_day);
}

int dostuff2()
{
	double luggageLength = 0.0;
	double luggageWidth = 0.0;
	double luggageHeight = 0.0;
	double linearInches = 0.0;
	double volume = 0.0;
	string userString = "";
	bool firstClass = false;
	string luggageClass = "";
	string luggageCost = "";
	int coachCarryOnInches = 45;
	int coachCheckedInches = 62;
	int firstCarryOnInches = 45;
	int firstCheckedInches = 62;

	cout << "\t\t" << "** Welcome to BYU Air Luggage Sizing **" << endl << endl;
	cout << "Please enter the length, width, and height of your luggage in inches: " << endl << endl;
	cin >> luggageLength;
	cin >> luggageWidth;
	cin >> luggageHeight;

	linearInches = luggageHeight + luggageLength + luggageWidth;
	cout << "Your luggage is " << fixed << setprecision(1) << linearInches << " linear inches." << endl;

	volume = luggageHeight * luggageLength * luggageWidth;
	cout << "Your luggage has a volume of " << fixed << setprecision(1) << volume << " cubic inches." << endl << endl;

	cout << "Are you flying first class (y or n): " << endl << endl;
	cout << "cin is good: " << cin.good() << endl;
	cin >> firstClass;
	cout << "cin is good: " << cin.good() << endl;
	cin.clear();

	if (userString == "y") {
		firstClass = true;
	}
	else {
		firstClass = false;
	}


	if (firstClass == true) {
		//luggageClass = "First Class";
		if (linearInches <= firstCarryOnInches) {
			luggageClass = "Carry on";
			luggageCost = "0.00";
			cout << "Your luggage class is: " << luggageClass << endl;
			cout << "Your cost is: " << luggageCost << endl << endl;
			cout << "Goodbye.";
		}
		else if (linearInches <= firstCheckedInches) {
			luggageClass = "Checked";
			luggageCost = "0.00";
			cout << "Your luggage class is: " << luggageClass << endl;
			cout << "Your cost is: " << luggageCost << endl << endl;
			cout << "Goodbye.";
		}
		else {
			luggageClass = "Not allowed";
			cout << "Your luggage class is: " << luggageClass << endl << endl;
			cout << "Goodbye.";
		}
	}
	else {
	//luggageClass = "Coach";
	if (linearInches <= coachCarryOnInches) {
		luggageClass = "Carry on";
		luggageCost = "$15.00";
		cout << "Your luggage class is: " << luggageClass << endl;
		cout << "Your cost is: " << luggageCost << endl << endl;
		cout << "Goodbye.";
	}
	else if (linearInches <= coachCheckedInches) {
		luggageClass = "Checked";
		luggageCost = "$25.00";
		cout << "Your luggage class is: " << luggageClass << endl;
		cout << "Your cost is: " << luggageCost << endl << endl;
		cout << "Goodbye.";
	}
	else {
		luggageClass = "Not allowed";
		cout << "Your luggage class is: " << luggageClass << endl << endl;
		cout << "Goodbye.";
	}
	}


	//system("pause");

	return 0;
}

int dostuff4() {
	return 0;
}

int dostuff3() {
	dostuff4();
}

int StepsToFeet(int baseSteps) {
   const int FEET_PER_STEP = 3;  // Unit conversion
	int feetTot = 0;              // Corresponding feet to steps
	int val1 = 38;
	int val2;

	val2 = baseSteps + 90;
   
	feetTot = baseSteps * FEET_PER_STEP;
	val2 = val1 + baseSteps;
	val1 -= val2;
}

int dostuff1()
{
	char testchar = '\xFFFFF';
	cout << "testchar:" << testchar << endl;
	const char *str = "long"
	"string";
	int octVar = 011;
	cout << octVar << endl;
	cout << str;

	str = "longer"
	"string";

	// int feet = StepsToFeet(8);
	// assert(feet);
	// assert(dostuff3() /*foo*/ * 3*4);

	/*
	int x = 3;
	string s = "foo";

	ifstream file1;
	ofstream file2;
	file1.open("test-input"); 
	file2.open("test-output");
	if(file1.is_open() && file2.is_open()) {
		file1 >> x;
		file1 >> s;
		file2 << x << s;
	}
	file1.close();
	file2.close();
	cout << x << " " << s << endl;
	tolower('w');

	/*
	char name1[] = "foo";
	char name2[] = "bar";

	cout << "sizeof foo " << sizeof(name1) << endl;
	cout << "sizeof bar " << sizeof(name2) << endl;

	int i1 = 5;
	vector<int> vect(3, 10);

	cout << vect.at(2) << endl;
	i1 = vect.at(2);
	i1 = 6;
	cout << vect.at(2) << endl;
	int& r1 = vect.at(2);
	r1 = 8;
	cout << vect.at(2) << endl;
	vect.pop_back();
	r1 = 9;
	cout << r1 << endl;
	int array_length = 3;
	cin >> array_length;
	cout << "array_length " << array_length << endl;
	int arr1[array_length];
	int arr2[3];
	arr2[6] = 8;
	const int carr1[3] = {0,1,2};

	// cout << RAND_MAX << endl;
	// srand(0);
	// cout << rand() << " " << rand() << " " << rand() << endl;
	// cin >> i2;
	// double myPi = M_PI;
	// cout << myPi << endl;
	/*
	int x = 0, y = 0;
	y = x + x++ + x  ;
	cout << x << "  " << y << endl;

	x=0; y=0;
	y = x++ + x + x  ;
	cout << x << "  " << y << endl;

	x=0; y=0;
	y = x + x + x++  ;
	cout << x << "  " << y << endl;

	x=0; y=0;
	y = x + ++x + x  ;
	cout << x << "  " << y << endl;

	double mydoub = 823921675293.9829319382;
	cout << mydoub << endl;
	cout << setprecision(1);
	cout << mydoub << endl;
	cout << fixed;
	cout << mydoub << endl;

	mydoub -= 309.3;
	cout << mydoub << endl;
	mydoub -= 0.4;
	cout << mydoub << endl;
	if(fabs(mydoub - 0.0) < 0.001)
		cout << "equal dude" << endl;

	uint unsig = 0x80000001;
	cout << "uint " << unsig << endl;
	cout << "int " << static_cast<int>(unsig) << endl;
	cout << "ulong " << static_cast<ulong>(unsig) << endl;
	cout << "long " << static_cast<long>(unsig) << endl;
	//cout << "double " << static_cast<double>(unsig) << endl;
	
	double numstart = 0.7;
	cout << numstart << ". ";
	numstart -= 0.4;
	cout << numstart << ". ";
	numstart -= 0.3;
	cout << numstart << ". ";
	
	string my_string = "Go Cougars";
	tolower(my_string.at(4));
	//my_string.erase(7, 2);
	my_string.replace(7,2,"");
	cout << my_string << endl;
	*/
	cout << "char " << sizeof(char) << ". short " << sizeof(short) << "." << endl;
	cout << "long " << sizeof(long) << ". long long " << sizeof(long long) << "." << endl;
	cout << "int " << sizeof(int) << "." << endl;
	cout << "float " << sizeof(float) << ". double " << sizeof(double) << "." << endl;
	cout << "long double " << sizeof(long double) << "." << endl;
	cout << "bool " << sizeof(bool) << endl;
	/*
	char dd = 104;
	cout << "dd " << dd << endl;

	switch (dd)
	{
		case 104:
			cout << "got 104";
			break;
		//case 'h':
		//	cout << "got h";
		//	break;
	}

	int overfl = 2999999999;
	cout << overfl << endl;
	char c = '\'';
	cout << "size of char " << sizeof(c) << endl;

	
	//int globalscope-test = 3;
	WinPosEnum WindowPosition = WinPosEnum::NORMAL;
	WinPosEnum_class winClass = WinPosEnum_class::F_NORMAL;
	//cout << "WinPosEnum_class value is " << winClass << endl;
	WindowPosition = (WinPosEnum)10;
	int testvar = NORMAL;
	F_WinPosEnum f_WinPosEnum = static_cast<F_WinPosEnum>(NORMAL);
	const int wp = NORMAL;

	WindowPosition = (WinPosEnum) (WindowPosition + 1);
	f_WinPosEnum = (F_WinPosEnum) WindowPosition;
	printf("Window Position is %d\n", WindowPosition);

	/*
	double val1 = 2.3e-3;
	printf("val1 is %f\n", val1);
	cout << "val1 is " << val1 << endl;
	//cout << "divide " << val1 / 0.0 << endl;
	//cout << "divide int " << 10 / 0 << endl;


	int notdone = 2;
	while (notdone--)
	{
		int scopetest = 3;
		calculate_foo("besse", 1000, 2000, 100);
		calculate_foo("lulu", 2000, 2500, 120);
		printf("scopetest is %d\n", scopetest);
	}
	int scopetest;
	printf("scopetest is %d\n", scopetest);
	*/
}

int main(int argv, char **argc)
{
	string foo = "cool stuff";
	foo.at();

	)
	dostuff1();
	//dostuff2();
	pause();
	cout << "done" << endl;
}
