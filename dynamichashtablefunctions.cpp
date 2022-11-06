#include <iostream>
#include "dynamichashtable.h"
#include "employees.h"
using namespace std;

dynamichashtable::dynamichashtable(int n) {
	numberofobjects = 0;
	tablesize = n;
	table = new employees[n];

	for (int i = 0; i < n; i++) {
		table[i].setexperience(-1);
	}
}

int dynamichashtable::hash(employees e) {
	int h;
	h = e.getexperience() % tablesize;
	return h;
}

void dynamichashtable::insert(employees e) {
	int h = hash(e);

	if (table[h].getexperience() == -1) {
		table[h] = e;
		numberofobjects++;
	}
	else {
		int start=h;
		bool full = true;
		h = (h + 1) % tablesize;
		while (table[h].getexperience() != -1 && start!=h) {
			h = (h + 1) % tablesize;
		}
		if (table[h].getexperience() == -1) {
			table[h] = e;
			numberofobjects++;
			full = false;
		}
		if (full) {
			cout << "No place found, table is full." << endl;
		}
	}
}

void dynamichashtable::remove(employees e) {
	int h = hash(e);

	if (table[h].getname() == e.getname()) {
		table[h].setexperience(-1);
		numberofobjects--;
	}
	else {
		int start = h;
		bool doesnotexist = true;
		while (table[h].getname() != e.getname() || !(start == h)) {
			h = (h + 1) % tablesize;
		}
		if (table[h].getname() == e.getname()) {
			table[h].setexperience(-1);
			numberofobjects--;
			doesnotexist = false;
		}
		if (doesnotexist) {
			cout << "Required object was not found." << endl;
		}
	}
}

void dynamichashtable::print() {
	for (int i = 0; i < tablesize; i++) {
		if (table[i].getexperience() != -1) {
			cout << i + 1 << " " << table[i].getname() << " " << table[i].getage() << " " <<
				table[i].getsalary() << " " << table[i].getexperience() << endl;
		}
	}
}

void dynamichashtable::collisionrate() {
	//collison rate is C = M * (M-1) / 2T
	// where M is the number of elements to be hashed 
	// T is the total number of hashed elements.
	//According to this website:
	//https://iq.opengenus.org/probability-of-collision-in-hash/#:~:text=of%20hash%20values.-,If%20we%20hash%20M%20values%20and%20total%20possible%20hash%20values,(M%2D1)%20%2F%202T
	float c;
	c = (tablesize * (tablesize - 1)) / (2 * numberofobjects);
	cout << "Collision rate is: " << c;
}