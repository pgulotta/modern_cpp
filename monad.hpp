#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

using vp = std::shared_ptr<int>;
using box_t = struct box { vp val; };
using box_tp = std::shared_ptr<box_t>;


box_tp make_box ( int x )
{
  box b{ std::make_shared<int> ( x ) };
  return std::make_shared<box_t> ( b );
}

class Monad
{
public:
  Monad () {};
  ~Monad () {};

  static int Maybe( box_tp p )
  {
    return ( ( p && p->val ) ? *p->val : 0 );
  }

  std::function<box_tp( box_tp, box_tp, box_tp )>
  operator>>= ( std::function<int( int, int, int )> fn )
  {
    return [this, fn]( box_tp x, box_tp y, box_tp z ) {
      std::vector<box_tp> args = {x, y, z};
      // ugly, will be better in C++17
      std::vector<int> safe_args = {0, 0, 0};
      std::transform ( args.begin (), args.end (),
                       safe_args.begin (), Maybe );
      /* I know it's stupid to unwrap the safe_args here,
         but the more elegant std::apply appears in C++17.
         return std::apply(fn, args_in_tuple);
       */
      return make_box( fn ( safe_args[0], safe_args[1],
                            safe_args[2] ) );
    };
  };
};



void test_monad()
{
  auto m = Monad ();
  auto sum = []( int x, int y, int z ) { return x + y + z; };

  // Bind to the Monad for validation
  auto safe_sum = m >>= sum;  // right shift equals

  auto a = make_box ( 1 );
  auto b = make_box ( 2 );
  auto c = make_box ( 3 );

  /* We have to use Monad::Maybe to get the available result,
     because according to Monad laws, we have to make safe_sum
     return box_tp type either.
   */
  std::cout << "1 + 2 + 3 = "
            << Monad::Maybe( safe_sum ( a, b, c ) )
            << std::endl;
  std::cout << "1 + 2 + nullptr = "
            << Monad::Maybe( safe_sum ( a, b, nullptr ) )
            << std::endl;


}
