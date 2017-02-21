// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_value

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_VALUE

#include <txpl/vm/value.hpp>
#include <txpl/vm/array.hpp>
#include <txpl/vm/object.hpp>
#include <yaul/variant/get.hpp>

BOOST_AUTO_TEST_CASE(basic)
{
  using namespace txpl::vm;
  using std::is_same;

  typedef basic_types<>::blank_type blank_type;
  typedef basic_types<>::char_type char_type;
  typedef basic_types<>::int_type int_type;
  typedef basic_types<>::bool_type bool_type;
  typedef basic_types<>::real_type real_type;
  typedef basic_types<>::string_type string_type;
  typedef basic_types<>::regex_type regex_type;
  typedef array<> array_type;
  typedef object<> object_type;

  value<> v;

  {
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(v));
    BOOST_CHECK_THROW(yaul::get<char_type>(v), yaul::bad_get);
    BOOST_CHECK_THROW(yaul::get<int_type>(v), yaul::bad_get);
    BOOST_CHECK_THROW(yaul::get<bool_type>(v), yaul::bad_get);
    BOOST_CHECK_THROW(yaul::get<real_type>(v), yaul::bad_get);
    BOOST_CHECK_THROW(yaul::get<string_type>(v), yaul::bad_get);
    BOOST_CHECK_THROW(yaul::get<regex_type>(v), yaul::bad_get);
  }
  {
    char_type x;
    BOOST_CHECK_NO_THROW(v = char_type{'a'});
    BOOST_CHECK_NO_THROW(x = yaul::get<char_type>(v));
    BOOST_CHECK_EQUAL(x, char_type{'a'});
  }
  {
    int_type x;
    BOOST_CHECK_NO_THROW(v = int_type{100});
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(v));
    BOOST_CHECK_EQUAL(x, int_type{100});
  }
  {
    bool_type x;
    BOOST_CHECK_NO_THROW(v = bool_type{true});
    BOOST_CHECK_NO_THROW(x = yaul::get<bool_type>(v));
    BOOST_CHECK_EQUAL(x, bool_type{true});
  }
  {
    real_type x;
    BOOST_CHECK_NO_THROW(v = real_type{.100});
    BOOST_CHECK_NO_THROW(x = yaul::get<real_type>(v));
    BOOST_CHECK_EQUAL(x, real_type{.100});
  }
  {
    string_type x;
    BOOST_CHECK_NO_THROW(v = string_type("xyz"));
    BOOST_CHECK_NO_THROW(x = yaul::get<string_type>(v));
    BOOST_CHECK_EQUAL(x, string_type("xyz"));
  }
  {
    BOOST_CHECK_NO_THROW(v = regex_type());
    BOOST_CHECK_NO_THROW(yaul::get<regex_type>(v));
  }
  {
    array_type x, y;
    char_type c = 'x';
    int_type i = 654;
    y.push_back(value<>(char_type{'a'}));
    y.push_back(value<>(int_type{100}));
    BOOST_CHECK_NO_THROW(v = y);
    BOOST_CHECK_NO_THROW(x = yaul::get<array_type>(v));
    BOOST_CHECK_EQUAL(x.size(), 2);
    BOOST_CHECK_NO_THROW(c = yaul::get<char_type>(x[0]));
    BOOST_CHECK_NO_THROW(i = yaul::get<int_type>(x[1]));
    BOOST_CHECK(c == char_type{'a'});
    BOOST_CHECK(i == int_type{100});
  }
  {
    object_type x, y;
    char_type c = 'x';
    int_type i = 654;
    y["c"] = char_type{'a'};
    y["i"] = int_type{100};
    BOOST_CHECK_NO_THROW(v = y);
    BOOST_CHECK_NO_THROW(x = yaul::get<object_type>(v));
    BOOST_CHECK_EQUAL(x.size(), 2);
    BOOST_CHECK_NO_THROW(c = yaul::get<char_type>(x.at("c")) );
    BOOST_CHECK_NO_THROW(i = yaul::get<int_type>(x.at("i")) );
    BOOST_CHECK(c == 'a');
    BOOST_CHECK(i == 100);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
