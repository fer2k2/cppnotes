/** Threads **/

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

t1.detach(); // t1 runs freely becoming a deamon process

t1.joinable(); // ask if a thread is joinable, so we can call join()

this_thread::get_id(); // get the current thread ID

this_thread::sleep_for(1s); // current thread sleeps for 1 sec

lock_guard<mutex> locker(comonLock); // the lock guard secures all the statements until the end of the method

// Condition variable

// header
#include <condition_variable>
