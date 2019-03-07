// Given the class
class IntArray {
  private:
    int* m_ptr;
    int m_size;
};

// Default memer-wise copy constructor
// a and b point to the same location (shalow copy)
// modifications to a are reflected to b and viceversa
IntArray b = a;
b.m_ptr = a.m_ptr;
b.m_size = a.m_size;

// When any of the objects is out of scope, it calles the corresponding destructor
delete[] a.m_ptr
// Causing a Double-delete bug when the oher's object destructor is called
delete[] b.m_ptr // Runtime error: memory was already freeed

// A basic solution would be to delete the default copy constructor
class IntArray {
  public:
    // Copy constructor
    IntArray(const IntArray&) = delete;
    ...
};

// A better ide ais to implement our own copy constructor that performs Deep-copying
IntArray(const IntArray& source)
{
  if (!source.IsEmpty()) {
    m_size = source.m_size;
    m_ptr = new int[m_size]{};
    
    for (int i=0; i < m_size; i++) {
      m_ptr[i] = source.m_ptr[i];  
    }
  }
}



