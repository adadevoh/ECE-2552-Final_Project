#pragma once
#include "User.h"
#include"List.h"
class Student :
	public User
{
public:
	Student(string, string, string);
	void addClass(string);
	void displayCourseList();
	bool removeClass(string);
	void dropAllClasses();
	virtual ~Student();
	virtual void setUserType();

private:
	List<string>* courseList;
};

