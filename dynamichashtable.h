#pragma once
#include <iostream>
#include "employees.h"
using namespace std;

class dynamichashtable {
private:
	int numberofobjects;
	int tablesize;
	employees* table;
	int hash(employees e);
public:
	dynamichashtable(int n);

	void insert(employees e);
	void remove(employees e);
	void print();
	void collisionrate();

};