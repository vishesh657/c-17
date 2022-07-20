// Rangarajan Krishnamoorthy
// Example to illustrate std::apply() and std::invoke() 
// October 10, 2018

#include <stdio.h>
#include <array>
#include <tuple>
#include <functional>

using namespace std;

// Simple function to add three integers
int sumOf(int a, int b, int c) {
	return a + b + c;
}

// Simple struct with a member function
// and an instance variable
struct MyClass {
	int add(int a, int b, int c) {
		// Cache the computed result
		return result = a + b + c;
	}
	int result;
};

int main()
{
	array<int, 3> args = { 1, 2, 3 }; // Array object
	tuple<int, int, int> args2(23, 34, 45); // Tuple

	// Regular function call. Pass the arguments directly.
	int sum = sumOf(10, 20, 30);

	// When calling the function directly, we have to pass the args directly as well.
	//    sum = sumOf(args); // Error: Array object
	//    sum = sumOf(args2); // Error: Tuple

	// Assume that the actual function to be called is known dynamically
	// through some variable
	auto sum_func = sumOf;

	// Use "apply" to call the function dynamically, passings args via Tuple, or Array object.
	sum = apply(sum_func, args);
	sum = apply(sum_func, args2);

	// Can't use "apply" to pass the arguments directly
	//    sum = apply(sum_func, 1000, 2000, 3000);

	// Use "invoke" for this. Function call is dynamic, but args are passed directly
	sum = invoke(sum_func, 1000, 2000, 3000);

	// "invoke" doesn't take arguments bundled via Tuple, or Array! Must pass args directly
	// sum = invoke(sum_func, args); // Error
	// sum = invoke(sum_func, args2); // Error

	// What about calling a function such as "printf" that has varargs?
	auto print_func = printf;

	// We need a tuple, not Array object, since args can be of different types
	auto t2 = make_tuple("%d-%f\n", 100, 20.80);

	apply(print_func, t2);
	invoke(print_func, "%d-%f\n", 100, 20.80);

	// Let us use std::apply and std::invoke with class members
	MyClass m_obj;

	// Call the member function by passing its pointer
	// Remember, we need the receiving object as first parameter, so we concatenate the tuples
	sum = apply(&MyClass::add, tuple_cat(make_tuple(m_obj), args2));

	// Here we pass the pointer to object!
	sum = apply(&MyClass::add, tuple_cat(make_tuple(&m_obj), args2));

	// Call "invoke". Supply args in the correct order
	sum = invoke(&MyClass::add, m_obj, 10, 20, 30); // m_obj.add(10, 20, 30)

	// Same call format even when passing pointer to object.
	sum = invoke(&MyClass::add, &m_obj, 10, 20, 30); // (&m_obj)->add(10, 20, 30)

	// Access instance variable, not function. Same call format!
	sum = invoke(&MyClass::result, m_obj); // m_obj.result
	sum = invoke(&MyClass::result, &m_obj); // (&m_obj)->result

	return 0;
}
