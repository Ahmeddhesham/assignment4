#include <iostream>
#include "employees.h"
#include "dynamichashtable.h"
#include "linkedlisthashtable.h"
using namespace std;

int main() {
	employees e[9];
	e[0].setemployee("Mina", 30, 10000, 4);
	e[1].setemployee("Fawzy", 45, 5000, 8);
	e[2].setemployee("Yara", 19, 2000, 0);
	e[3].setemployee("Mariam", 32, 8000, 2);
	e[4].setemployee("Ayman", 33, 4000, 8);
	e[5].setemployee("Roshdy", 28, 9000, 3);
	e[6].setemployee("Aya", 26, 6000, 3);
	e[7].setemployee("Abdallah", 29, 7000, 4);
	e[8].setemployee("Fatma", 21, 3000, 1);
	dynamichashtable t(9);
	t.insert(e[0]);
	t.insert(e[1]);
	t.insert(e[2]);
	t.insert(e[3]);
	t.insert(e[4]);
	t.insert(e[5]);
	t.insert(e[6]);
	t.insert(e[7]);
	t.insert(e[8]);
	t.print();
	t.collisionrate();

	cout << endl << endl;
	linkedhashing t2;
	t2.insert(e[0]);
	t2.insert(e[1]);
	t2.insert(e[2]);
	t2.insert(e[3]);
	t2.insert(e[4]);
	t2.insert(e[5]);
	t2.insert(e[6]);
	t2.insert(e[7]);
	t2.insert(e[8]);
	t2.print();
	t2.collisionrate();

	return 0;
}