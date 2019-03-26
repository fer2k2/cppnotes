// Move constructor of the array class

IntArray(IntArray&& source) {
  // Transfer ownership (steal data) from source
  m_ptr = source.m_ptr;
  m_size = source.m_size;
  // Clear source
  source.m_ptr = nullptr;
  source.m_size = 0;
}
