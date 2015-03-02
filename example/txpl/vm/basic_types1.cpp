// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

/** // doc: txpl/vm/basic_types1.cpp {{{
 * \file txpl/vm/basic_types1.cpp
 * \example txpl/vm/basic_types1.cpp
 * \brief Usage example for txpl::vm::basic_types
 */ // }}}

// [Code]
#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/io.hpp>
#include <boost/variant/static_visitor.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <iostream>

struct inc : boost::static_visitor<void>
{
  template<typename T> void operator() (T) const { }
  void operator() (short& x) const { ++x; }
  void operator() (long& x) const { ++x; }
};

int main()
{
  using namespace txpl;
  typedef vm::basic_types<char, long>  T1;
  typedef vm::basic_types<char, short> T2;
  typedef vm::value<T1> V1;
  typedef vm::value<T2> V2;

  V1 v1 = long{32767};
  V2 v2 = short{32767};

  boost::apply_visitor(inc(), v1);
  boost::apply_visitor(inc(), v2);

  std::cout << "v1: " << v1 << std::endl;
  std::cout << "v2: " << v2 << std::endl;

  return 0;
}
// [Code]

/* [Output] *
v1: 32768
v2: -32768
 * [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
