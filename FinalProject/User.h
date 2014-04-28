#pragma once
#include<string>

using namespace std;
class User
{
public:
	User(string, string, string);
	virtual ~User();
	virtual void setUserType();
	string getUserType() const;
	string displayName() const;
	string getUserName() const;
	string getPassword() const;

protected:
	string name;
	string userType;
	string userName;
	string password;

};

