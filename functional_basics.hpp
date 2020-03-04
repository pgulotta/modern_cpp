#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>

template <class from, class to> class Functor
{
public:
  Functor ( std::function<to ( from )> op ) : op_ ( op ) {};
  ~Functor () {};
  template <class T> T operator()( T c )
  {
    transform ( c.begin (), c.end (), c.begin (), op_ );
    return c;
  };
private:
  std::function<to ( from )> op_;
};

void test_functional_basics()
{
  int x = 5;
  auto thunk = [x]() {
    std::cout << "now thunk run" << std::endl;
    return x + 10;
  };

  std::cout << "Thunk will not run before you run it" << std::endl;
  std::cout << thunk() << std::endl;
  std::cout << "***************************************" << std::endl;

  std::list<int> a = {1, 2, 3};
  auto f = Functor<int, int> ( []( int x ) { return 2 * x; } );
  auto g = Functor<int, int> ( []( int x ) { return 10 * x; } );
  auto z = Functor<int, int> ( []( int x ) { return x + 1; } );

  auto result1 = g( f( a ) );
  auto result2 = f( g( a ) );
  std::cout << "Function composition: " << ( result2 == result1 ? "yes" : "no" ) << std::endl;
  // We use Functor p to print out the final result
  auto p = Functor<int, int> ( []( int x ) {
    std::cout << x << std::endl;
    return x;
  } );
  p( result1 );
  p( result2 );
}
