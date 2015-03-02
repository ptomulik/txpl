// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

/** // doc: txpl/vm/can_apply_unary_op1.cpp {{{
 * \file txpl/vm/can_apply_unary_op1.cpp
 * \example txpl/vm/can_apply_unary_op1.cpp
 * \brief Usage example for \ref txpl::vm::can_apply_unary_op "vm::can_apply_unary_op<>"
 */ // }}}

// [Code]
#include <txpl/vm/can_apply_unary_op.hpp>
#include <txpl/vm/op_t.hpp>
#include <iostream>
#include <string>

int main()
{
  using namespace txpl;
  std::cout << std::boolalpha << "can ~int: "
            << vm::can_apply_unary_op<vm::op_t::neg_, int>::value
            << std::endl;
  std::cout << std::boolalpha << "can ~double: "
            << vm::can_apply_unary_op<vm::op_t::neg_, double>::value
            << std::endl;
  return 0;
}
// [Code]

/* [Output] *
can ~int: true
can ~double: false
 * [Output] */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
