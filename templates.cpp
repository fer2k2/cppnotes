/**************************
*** All about templates ***
**************************/
// No template function for comparing two numbers

bool Equals(lhs, rhs)
{
	return lhs == rhs;
}

// Basic function template
template <typename T>
bool Equals(T lhs, T rhs)
{
	return lhs == rhs;
}

// Templates with more than one type
template <typename T, typename U>
bool Equals(T lhs, U rhs)
{
	return lhs == rhs;
}

/** Class templates **/
// TODO: Add parameter initialization on ctor
template <typename T>
class MyPair
{
	T values [2];
public:
	MyPair (T first, T second)
	{
		values[0] = first;
		values[1] = second;
	}
}

/** Template specialization **/
// given the template 
template <typename T>
bool Equals(T lhs, T rhs)
{
	return lhs == rhs;
}

// we can create an specialization for an specific type
template <>
bool Equals<float>(float lhs, float rhs)
{
	// implement floating point imprecission handling
	return true;
}


/** Tag dispatch **/
#include <type_traits>
template <typename T>
bool Equals(T lhs, T rhs)
{
	return Equals(lhs, rhs, conditional<is_floating_point<T>::value, true_type, false_type>{});
}

template <typename T>
bool Equals 



/** SFINAE: Substitution failure is not an error **/

// Option 1

// Option 2

// Option 3


