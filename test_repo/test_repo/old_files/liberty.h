#include <iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;

const int SIZE = 100;

struct inv_type {
	char item[40];
	double cost;
	double retail;
	int on_hand;
	int lead_time;
} invtry[SIZE];

void enter(), init_list(), display();
void update(), input(int i), search();
int menu();

int main(){
	char choice;
	init_list();

	for (;;) {
		choice = menu();
		switch (choice) {
		case'e': enter();
			break;
		case 'u':update();
			break;
		case 'd': display();
			break;
		case 's': search();
			break;
		case 'q': return 0;
			}
	}
	getchar();
	return 0;
}

void init_list() {
	for (int t = 0; t < SIZE; t++)
		*invtry[t].item = '\0';
}
int menu() {
	char ch;
	do {
		cout << "E - enter" << endl;
		cout << "U - update" << endl;
		cout << "D - display" << endl;
		cout << "Q - quit" << endl;
		cout << "S - search for id" << endl;
		cout << "Select comand: " << endl;
		cin >> ch;
	} while (!strchr("eduqs", tolower(ch)));
	return tolower(ch);
}

void enter() {
	int i;

	for (i = 0; i < SIZE; i++)
		if (!*invtry[i].item) break;
	/*if (i = SIZE) {
		cout << "List is full" << endl;
		return;*/
	
	input(i);
}

void input(int i) {
	cout << "Product: ";
	cin >> invtry[i].item;
	cout <<'\n' << "Cost: ";
	cin >> invtry[i].cost;
	cout << '\n' << "Id: ";
	cin >> invtry[i].retail;
}

void update() {

}

void display() {
	int t;

	for (t = 0; t < SIZE; t++) {
		cout << invtry[t].item << endl;
		cout << "Cost: "<< invtry[t].cost << endl;
		cout << "Id: "<<invtry[t].retail << endl;
	}
}

void search() {
	int a;
	cout << "Enter id: ";
	cin >> a;
	for (int i = 0; i < SIZE; i++) {
		if (a == invtry[i].retail)
			cout << "Your product: " << invtry[i].item << endl;
	}
}


