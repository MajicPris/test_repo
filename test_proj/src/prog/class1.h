#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;
	
class queue {
	int q[100];
	int sloc, rloc;
public:
	void init();
	void qput(int i);
	int qget();
};

void queue::init() {
	sloc = rloc = 0;
}

void queue::qput(int i) {
	if (sloc == 100) {
		cout << "to much" << endl;
		return;
	}
	sloc++;
	q[sloc] = i;
}

int queue::qget() {
	if (sloc == rloc) {
		cout << "Empty" << endl;
		return 0;
	}
	rloc++;
	return q[rloc];
}

int main() {
	queue a, b;
	a.init();
	b.init();
	int y=10;
	for (int x = 0; x < 10; x++) {
		a.qput(y);
		cout << a.qget() << endl;
		y++;
	}
	system("pause");
	return 0;
}