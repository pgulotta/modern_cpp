#include <iostream>
#include <string>

template <typename ... Ts>
static auto multicall ( Ts ...functions )
{
  return [ = ]( auto x ) {
    ( void )std::initializer_list<int> {
      ( ( void )functions( x ), 0 )...
    };
  };
}

template <typename F, typename ... Ts>
static auto for_each ( F f, Ts ...xs )
{
  ( void )std::initializer_list<int> {
    ( ( void )f( xs ), 0 )...
  };
}

static auto brace_print ( char a, char b )
{
  return [ = ] ( auto x ) {
    std::cout << a << x << b << ", ";
  };
}

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

  auto f  ( brace_print( '(', ')' ) );
  auto g  ( brace_print( '[', ']' ) );
  auto h  ( brace_print( '{', '}' ) );
  auto nl ( []( auto ) { std::cout << '\n'; } );

  auto call_fgh ( multicall( f, g, h, nl ) );

  for_each( call_fgh, 1, 2, 3, 4, 5 );
}
