#pragma once
#include "User.h"
#include "List.h"
#include"Student.h"
#include<vector>
class Instructor :
	public User
{
public:
	Instructor(string, string, string, vector<Student*>);
	virtual void setUserType();
	void displayStudenList();
	vector<Student*> getStudentList();
	virtual ~Instructor();
private:
	//List<Student> students;
	Student *studentList;
	vector<Student*>sList;
	
};

