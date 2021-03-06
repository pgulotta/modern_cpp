#include <iostream>
#include <set>
#include <string>
#include <iterator> // for ostream_iterator

using namespace std;

void test_filter_unique_user_input()
{
  set<string> s;

  istream_iterator<string> it {cin};
  istream_iterator<string> end;

  copy( it, end, inserter( s, s.end() ) );

  for ( const auto word : s ) {
    cout << word << ", ";
  }

  cout << '\n';
}

