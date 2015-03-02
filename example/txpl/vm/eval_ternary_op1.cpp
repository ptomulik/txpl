// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

/** // doc: txpl/vm/eval_ternary_op1.cpp {{{
 * \file txpl/vm/eval_ternary_op1.cpp
 * \example txpl/vm/eval_ternary_op1.cpp
 * \brief Usage example for \ref txpl::eval_ternary_op_visitor "eval_ternary_op_visitor<>"
 */ // }}}

// [Code]
#include <txpl/vm/eval_ternary_op.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/op_t.hpp>
#include <txpl/vm/io.hpp>
#include <string>
#include <iostream>

int main()
{
  using namespace txpl::vm;
  value<> r;
  auto cond = eval_ternary_op<op_t::qmark_>(r);

  if(cond(true, std::string("x2"), std::string("x3")))
    std::cout << "1: success" << std::endl;
  else
    std::cout << "1: failure" << std::endl;
  std::cout << "r: " << r << std::endl;

  if(cond(true, std::string("x1"), 0.3))
    std::cout << "2: success" << std::endl;
  else
    std::cout << "2: failure" << std::endl;
  std::cout << "r: " << r << std::endl;

  if(cond(std::string("x1"), 1, 2))
    std::cout << "3: success" << std::endl;
  else
    std::cout << "3: failure" << std::endl;
  std::cout << "r: " << r << std::endl;

  return 0;
}
// [Code]

/* [Output] *
1: success
r: x2
2: failure
r: x2
3: failure
r: x2 
 * [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
