#include "User.h"
#include"Student.h"
#include"Instructor.h"


User::User(string n, string u, string p) : name(n), userName(u), password(p){ }

string User::getUserType()const{
	return this->userType;
}

string User::displayName()const{
	return this->name;
}

string User::getUserName()const{
	return this->userName;
}

string User::getPassword()const{
	return this->password;
}

void User::setUserType(){
	//if (this->)
}


User::~User()
{
}
