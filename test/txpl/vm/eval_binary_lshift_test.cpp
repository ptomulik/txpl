// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_eval_binary_lshift

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_EVAL_BINARY_LSHIFT

#include <txpl/vm/eval_binary_op.hpp>
#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/value.hpp>
#include <yaul/variant/apply_visitor.hpp>
#include <yaul/variant/get.hpp>

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

BOOST_AUTO_TEST_CASE(char__lshift__char)
{
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} << char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(char__lshift__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} << int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(char__lshift__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} << bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(char__lshift__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__lshift__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__lshift__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__lshift__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__lshift__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(int__lshift__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (int_type{0} << char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(int__lshift__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = int_type{0x1700};
    const value<> v2 = int_type{1};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (int_type{0x1700} << int_type{1}));
  }
}
BOOST_AUTO_TEST_CASE(int__lshift__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (int_type{0} << bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(int__lshift__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__lshift__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__lshift__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__lshift__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__lshift__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(bool__lshift__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (char_type{false} << bool_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(bool__lshift__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (bool_type{false} << int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(bool__lshift__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (bool_type{false} << bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(bool__lshift__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__lshift__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__lshift__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__lshift__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__lshift__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(real__lshift__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__lshift__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__lshift__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__lshift__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__lshift__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__lshift__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__lshift__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__lshift__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(string__lshift__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__lshift__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__lshift__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__lshift__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__lshift__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__lshift__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__lshift__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__lshift__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(regex__lshift__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__lshift__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__lshift__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__lshift__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__lshift__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__lshift__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__lshift__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__lshift__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(array__lshift__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__lshift__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__lshift__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__lshift__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__lshift__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__lshift__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__lshift__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<array_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__lshift__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(object__lshift__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__lshift__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__lshift__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__lshift__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__lshift__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__lshift__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__lshift__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__lshift__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::lshift_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
