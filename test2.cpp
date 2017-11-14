#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std;

class ClassB {
public:
	ClassB();
	ClassB(int parm1);
private:
	int var1;
};

class ClassA {
public:
	ClassA();
	ClassA(int parm1, ClassB b);
	void print() {
		cout << "ClassA::print() - " << var1 << endl;
	}
private:
	int var1;
};

ClassA::ClassA() {
	this->print();
}

ClassA::ClassA(int p1, ClassB b) {

}

int main () {
	int currentCapacity = 2;
	int size = 0;
	int* myspace = new int[currentCapacity];
	myspace[4] = 3;

	ClassA * myClassSpace = new ClassA();

	ClassA * myContainer = new ClassA[10];

	return 0;
}
