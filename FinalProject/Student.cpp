#include "Student.h"


Student::Student(string n, string u, string p) :User(n, u, p) {
	this->courseList = new List<string>();
}

void Student::setUserType(){ this->userType = "student" ; }

void Student::addClass(string course){
	if (courseList->getSize() > 5)cout << "Course limit reached.\n You cannot add anymore classes \n";
	else
		this->courseList->add(course);
}

void Student::displayCourseList(){
	courseList->display();
}

void Student::dropAllClasses(){
	courseList->destroy();
	cout << "Successfully dropped all classes" << endl;
}

bool Student::removeClass(string course){
	if (courseList->isEmpty()){
		cout << "List is empty" << endl;
			return false;
	}
	Node<string> *temp = courseList->getHead(); //cout << "reached removeClass" << endl;
	/*if (courseList->getSize() == 1){
		courseList->destroy();
		return true;
	}*/
	//else{
		while (temp != nullptr){
			if (temp->getData() == course)
				return courseList->deleteNode(temp);
			temp = temp->getNext();
		}
	//}

	return false;
}


Student::~Student()
{
}
