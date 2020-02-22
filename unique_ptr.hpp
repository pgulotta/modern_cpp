#include <iostream>
#include <memory>

using namespace std;

class Moo
{
public:
  string name;

  Moo( string n )
    : name{move( n )}
  { cout << "CTOR " << name << '\n'; }

  ~Moo() { cout << "DTOR " << name << '\n'; }
};

void process_item( unique_ptr<Moo> p )
{
  if ( !p ) { return; }

  cout << "Processing " << p->name << '\n';
}

void test_unique_ptr()
{
  {
    unique_ptr<Moo> p1 {new Moo{"moo"}};
    auto            p2 ( make_unique<Moo>( "bar" ) );
  }

  process_item( make_unique<Moo>( "moo1" ) );

  auto p1 ( make_unique<Moo>( "moo2" ) );
  auto p2 ( make_unique<Moo>( "moo3" ) );

  process_item( move( p1 ) );

  cout << "End of test_unique_ptr()\n";
}
