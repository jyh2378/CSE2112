#include <iostream>

using namespace std;

int addone(int val) {
	val++;
	return val;
}


int main() {

	int n = 3;
	int ref = addone(n);

	cout << n << endl;
	cout << ref << endl;

	return 0;
}