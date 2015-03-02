// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_eval_binary_or

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_EVAL_BINARY_OR

#include <txpl/vm/eval_binary_op.hpp>
#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/value.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/get.hpp>

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

BOOST_AUTO_TEST_CASE(char__or__char)
{
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} || char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(char__or__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} || int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(char__or__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} || bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(char__or__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} || real_type{0.0}));
  }
}
BOOST_AUTO_TEST_CASE(char__or__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__or__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__or__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__or__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(int__or__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (int_type{0} || char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(int__or__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (int_type{0} || int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(int__or__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (int_type{0} || bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(int__or__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (int_type{0} || real_type{0.0}));
  }
}
BOOST_AUTO_TEST_CASE(int__or__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__or__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__or__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__or__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(bool__or__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (char_type{false} || bool_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(bool__or__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{false} || int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(bool__or__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{false} || bool_type{false}));
  }
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = bool_type{true};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{false};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{false} || bool_type{true}));
  }
  {
    const value<> v1 = bool_type{true};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{false};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{true} || bool_type{false}));
  }
  {
    const value<> v1 = bool_type{true};
    const value<> v2 = bool_type{true};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{false};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{true} || bool_type{true}));
  }
}
BOOST_AUTO_TEST_CASE(bool__or__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (bool_type{false} || bool_type{0.0}));
  }
}
BOOST_AUTO_TEST_CASE(bool__or__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__or__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__or__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__or__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(real__or__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (real_type{0.0} || char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(real__or__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (real_type{0.0} || int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(real__or__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (real_type{0.0} || bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(real__or__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == (real_type{0.0} || real_type{0.0}));
  }
}
BOOST_AUTO_TEST_CASE(real__or__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__or__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__or__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__or__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(string__or__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__or__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__or__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__or__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__or__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__or__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__or__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__or__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(regex__or__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__or__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__or__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__or__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__or__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__or__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__or__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__or__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(array__or__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__or__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__or__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__or__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__or__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__or__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__or__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<array_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__or__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(object__or__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__or__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__or__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__or__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__or__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__or__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__or__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!boost::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__or__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::or_>(r);
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
