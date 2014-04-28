#include<iostream>
#include<string>
#include<vector>
#include"Student.h"
#include"Instructor.h"

using namespace std;
//initialize list of students
vector<Student*> createStudentList(){
	vector<Student*>myList(10);
	myList[0] = new Student("Joshua Adadevoh", "adadizzle", "23e434");
	myList[1] = new Student("Joanna Adadevoh", "seyram", "48jf34f");
	myList[2] = new Student("Jill Neem", "jneem", "3945fj");
	myList[3] = new Student("James Dean", "jdean", "49jde3");
	myList[4] = new Student("Dean Winchester", "dwinch", "23e434");
	myList[5] = new Student("Sam Winchester", "swinch", "2w4r34");
	myList[6] = new Student("Bobby Singer", "bsing", "48fjf4f");
	myList[7] = new Student("Castiel Angel", "cangel", "5t434df3");
	myList[8] = new Student("Bereket Mathewos", "bmathewos", "34fhd3j");
	myList[9] = new Student("Random User", "ruser", "changeme");

	return myList;
}
///initialize list of users
vector<User*> createUserList(){
	vector<User*>myList(11);
	myList[0] = new Student("Joshua Adadevoh", "adadizzle", "23e434");
	myList[1] = new Student("Joanna Adadevoh", "seyram", "48jf34f");
	myList[2] = new Student("Jill Neem", "jneem", "3945fj");
	myList[3] = new Student("James Dean", "jdean", "49jde3");
	myList[4] = new Student("Dean Winchester", "dwinch", "23e434");
	myList[5] = new Student("Sam Winchester", "swinch", "2w4r34");
	myList[6] = new Student("Bobby Singer", "bsing", "48fjf4f");
	myList[7] = new Student("Castiel Angel", "cangel", "5t434df3");
	myList[8] = new Student("Bereket Mathewos", "bmathewos", "34fhd3j");
	myList[9] = new Student("Random User", "ruser", "changeme");
	myList[10] = new Instructor("Charles Otero", "cotero", "23re928j", createStudentList());

	return myList;
}

vector<Instructor*>createInstructorList(){
	vector<Instructor*> myList(3);
	myList[0] = new Instructor("Charles Otero", "cotero", "23re928j", createStudentList());
	myList[1] = new Instructor("Jeremy Weber", "jwebb", "32en4ew", createStudentList());
	myList[2] = new Instructor("Jack Bower", "jbower", "21ei3df", createStudentList());

	return myList;
}

int studentMenu(Student* student){
	int option;
	cout << "Please select an option from 1 to 4" << endl;
	cout << "1. Add a class" << endl
		 << "2. remove a class" << endl
		 << "3. View class List" << endl
		 << "4. Drop all calsses" << endl
		 << "5. Logout" << endl;
	cout << "Option: "; cin >> option;

	return option;
}

bool studentOption(int input, Student* student){
	string className;
	cout << endl;
	cout << "Thanks!" << endl;
	if (input == 1){
		cout << "Now, please enter the class to add: "; cin >> className;
		student->addClass(className);
		return false;
	}
	else if (input == 2){
		cout << "Now, please enter the class to remove: "; cin >> className;
		if (student->removeClass(className)){
			cout << className << " was dropped successfully" << endl;
			return false;
		}
		else
			cout << "sorry failed to drop " << className << endl
			<< "Is it in your list of regisrtered classes? Try again" << endl;
		return false;
	}
	else if (input == 3){
		cout << "Your list of registered classes: " << endl;
		student->displayCourseList();
		return false;
	}
	else if (input == 4){
		char confirm;
		bool leave = false;
		while (!leave){
			cout << "Are you sure you want to drop all your classes? (Y/N): "; cin >> confirm;
			if (confirm == 'Y'){
				student->dropAllClasses();
				leave = true;
			}
			else if (confirm == 'N'){
				cout << "returning to menu" << endl;
				leave = true;
			}
			else
				cout << "invalid input" << endl;
		}
		return false;
	}
	else if (input == 5){
		cout << "Logging you out" << endl;
		return true;
	}
	else
		cout << "Invalid selection" << endl;
	return false;

}

int instructorMenu(Instructor* instructor){
	int option;
	cout << "Please select an option" << endl;
	cout << "1. Display your student list" << endl
		 << "2. Logout" << endl;
	cout << "Option: "; cin >> option;

	return option;
}

bool instructorOption(int input, Instructor* instructor){
	cout << endl;
	cout << "Thanks!" << endl;

	if (input == 1){
		cout << "List of students in your class: " << endl;
		instructor->displayStudenList();
		return false;
	}
	else if (input == 2){
		cout << "Logging you out" << endl;
		return true;
	}
	else
		cout << "Invalid selection" << endl;
	return false;
}
void instructorStudentList(){

}


int main(){

	vector<Student *>studentList = createStudentList();
	vector<User*>usersList = createUserList();
	vector<Instructor*>instructorList = createInstructorList();
	int usertype;
	bool exit = false;
	

	string username;
	string password;
	while (!exit){
		cout << "Hello, please enter 1 for students, 2 for instuctor, 3 to exit: "; cin >> usertype;
		cout << endl;
		int i = 0;
		int studentAction;
		int instructorAction;
		bool logOut = false;
		//user is a student, check against existing values
		if (usertype == 1){
			cout << "Thank you,now enter your student username and password" << endl;
			cout << "Username: "; cin >> username;
			cout << "Password: "; cin >> password;
			for (int i = 0; i < studentList.size(); i++){
				if (username == studentList[i]->getUserName() && password == studentList[i]->getPassword()){
					cout << endl << "Welcome " << studentList[i]->displayName() << endl;
					while (!logOut){
						studentAction = studentMenu(studentList[i]);
						logOut = studentOption(studentAction, studentList[i]);
					}
					break;
				}//cout << "stil running" << endl;
			}//cout << "Sorry Invalid credentials" << endl;
		}//if user is aninstructor
		else if (usertype == 2){
			cout << "Thank you. Now enter your instructor credentials" << endl;
			cout << "Username: "; cin >> username;
			cout << "Password: "; cin >> password;
			for (int i = 0; i < instructorList.size(); i++){
				if (username == instructorList[i]->getUserName() && password == instructorList[i]->getPassword()){
					cout << endl << "Welcome " << instructorList[i]->displayName() << endl << endl;
					while (!logOut){
						instructorAction = instructorMenu(instructorList[i]);
						logOut = instructorOption(instructorAction, instructorList[i]);
					}
					break;
				}
			}
		}
		else if (usertype == 3){
			cout << "Thanks for using the application..... exiting" << endl;
			exit = true;
		}
		else
			cout << "Sorry, invalid input. Please try again" << endl;
	}

	system("pause");
	return 0;
}