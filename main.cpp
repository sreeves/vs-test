#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {
public:
	Student(string name = "not intialized", double GPA = 0.0);
	void SetName(string studentName);
	void SetGPA(double personName);
	string ToString() const;
private:
	string name;
	double GPA;
};

Student::Student(string initialName, double initialGPA) {
	name = initialName;
	GPA = initialGPA;
}

void Student::SetName(string inputName) {
	name = inputName;
}

void Student::SetGPA(double newGPA) {
	GPA = newGPA;
}

//Insert the ToString member function here
string Student::ToString() const {
   ostringstream studentInfo;
   int precision = 1;
   studentInfo << fixed;
   studentInfo << setprecision(precision);
   studentInfo << name << " has a GPA of " << GPA;
   return studentInfo.str();
}

int mainX() {
	vector<Student*> students;
	bool quit = false;
	string userChoice;
	string addedName;
	double addedGPA = 0.0;
	Student* student = nullptr;
	string studentInfo;
	int indexDropStudent = 0;


	
	do {
		cout << "Enter Option: " << endl;
		cin >> userChoice;
		
		if (userChoice == "add"){
			cout << "Student name: " << endl;
			cin >> addedName;
			cout << addedName << "'s GPA: " << endl;
			cin >> addedGPA;
			student = new Student(addedName, addedGPA);
			students.push_back(student);
		}
		else if (userChoice == "print") {
			for (int i = 0; i < students.size(); ++i) {
				studentInfo = students.at(i)->ToString();
				cout << i << ": " <<  studentInfo << endl;
			}
		}
		else if (userChoice == "drop") {
			cout << "Index of student to drop: " << endl;
			cin >> indexDropStudent;
			delete students.at(indexDropStudent);
			students.erase(students.begin() + indexDropStudent);
		}
		else {
			quit = true;
		}


	} while (!quit);
	

	return 0;
}