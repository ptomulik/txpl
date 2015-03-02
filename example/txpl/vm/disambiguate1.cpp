// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

/** // doc: txpl/vm/disambiguate1.cpp {{{
 * \file txpl/vm/disambiguate1.cpp
 * \example txpl/vm/disambiguate1.cpp
 * \brief Usage example for \ref txpl::vm::disambiguate() "vm::disambiguate()"
 */ // }}}

// [Code]
#include <txpl/vm/disambiguate.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/io.hpp>

int main()
{
  using namespace txpl;
  typedef vm::basic_types<char, long> BasicTypes;
  typedef vm::value<BasicTypes> V;

  V v1 = vm::disambiguate<BasicTypes>(L'a');
  V v2 = vm::disambiguate<BasicTypes>("C string");
  V v3 = vm::disambiguate<BasicTypes>('a' + 3);

  std::cout << "v1: " << v1 << std::endl;
  std::cout << "v2: " << v2 << std::endl;
  std::cout << "v3: " << v3 << std::endl;
  return 0;
}
// [Code]

/* [Output] *
v1: a
v2: C string
v3: 100
 * [Output] */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
