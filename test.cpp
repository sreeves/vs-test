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
#include <cstring>

using namespace std;

enum WinPosEnum { NORMAL, MAX, MIN, LEFT, RIGHT };
enum F_WinPosEnum { F_NORMAL, F_MAX, F_MIN, F_LEFT, F_RIGHT };
//enum class WinPosEnum_class { F_NORMAL, F_MAX, F_MIN, F_LEFT, F_RIGHT };

class BaseClass {
public:
	virtual string print() const = 0;
	void print2();
};

void BaseClass::print2() {
	this->print();
	print();
}

class ClassB : public BaseClass {
public:
	static const char* default_data;

	ClassB();
	ClassB(const ClassB& orig);						//copy constructor
	ClassB(ClassB&& other) noexcept;					//move constructor
	ClassB(int parm1, const string& parm2, int parm3);
	~ClassB() noexcept;
	ClassB& operator= (const ClassB& rhs);			//copy assignment operator
	ClassB& operator= (ClassB&& rhs) noexcept;	//move assignment operator
	ClassB operator+ (const ClassB& rhs);
	int GetVar1() { return var1; }
	const string& GetData() const { return *data; }
	virtual string print() const;
	string print(string prefix) const {
		return prefix + print();
	}
protected:
	int p2;
private:
	friend std::ostream& operator<< (std::ostream& os, const ClassB& b) {
		os << "ClassB::var1 " << b.var1 << " ClassB::data \"" << *b.data << "\" ClassB::p2 " << b.p2;
		return os;
	}

	string *data;
	int var1;
};

const char* ClassB::default_data = "No Data";

ClassB::ClassB() : data(new string(default_data)) {
	cout << "ClassB::ClassB() - this(" << this << ")" << endl;
	var1 = 2;
	p2 = 2;
}

ClassB::ClassB(const ClassB& orig) : data(new string(*(orig.data))) {
	cout << "ClassB::ClassB(const ClassB &) - this(" << this << ")" << endl;
	var1 = orig.var1;
	p2 = orig.p2;
}

ClassB::ClassB(ClassB&& other) noexcept : data(other.data) {
	cout << "ClassB::ClassB(ClassB &&) - this(" << this << ")" << endl;
	other.data = nullptr;
	var1 = other.var1;
	p2 = other.p2;
}

ClassB::ClassB(int p1, const string& s1, int p2) : data(new string(s1)) {
	cout << "ClassB::ClassB(int, const string&, int) - this(" << this << ")" << endl;
	var1 = p1;
	this->p2 = p2;
};

ClassB::~ClassB() noexcept {
	cout << "ClassB::~ClassB() - this(" << this << ")" << endl;
	delete data;
}

ClassB& ClassB::operator= (const ClassB& rhs) {
	cout << "ClassB::operator=(const ClassB&) - this(" << this << ")" << endl;
	if (this != &rhs) {
		ClassB temp(rhs);				//re-use copy constructor
		*this = std::move(temp);	//re-use move assignment
	}
	return *this;
}

ClassB& ClassB::operator= (ClassB&& rhs) noexcept {
	delete data;
	data = rhs.data;
	rhs.data = nullptr;
	var1 = rhs.var1;
	p2 = rhs.p2;
	return *this;
}

ClassB ClassB::operator+ (const ClassB& rhs) {
	cout << "ClassB::operator+(const ClassB&) - this(" << this << ")" << endl;
	return ClassB(this->var1 + rhs.var1, *this->data + *rhs.data, this->p2 + rhs.p2);
}

string ClassB::print() const {
	ostringstream os("ClassB::print() - ", ios_base::ate);
	os << *this;
	return os.str();
}

class SubB : public ClassB {
public:
	SubB(int x=8);
	int GetX_TestAccess() { return x + p2 + GetVar1(); }
	string print() const;
private:
	int x;
};

SubB::SubB(int x) : x(x), ClassB(4, string("SubB dude"), 4) {
	p2 = 4;
}

string SubB::print() const {
		ostringstream os("SubB::print() - ", ios_base::ate);
		os << ClassB::print() << " SubB::x " << x;
		return os.str();
}

class SubSubB : public SubB {
public:
	SubSubB(int x=45);
	string print() const;
private:
	int sbbx;
};

SubSubB::SubSubB(int x) { sbbx = x; }

string SubSubB::print() const {
	ostringstream os;
	os << "SubSubB::print() - " << SubB::print() << " SubSubB::sbbx " << sbbx;
	return os.str();
}

class ClassA {
public:
	ClassA();
	ClassA(int parm1, vector<double> parm2, ClassB b);
	ClassA(const ClassA &);
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
	myB = ClassB(2, "blank", 2);
}

ClassA::ClassA(const ClassA& orig) {
	cout << "ClassA::ClassA(ClassA &) - this(" << this << ")" << endl;
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
	return ClassA(this->var1 + rhs.var1, vector<double>() , this->myB + rhs.myB);
}

string ClassA::print() {
	ostringstream outStream;
	outStream << "ClassA this: " << this << " var1=" << var1 << " vec size =" << vec.size() << " myB=" << myB.GetVar1() << endl;
	return outStream.str();
}

// ClassA operator+(ClassA lhs, ClassA rhs) {
// 	ClassA result = ClassA();
// 	return result;
// }

template<typename type1>
type1 AddIt(type1 x, type1 y) {
	type1 sum;
	sum = x + y;
	return sum;
}

void dostuff3() {
	int x,y;
	int sum = AddIt(x, y);
	ClassB a1,b1;
	ClassB result = a1 + b1;

	SubB sb1(90);
	SubSubB ssb;
	ClassB *a = new SubSubB();
	cout << a->print() << endl;

	ClassB& br = sb1;
	ClassB& br2 = ssb;
	SubB& sbr1 = ssb;
	ClassB *bp = &sb1;
	ClassB b2 = br;
	ClassB b3 = sb1;
	cout << ssb.print() << endl;
	cout << sb1.print() << endl;
	cout << br.print() << endl;
	cout << br2.print() << endl;
	cout << sbr1.print() << endl;
	cout << bp->print() << endl;
	cout << sb1.ClassB::print() << endl;
	cout << b2.print() << endl;
	cout << b3.print() << endl;
	cout << sb1 << endl;
	cout << br << endl;
	// cout << bp->SubB::print() << endl;
	// cout << sb1.print(string("Prefix Dude:")) << endl;

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

	// ClassA * myContainer2 = new ClassA[3] (2, vector<double> (1, 2.0), ClassB(3));
	// ClassA * myContainer = new ClassA[3];
	// int foo[] = {0, 1, 3, 5, 7};
	// for(auto it = std::begin(foo); it != std::end(foo); ++it) {
	// 	cout << *it << " ";
	// }
	// myContainer[0] = ClassA(2, vector<double> (1, 2.0), ClassB(3, "foo", 3));
	// myContainer[1] = ClassA(5, vector<double> (1, 2.0), ClassB(6, "foo", 6));
	// myContainer[2] = myContainer[0] + myContainer[1];
	// cout << myContainer[2].print() << endl;
	// delete[] myContainer;

	// const char * myP = "wow";
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
