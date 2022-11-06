#pragma once
#include <iostream>
using namespace std;

class employees {
private:
	string name;
	int age;
	int salary;
	int experience;
public:
	employees();

	void setname(string n);
	void setage(int n);
	void setsalary(int n);
	void setexperience(int n);
	void setemployee(string n, int a, int s, int exp);

	string getname();
	int getage();
	int getsalary();
	int getexperience();
};