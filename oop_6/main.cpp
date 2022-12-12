#include <iostream>
#include "List.h"

int main() {
	List<int> a(5);
	List<int> b;
	for (int j = 0; j < 4; j++)
		b.push_back(j);
	List<int>::iterator it = a.begin(),it2=b.begin(),it3=b.end();
	a.push(it,it2,it3);
	for (List<int>::iterator it4 = a.begin(); it4 != a.end(); it4++) {
		cout << *it4 << " ";
	}
	cout << endl;
	it = a.begin();
	it2 = it;
	it2++; 
	cout << *it2 << endl;
	a.erase(it,it2);
	for (List<int>::iterator it4 = a.begin(); it4 != a.end(); it4++) {
		cout << *it4 << " ";
	}
	cout << endl;
	for (List<int>::iterator it4 = b.begin(); it4 != b.end(); it4++) {
		cout << *it4 << " ";
	}
	cout << endl;
	it2 = b.begin();
	cout << "ite:" << *it <<endl;
	it3 = it; it3++;
	b.replacement(it2,it,it3);
	for (List<int>::iterator it4 = a.begin(); it4 != a.end(); it4++) {
		cout << *it4 << " ";
	}
	cout << endl;
	for (List<int>::iterator it4 = b.begin(); it4 != b.end(); it4++) {
		cout << *it4 << " ";
	}
	cout << endl;
	it = b.begin(); it2 = it; it2++;
	it3 = b.end();
	cout << *(a.search(it,it2));
	return 0;
}