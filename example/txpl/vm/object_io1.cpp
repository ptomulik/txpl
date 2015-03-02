// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

/** // doc: txpl/vm/object_io1.cpp {{{
 * \file txpl/vm/object_io1.cpp
 * \example txpl/vm/object_io1.cpp
 * \brief Usage example for ostream operator<< and txpl::vm::object
 */ // }}}

// [Code]
#include <txpl/vm/object.hpp>
#include <txpl/vm/io.hpp>
#include <boost/variant/get.hpp>
#include <iostream>

int main()
{
  using namespace txpl;
  typedef vm::value<>                  V;
  typedef vm::basic_types<>::int_type  I;
  typedef vm::basic_types<>::char_type C;
  typedef vm::object<>                 O;

  O object;
  object["m1"] = V(C{'A'});
  object["m2"] = V(I{3});

  std::cout << object << std::endl;

  return 0;
}
// [Code]

/* [Output] *
{m1: A, m2: 3}
 * [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
