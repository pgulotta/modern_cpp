#include <stdio.h>
#include <string>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <set>
#include <cassert>
#include <iostream>
#include "efficient_insert_or_reassign_to_map.hpp"
#include "erase_remove_idiom.hpp"
#include "filter_unique_user_input.hpp"
#include "fold_expressions.hpp"
#include "keep_vector_sorted.hpp"
#include "map_insertion_hint.hpp"
#include "structured_bindings.hpp"
#include "template_class_type_deduction.hpp"




int main()
{
  test_fold_expressions();
  std::cout << "*************************" << std::endl << std::endl;
  test_template_class_type_deduction();
  std::cout << "*************************" << std::endl << std::endl;
  test_structured_bindings();
  std::cout << "*************************" << std::endl << std::endl;
  test_efficient_insert_or_reassign_to_map();
  std::cout << "*************************" << std::endl << std::endl;
  test_erase_remove_idiom();
  std::cout << "*************************" << std::endl << std::endl;
  test_filter_unique_user_input();
  std::cout << "*************************" << std::endl << std::endl;
  test_keep_vector_sorted();
  std::cout << "*************************" << std::endl << std::endl;
  test_map_insertion_hint();
}
