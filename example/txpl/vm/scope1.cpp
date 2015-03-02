// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

/** // doc: txpl/vm/scope1.cpp {{{
 * \file txpl/vm/scope1.cpp
 * \example txpl/vm/scope1.cpp
 * \brief Usage example for \ref txpl::vm::scope "vm::scope<>"
 */ // }}}

// [Code]
#include <txpl/vm/scope.hpp>
#include <txpl/vm/scope_insert.hpp>
#include <txpl/vm/scope_lookup.hpp>
#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/io.hpp>
#include <boost/variant/get.hpp>
#include <iostream>

void print_symbol(int no, txpl::vm::symbol<> const& sym)
{
  using namespace txpl::vm;
  value<> const* vp = boost::get<value<> >(&sym);
  if(vp)
    std::cout << no << ": " << *vp << std::endl;
  else
    std::cout << no << ": not a value" << std::endl;
}

int main()
{
  using namespace txpl::vm;
  typedef scope<>::key_type K;

  scope<> global;
  symbol<> sym;

  scope_insert(global, K("var"), value<>('a'));
  scope_insert(global, K("ns1::var"), value<>('b'));
  scope_insert(global, K("ns1::ns2::var"), value<>('c'));

  // 1: lookup for "var" in global scope
  if(scope_lookup(global, K(""), K("var"), sym))
    print_symbol(1, sym);
  else
    std::cout << "1: error" << std::endl;

  // 2: lookup for "ns1::var" in global scope
  if(scope_lookup(global, K(""), K("ns1::var"), sym))
    print_symbol(2, sym);
  else
    std::cout << "2: error" << std::endl;

  // 3: lookup for "ns2::var" in global scope (shall not be found)
  if(scope_lookup(global, K(""), K("ns2::var"), sym))
    print_symbol(3, sym);
  else
    std::cout << "3: error" << std::endl;

  // 4: lookup for "ns1::ns2::var" in global scope
  if(scope_lookup(global, K(""), K("ns1::ns2::var"), sym))
    print_symbol(4, sym);
  else
    std::cout << "4: error" << std::endl;

  // 5: lookup for "var" starting from "ns1" scope
  if(scope_lookup(global, K("ns1"), K("var"), sym))
    print_symbol(5, sym);
  else
    std::cout << "5: error" << std::endl;

  // 6: lookup for "var" starting from "ns1::ns2" scope
  if(scope_lookup(global, K("ns1::ns2"), K("var"), sym))
    print_symbol(6, sym);
  else
    std::cout << "6: error" << std::endl;

  // 7: lookup for "ns1::var" starting from "ns1:ns2" scope
  if(scope_lookup(global, K("ns1::ns2"), K("ns1::var"), sym))
    print_symbol(7, sym);
  else
    std::cout << "7: error" << std::endl;

  // 8: lookup for "::var" (absolute name!)
  if(scope_lookup(global, K("ns1::ns2"), K("::var"), sym))
    print_symbol(8, sym);
  else
    std::cout << "8: error" << std::endl;

  // 9: lookup for "abc::xyx" in global scope (shall not be found!)
  if(scope_lookup(global, K(""), K("abc::xyz"), sym))
    print_symbol(9, sym);
  else
    std::cout << "9: error" << std::endl;

  // 10: lookup for "var" starting from "abc" scope (shall not be found!)
  if(scope_lookup(global, K("abc"), K("var"), sym))
    print_symbol(10, sym);
  else
    std::cout << "10: error" << std::endl;

  // 11: lookup for "ns2" starting from "ns1" scope (shall find a scope)
  if(scope_lookup(global, K("ns1"), K("ns2"), sym))
    print_symbol(11, sym);
  else
    std::cout << "11: error" << std::endl;

  return 0;
}
// [Code]

/* [Output] *
1: a
2: b
3: error
4: c
5: b
6: c
7: b
8: a
9: error
10: error
11: not a value
 * [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
