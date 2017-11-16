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
#include <sstream>

using namespace std;

enum WinPosEnum { NORMAL, MAX, MIN, LEFT, RIGHT };
enum F_WinPosEnum { F_NORMAL, F_MAX, F_MIN, F_LEFT, F_RIGHT };
//enum class WinPosEnum_class { F_NORMAL, F_MAX, F_MIN, F_LEFT, F_RIGHT };

class ClassB {
public:
	ClassB();
	ClassB(int parm1);
	int getVar1() {
		return var1;
	}
private:
	int var1;
};

ClassB::ClassB() {
	cout << "ClassB::ClassB() - this(" << this << ")" << endl;
	var1 = 2;
}

ClassB::ClassB(int p1) {
	cout << "ClassB::ClassB(int) - this(" << this << ")" << endl;
	var1 = p1;
};

class ClassA {
public:
	ClassA();
	ClassA(int parm1, vector<double> parm2, ClassB b);
	ClassA operator+(ClassA rhand_side);
	~ClassA();
	string print();
	
private:
	int var1;
	vector<double> vec;
	ClassB myB;
};

ClassA::ClassA() {
	cout << "ClassA::ClassA() - this(" << this << ")" << endl;
	var1 = 2;
	vec = vector<double> (2, 2.0);
	myB = ClassB(2);
}

ClassA::ClassA(int parm1, vector<double> parm2, ClassB b) : myB(b) {
	cout << "ClassA::ClassA(int, vector<double, ClassB) - this(" << this << ")" << endl;
	var1 = parm1;
	vec = parm2;
}

ClassA::~ClassA() {
	cout << "ClassA::~ClassA() - this(" << this << ")" << endl;
}

ClassA ClassA::operator+(ClassA rhs) {
	return ClassA(this->var1 + rhs.var1, vector<double>() ,
		ClassB(myB.getVar1() + rhs.myB.getVar1()));
}

string ClassA::print() {
	ostringstream outStream;
	outStream << "ClassA this: " << this << " var1=" << var1 << " vec size =" << vec.size() << " myB=" << myB.getVar1() << endl;
	return outStream.str();
}

// ClassA operator+(ClassA lhs, ClassA rhs) {
// 	ClassA result = ClassA();
// 	return result;
// }

void dostuff3() {
	// int n=42;
	// double a[n][5];
	// auto p1 = new double[5][5];
	// double (*p1)[n] = new double[n][5];
	// double (*p2)[n] = new double[n][n];
	// cout << sizeof(a) << endl;

	// int size = sizeof(ClassA(88, vector<double>(600, 33.3), ClassB(399)));
	// cout << "sizeof(ClassA) is: " << size << endl;
	// size = sizeof(int);
	// cout << size << endl;
	// size = sizeof(ClassB);
	// cout << size << endl;
	// size = sizeof(vector<double>);
	// cout << size << endl;

	// vector<ClassA> foo(6, ClassA());
	// for(vector<ClassA>::iterator it = foo.begin(); it != foo.end(); it++) {
	// 	(*it).print();
	// }
	// cout << endl;

	ClassA * myContainer = new ClassA[3];
	int foo[] = {0, 1, 3, 5, 7};
	for(auto it = std::begin(foo); it != std::end(foo); ++it) {
		cout << *it << " ";
	}
	// ClassA * myContainer2 = new ClassA[3] (2, vector<double> (1, 2.0), ClassB(3));
	cout << endl;
	myContainer[0] = ClassA(2, vector<double> (1, 2.0), ClassB(3));
	myContainer[1] = ClassA(5, vector<double> (1, 2.0), ClassB(6));
	myContainer[2] = myContainer[0] + myContainer[1];
	cout << myContainer[2].print() << endl;
	delete[] myContainer;

	const char * myP = "wow";
}

int dostuff1()
{
	char testchar = '\0';
	cout << "testchar:" << testchar << endl;
	const char *str = "long"
	"string";
	int octVar = 011;
	cout << octVar << endl;
	cout.operator<<(octVar);
	cout << str;

	str = "longer"
	"string";

	string testStr = "foo";
	cin >> testStr;
	cout << testStr;
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

	*/
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
	return 0;
}

void fooFunc2(const string str) {
	// str.erase(2);
	char c = str.at(2);
	c = 'x';
	cout << "fooFunc2 str is " << str << endl;
}

int main(int argv, char **argc) 
{
	// dostuff1();
	//dostuff2();
	dostuff3();
	pause();
	cout << "done" << endl;
}
