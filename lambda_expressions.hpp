#include <iostream>
#include <string>



static void test_lambda_expressions()
{
  std::cout  << []( auto l, auto r ) { return l + r; }( 123, 456 )  << '\n';

  auto counter0 ( [] ( auto count = 0 )  { return ++count; } );
  auto counter1 ( [count = 0] () mutable { return ++count; } );
  auto count = 0;
  auto counter2 ( [&count] ()  { return ++count; } );

  for ( size_t i {0}; i < 5; ++i ) {
    std::cout << counter0( i ) << ", ";
    std::cout << counter1() << ", ";
    std::cout << counter2() <<  std::endl;
  }



}
