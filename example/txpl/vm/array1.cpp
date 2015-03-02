// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

/** // doc: txpl/vm/array1.cpp {{{
 * \file txpl/vm/array1.cpp
 * \example txpl/vm/array1.cpp
 * \brief Usage example for txpl::vm::array
 */ // }}}

// [Code]
#include <txpl/vm/array.hpp>
#include <txpl/vm/io.hpp>
#include <boost/variant/get.hpp>
#include <iostream>

int main()
{
  using namespace txpl;
  typedef vm::value<>                    V;
  typedef vm::basic_types<>::int_type    I;
  typedef vm::basic_types<>::char_type   C;
  typedef vm::basic_types<>::string_type S;
  typedef vm::array<>                    A;

  A array = { V(I{7}), V(C{'a'}) };
  array.push_back(S("str"));
  array.push_back(A());

  I i = boost::get<I>(array[0]);
  C c = boost::get<C>(array[1]);
  S s = boost::get<S>(array[2]);
  A a = boost::get<A>(array[3]);

  std::cout << "i: " << i << std::endl;
  std::cout << "c: " << c << std::endl;
  std::cout << "s: " << s << std::endl;
  std::cout << "a: " << a << std::endl;

  return 0;
}
// [Code]

/* [Output] *
i: 7
c: a
s: str
a: []
* [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
