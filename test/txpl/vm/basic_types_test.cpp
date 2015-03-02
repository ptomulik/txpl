// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_basic_types

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_BASIC_TYPES

#include <txpl/vm/basic_types.hpp>
#include <type_traits>

BOOST_AUTO_TEST_CASE(defaults)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> T;
  BOOST_CHECK((is_same<T::char_type,    char>::value));
  BOOST_CHECK((is_same<T::int_type,     long>::value));
  BOOST_CHECK((is_same<T::bool_type,    bool>::value));
  BOOST_CHECK((is_same<T::real_type,    double>::value));
  BOOST_CHECK((is_same<T::string_type,  std::string>::value));
  BOOST_CHECK((is_same<T::regex_type,   std::regex>::value));
  BOOST_CHECK((is_same<T::blank_type,   boost::blank>::value));
}
BOOST_AUTO_TEST_CASE(wchar_t_)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<wchar_t> T;
  BOOST_CHECK((is_same<T::char_type,    wchar_t>::value));
  BOOST_CHECK((is_same<T::int_type,     long>::value));
  BOOST_CHECK((is_same<T::bool_type,    bool>::value));
  BOOST_CHECK((is_same<T::real_type,    double>::value));
  BOOST_CHECK((is_same<T::string_type,  std::wstring>::value));
  BOOST_CHECK((is_same<T::regex_type,   std::wregex>::value));
  BOOST_CHECK((is_same<T::blank_type,   boost::blank>::value));
}
BOOST_AUTO_TEST_CASE(custom)
{
  using namespace txpl::vm;
  using std::is_same;
  struct x_char;
  struct x_int;
  struct x_bool;
  struct x_real;
  struct x_string;
  struct x_regex;
  struct x_blank;
  typedef basic_types<x_char, x_int, x_bool, x_real, x_string, x_regex, x_blank> T;
  BOOST_CHECK((is_same<T::char_type,    x_char>::value));
  BOOST_CHECK((is_same<T::int_type,     x_int>::value));
  BOOST_CHECK((is_same<T::bool_type,    x_bool>::value));
  BOOST_CHECK((is_same<T::real_type,    x_real>::value));
  BOOST_CHECK((is_same<T::string_type,  x_string>::value));
  BOOST_CHECK((is_same<T::regex_type,   x_regex>::value));
  BOOST_CHECK((is_same<T::blank_type,   x_blank>::value));
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
