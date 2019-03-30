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
bool Equals(T lhs, T rhs) // general case
{
	return Equals(lhs, rhs, conditional_t<is_floating_point<T>::value, true_type, false_type>{});
}

template <typename T>
bool Equals(T lhs, T rhs, true_type) // floating version
{
	// imprecission handling
	return true;
}

template <typename T>
bool Equals(T lhs, T rhs, false_type) // non-floating version
{
	return rhs == rhs;
}

/** SFINAE: Substitution failure is not an error **/
// Option 1
template <typename T>
bool Equals(T lhs, T rhs, false_type, enable_if_t<!is_floating_point<T>::value>* = nullptr) // non-floating version
{
	return rhs == rhs;
}

template <typename T>
bool Equals(T lhs, T rhs, false_type, enable_if_t<is_floating_point<T>::value>* = nullptr) // floating version
{
	// imprecission handling
	return true;
}

// Option 2
template <typename T>
enable_if_t<!is_floating_point<T>::value, bool> Equals(T lhs, T rhs, false_type) // non-floating version
{
	return rhs == rhs;
}

template <typename T>
enable_if_t<is_floating_point<T>::value, bool> Equals(T lhs, T rhs, false_type) // floating version
{
	// imprecission handling
	return true;
}
