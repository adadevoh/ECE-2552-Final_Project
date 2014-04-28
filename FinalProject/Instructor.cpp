#include "Instructor.h"


Instructor::Instructor(string n, string u, string p, vector<Student*> sL) : User(n, u, p)
{
	sList = sL;
}

void Instructor::setUserType(){ this->userName = "instructor"; }

void Instructor::displayStudenList(){
	for (int i = 0; i < sList.size(); i++){
		cout << sList[i]->displayName() << endl;
	}
	cout << endl;
}

vector<Student*> Instructor::getStudentList(){
	return this->sList;
}

Instructor::~Instructor()
{
}
