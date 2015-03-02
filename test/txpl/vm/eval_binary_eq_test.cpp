// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_eval_binary_eq

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_EVAL_BINARY_EQ

#include <txpl/vm/eval_binary_op.hpp>
#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/value.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/get.hpp>

#include <type_traits>

using namespace txpl::vm;
typedef basic_types<>::char_type   char_type;
typedef basic_types<>::int_type    int_type;
typedef basic_types<>::bool_type   bool_type;
typedef basic_types<>::real_type   real_type;
typedef basic_types<>::string_type string_type;
typedef basic_types<>::regex_type  regex_type;
typedef basic_types<>::blank_type  blank_type;
typedef array<value<> >            array_type;
typedef object<value<> >           object_type;

BOOST_AUTO_TEST_CASE(char__eq__char)
{
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} == char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(char__eq__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} == int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(char__eq__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} == bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(char__eq__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} == real_type{0.0}));
  }
}
BOOST_AUTO_TEST_CASE(char__eq__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__eq__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__eq__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__eq__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(int__eq__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (int_type{0} == char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(int__eq__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (int_type{0} == int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(int__eq__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (int_type{0} == bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(int__eq__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (int_type{0} == real_type{0.0}));
  }
}
BOOST_AUTO_TEST_CASE(int__eq__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__eq__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__eq__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__eq__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(bool__eq__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{false} == bool_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(bool__eq__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{false} == int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(bool__eq__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{false} == bool_type{false}));
  }
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = bool_type{true};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{false};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{false} == bool_type{true}));
  }
  {
    const value<> v1 = bool_type{true};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{false};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{true} == bool_type{false}));
  }
  {
    const value<> v1 = bool_type{true};
    const value<> v2 = bool_type{true};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{false};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{true} == bool_type{true}));
  }
}
BOOST_AUTO_TEST_CASE(bool__eq__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{false} == bool_type{0.0}));
  }
}
BOOST_AUTO_TEST_CASE(bool__eq__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__eq__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__eq__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__eq__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(real__eq__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (real_type{0.0} == char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(real__eq__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (real_type{0.0} == int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(real__eq__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (real_type{0.0} == bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(real__eq__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (real_type{0.0} == real_type{0.0}));
  }
}
BOOST_AUTO_TEST_CASE(real__eq__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__eq__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__eq__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__eq__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(string__eq__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__eq__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__eq__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__eq__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__eq__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = string_type("asd");
    const value<> v2 = string_type("asd");
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{false};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (string_type("asd") == string_type("asd")));
  }
  {
    const value<> v1 = string_type("asd");
    const value<> v2 = string_type("qwe");
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{false};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (string_type("asd") == string_type("qwe")));
  }
}
BOOST_AUTO_TEST_CASE(string__eq__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__eq__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__eq__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(regex__eq__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__eq__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__eq__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__eq__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__eq__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__eq__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__eq__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__eq__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(array__eq__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__eq__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__eq__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__eq__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__eq__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__eq__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__eq__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    array_type x;
    BOOST_CHECK_NO_THROW(x = boost::get<array_type>(r));
    BOOST_CHECK_EQUAL(x.size(), 0);
  }
  {
    array_type a1(3);
    array_type a2(3);
    a2[0] = a1[0] = char_type{'a'};
    a2[1] = a1[1] = int_type{100};
    a2[2] = real_type{321.0}; a1[2] = real_type{.123};
    const value<> v1 = a1;
    const value<> v2 = a2;
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    array_type x;
    BOOST_CHECK_NO_THROW(x = boost::get<array_type>(r));
    BOOST_CHECK_EQUAL(x.size(), 3);
    BOOST_CHECK(boost::get<bool_type>(x[0]));
    BOOST_CHECK(boost::get<bool_type>(x[1]));
    BOOST_CHECK(!boost::get<bool_type>(x[2]));
  }
  {
    array_type a1(3);
    array_type a2(2);
    a2[0] = a1[0] = char_type{'a'};
    a2[1] = a1[1] = int_type{100};
    a1[2] = real_type{.123};
    const value<> v1 = a1;
    const value<> v2 = a2;
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__eq__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(object__eq__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__eq__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__eq__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__eq__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__eq__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__eq__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__eq__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__eq__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::eq_, basic_types<> >(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
