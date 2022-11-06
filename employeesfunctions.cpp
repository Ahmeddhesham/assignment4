#include <iostream>
#include "employees.h"
using namespace std;

employees::employees() {
	name = "";
	age = 0;
	salary = 0;
	experience = 0;
}

void employees::setname(string n) {
	name = n;
}

void employees::setage(int n) {
	age = n;
}

void employees::setsalary(int n) {
	salary = n;
}

void employees::setexperience(int n) {
	experience = n;
}

void employees::setemployee(string n, int a, int s, int exp) {
	setname(n);
	setage(a);
	setsalary(s);
	setexperience(exp);
}

string employees::getname() {
	return name;
}

int employees::getage() {
	return age;
}

int employees::getsalary() {
	return salary;
}

int employees::getexperience() {
	return experience;
}