// All about threads

// Thread header
#include <thread>

// Given a function

void function_1 ()
{
  cout << "Beaudty is only skin-deep" << std::endl;
}

// Main function runs in one thread and creates other threads

int main()
{
  std::thread t1(function_1);
  t1.join(); // main thread waits for t1 to finish
  return 0;
}

// Detach a thread
t1.detach(); // t1 runs freely becoming a deamon process

t1.joinable(); // ask if a thread is joinable, so we can call join()
