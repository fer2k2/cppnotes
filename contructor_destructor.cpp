class IntArray
{
private:
  int* m_ptr{nullptr};
  int m_size{0};

public:
  IntArray() = default; // Default constructor initializes an empty array

  // Explicit constructor avoids undesired implicit casting
  explicit IntArray(int size) {
    if (size != 0) {
      m_ptr = new int[size]{};
      m_size = size;
    }
  }

  // Destructor frees the array memory
  ~IntArray() {
    delete[] m_ptr;
  }

  int Size() const {
    return m_size;
  }

};
