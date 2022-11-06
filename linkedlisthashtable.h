#pragma once
#include <iostream>
#include "employees.h"
using namespace std;

struct node {
	employees e;
	node* next;
};

class linkedhashing {
private:
	int numberofelements;
	node* table[10]; //just so it can work on any number of employees not necessarily the example of the 9 employees
	int tablesize = 10;
	int hash(employees e);

public:
	linkedhashing();
	void insert(employees e);
	void remove(employees e);
	void print();
	void collisionrate();
};