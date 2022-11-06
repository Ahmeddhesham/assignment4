#include <iostream>
#include "employees.h"
#include "linkedlisthashtable.h"
using namespace std;

linkedhashing::linkedhashing() {
	numberofelements = 0;
	for (int i = 0; i < 10; i++) {
		table[i] = NULL;
	}
}

int linkedhashing::hash(employees e) {
	int h;
	h = e.getexperience() % tablesize;
	return h;
}

void linkedhashing::insert(employees e) {
	int h = hash(e);
	node* newnode;
	newnode = new node;
	newnode->e = e;
	newnode->next = NULL;

	if (table[h] == NULL) {
		table[h] = newnode;
		numberofelements++;
	}
	else {
		node* p;
		p = table[h];
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = newnode;
		numberofelements++;
	}
}

void linkedhashing::remove(employees e) {
	int h = hash(e);
	if (table[h] == NULL) {
		cout<< "Required object was not found." << endl;
	}
	else {
		if (table[h]->e.getname() == e.getname()) {
			node* temp;
			temp = table[h];
			table[h] = table[h]->next;
			delete temp;
			numberofelements--;
		}
		else {
			node* p;
			p = table[h];
			node* q=table[h];
			while (p != NULL&&p->e.getname()!=e.getname()) {
				q = p;
				p = p->next;
			}

			if (p == NULL) {
				cout << "Required object was not found." << endl;
			}
			else {
				q->next = p->next;
				numberofelements--;
				delete p;
			}
		}
	}
}

void linkedhashing::print() {
	node* p;
	for (int i = 0; i < 10; i++) {
		if (table[i] != NULL) {
			
			p = table[i];
			while (p != NULL) {
				cout  << p->e.getname() << " " << p->e.getage() << " " << p->e.getsalary() << " " << p->e.getexperience() <<" -->  ";
				p = p->next;
			}
			cout << " NULL" << endl;
		}
	}
}

void linkedhashing::collisionrate() {
	//collison rate is C = M * (M-1) / 2T
	// where M is the number of elements to be hashed 
	// T is the total number of hashed elements.
	//According to this website:
	//https://iq.opengenus.org/probability-of-collision-in-hash/#:~:text=of%20hash%20values.-,If%20we%20hash%20M%20values%20and%20total%20possible%20hash%20values,(M%2D1)%20%2F%202T
	float c;
	c = (10 * (10 - 1)) / (2 * numberofelements);
	cout << "Collision rate is: " << c;
}