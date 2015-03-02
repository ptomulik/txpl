// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

/** // doc: txpl/vm/eval_unary_op1.cpp {{{
 * \file txpl/vm/eval_unary_op1.cpp
 * \example txpl/vm/eval_unary_op1.cpp
 * \brief Usage example for \ref txpl::eval_unary_op_visitor "eval_unary_op_visitor<>"
 */ // }}}

// [Code]
#include <txpl/vm/eval_unary_op.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/op_t.hpp>
#include <txpl/vm/io.hpp>
#include <string>
#include <iostream>

int main()
{
  using namespace txpl::vm;
  value<> r;
  auto neg = eval_unary_op<op_t::neg_>(r);

  if(neg(0))
    std::cout << "1: success" << std::endl;
  else
    std::cout << "1: failure" << std::endl;
  std::cout << "r: " << r << std::endl;

  if(neg(0.123))
    std::cout << "2: success" << std::endl;
  else
    std::cout << "2: failure" << std::endl;
  std::cout << "r: " << r << std::endl;

  if(neg('a'))
    std::cout << "3: success" << std::endl;
  else
    std::cout << "3: failure" << std::endl;
  std::cout << "r: " << r << std::endl;

  return 0;
}
// [Code]

/* [Output] *
1: success
r: -1
2: failure
r: -1
3: success
r: -98
 * [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
