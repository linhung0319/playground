#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void print(int *array, const int n);
bool compare(int a, int b);

// Use template to allow either a function pointer or a functor 
// to be passed into the same function.
template <typename FuncType>
void insertion_sort(int *begin, int *end, FuncType compare);

class Com {
private:
	bool state;
public:
	Com(bool _state=true):state(_state){};
	
	// use functor as compare function
	bool operator () (int a, int b);

	// static compare function
	static bool compare(int a, int b);
};

int main() {
	int data[] = {7,4,-1,-5,-3};
	const int n = sizeof(data) / sizeof(data[0]);
	int array[n];

	cout << "Use default compare function:" << endl;
	copy(begin(data), end(data), begin(array));
	sort(array, array + n, greater<int>());
	print(array, n);
	cout << endl;

	cout << "Use normal function as compare function:" << endl;
	copy(begin(data), end(data), begin(array));
	insertion_sort(array, array + n, compare);
	print(array, n);
	cout << endl;
	
	// We can only pass a static member function as compare function.
	// The form of a compare function is bool ()(int, int), while
	// a member function of Com has an implicit parameter resulting
	// in a form of bool ()(Com *this, int, int).
	// A static member function of Com do not have an implicit parameter,
	// so it matches the form of bool()(int, int).
	cout << "Use static member function as compare function:" << endl;
	copy(begin(data), end(data), begin(array));
	Com com1;
	insertion_sort(array, array + n, com1.compare);
	print(array, n);
	cout << endl;

	// What if we want the compare function in Com to be non-static?
	// We can use a functor to achieve this. A functor is a class or 
	// struct object that can be called like a function. It overloads
	// the function-call operator () and allows us to use an object
	// like a function.
	cout << "Use functor as compare function: state = true" << endl;
	copy(begin(data), end(data), begin(array));
	Com com2(true);
	insertion_sort(array, array + n, com2);
	print(array, n);
	cout << endl;

	cout << "Use functor as compare function: state = false" << endl;
	copy(begin(data), end(data), begin(array));
	Com com3(false);
	insertion_sort(array, array + n, com3);
	print(array, n);
	cout << endl;

	return 0;
}

void print(int *array, const int n) {
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}

bool compare(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	return a > b;
}

// Use template to allow either a function pointer or a functor 
// to be passed into the same function.
template <typename FuncType>
void insertion_sort(int* begin, int* end, FuncType compare) {
	int tmp;
	for (int* iptr = begin + 1; iptr != end; ++iptr) {
		for (int* jptr = iptr - 1; jptr >= begin; --jptr) {
			if (!compare(*jptr, *(jptr + 1))) {
				tmp = *jptr;
				*jptr = *(jptr + 1);
				*(jptr + 1) = tmp;
			}
			else {
				continue;
			}
		}
	}
}

bool Com::operator()(int a, int b) {
	if (state) {
		if (a < 0) a = -a;
		if (b < 0) b = -b;
		return a > b;
	}
	else {
		return a > b;
	}
}

bool Com::compare(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	return a > b;
}