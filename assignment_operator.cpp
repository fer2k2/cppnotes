// When we use the '=' sign for assingn an object to another
// the copy assignment operator is called
y = x;

// However. It performs a shallow copy as the default copy constructor
// A deep copy requires custom code

// Copy assignment signature:
IntArray& operator=(const IntArray& source) {
  ...
  return *this; // It returns a reference to destination
}

// Copy and swap idiom:
IntArray& operator=(IntArray source) { // Copy made because source was passed by value
  swap(*this, source); // swap portion
  return *this;
} // Destructor is called on the copy when the function's scope ends

// Where swap functions is:
friend void swap(IntArray& a, IntArray& b) noexcept {
  using std::swap;
  // Memberwise swap
  swap(a.m_ptr, b.m_ptr);
  swap(a.m_size, b.m_size);
}
