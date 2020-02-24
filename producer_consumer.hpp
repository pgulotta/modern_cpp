#include <iostream>
#include <queue>
#include <tuple>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
using namespace chrono_literals;


queue<size_t>      q1;
mutex              mut;
condition_variable cv;
bool               finished {false};

static void execute_producer( size_t items )
{
  for ( size_t i {0}; i < items; ++i ) {
    this_thread::sleep_for( 100ms );
    {
      lock_guard<mutex> lk {mut};
      q1.push( i );
    }
    cv.notify_all();
  }

  {
    lock_guard<mutex> lk {mut};
    finished = true;
  }

  cv.notify_all();
}

static void execute_consumer()
{
  while ( !finished ) {
    unique_lock<mutex> l {mut};

    cv.wait( l, [] { return !q1.empty() || finished; } );

    while ( !q1.empty() ) {
      cout << "Got " << q1.front() << " from queue.\n";
      q1.pop();
    }
  }
}

void test_producer_consumer()
{
  thread t1 {execute_producer, 10};
  thread t2 {execute_consumer};
  t1.join();
  t2.join();
  cout << "finished!\n";
}
