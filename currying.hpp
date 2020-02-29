#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator> // for ostream_iterator
#include <experimental/algorithm>
#include <experimental/functional>


using namespace std;

using namespace std::experimental;

template <typename Itr>
static void print( Itr it, size_t chars )
{
  copy_n( it, chars, ostream_iterator<char> {cout} );
  cout << '\n';
}

template <typename T>
static void print1( T t )
{
  copy_n( t, 1, ostream_iterator<char> {cout} );
  cout << '\n';
}


template<typename T>
T to_upper( T source )
{
  T destination{source};
  std::transform( source.begin(), source.end(), destination.begin(), ::toupper );
  return destination;
}



void test_currying()
{
  std::cout << to_upper<std::string>( "abc" ) << std::endl;
  vector<char> vec{'d', 'e', 'f'};
  auto vec_out {to_upper( vec ) };

  print( vec.begin(), vec.size() );

  std::cout << std::endl;

  vector<int> nums{1, 2, 3, 4, 5};
  auto nums_out {to_upper( nums ) };

  print( nums_out.begin(), nums_out.size() );
  std::cout << std::endl;




}

