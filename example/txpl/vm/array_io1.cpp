// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

/** // doc: txpl/vm/array_io1.cpp {{{
 * \file txpl/vm/array_io1.cpp
 * \example txpl/vm/array_io1.cpp
 * \brief Usage example for ostream operator<< and txpl::vm::array
 */ // }}}

// [Code]
#include <txpl/vm/array.hpp>
#include <txpl/vm/io.hpp>
#include <boost/variant/get.hpp>
#include <iostream>

int main()
{
  using namespace txpl;
  typedef vm::value<>                  V;
  typedef vm::basic_types<>::int_type  I;
  typedef vm::basic_types<>::char_type C;
  typedef vm::array<>                  A;

  A array = { V(I{7}), V(C{'a'}), V(A()) };

  std::cout << array << std::endl;

  return 0;
}
// [Code]

/* [Output] *
[7, a, []]
 * [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
