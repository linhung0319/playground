#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Object {
public:
	int a;
	Object(int n) {
		a = n;
	}

	~Object() {
		a = 10000;
	}
};


int main() 
{	
	queue<Object> q;
	Object ob1(1);
	Object ob2(2);

	q.push(ob1);
	q.push(ob2);

	//STL Queue pushes an object by copying this object.
	cout << "ob1.a: " << ob1.a << endl;
	cout << "q.front().a: " << q.front().a << endl;
	q.front().a = 3;
	cout << "q.front().a = 3" << endl;
	cout << "ob1.a: " << ob1.a << endl;
	cout << "q.front().a: " << q.front().a << endl << endl;
	
	//STL Queue pops an object by deleting this object.
	//The object's destructor is invoked.
	//If we don't want to delete the object while popping
	//it from the queue, we can push the pointer of this
	//object into the queue instead. A pointer does not have
	//a destructor.
	Object& ob3 = q.front();
	cout << "Object& ob3 = q.front()" << endl;
	cout << "ob3.a: " << ob3.a << endl;
	cout << "q.front().a: " << q.front().a << endl;
	q.pop();
	cout << "q.pop()" << endl;
	cout << "ob3.a: " << ob3.a << endl;

	cout << endl;
	return 0;
}