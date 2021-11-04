#include <iostream>
#include "LinkedList.h"

// overloads required for struct compatibility

using std::cout;
using std::ostream;

struct Test {
	int  a;
	bool b;
};
ostream& operator<<(ostream& os, const Test& t){
	return os << t.a << '{' << t.b << '}';
}
// add,get,rem,rev,<<,cc
int main() {
	LinkedList<Test> test{{10, 1},{11, 0},{12, 1},{13, 0}};

	test.add    ({14,0}); // ✅
// 	test.remove ({10, 1}); // need operator== overload from Test to Test
	test.print  (); // works after operator<< overload
	test.reverse(); // ✅
//	LinkedList<Test> copycat(test); // doesnt work either bc CC uses get()

	cout << test; // ✅
	cout << test.length();
	
// need to make a conversion from Test to int 
// because static cast in exception handling fails
	// cout << test.get(66);	
	// cout << test.get(1);

	return 0;
}
