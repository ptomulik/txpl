// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_eval_binary_bitand

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_EVAL_BINARY_BITAND

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

BOOST_AUTO_TEST_CASE(char__bitand__char)
{
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} & char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(char__bitand__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} & int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(char__bitand__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (char_type{'\0'} & bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(char__bitand__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = char_type{'\0'};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__bitand__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__bitand__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__bitand__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(char__bitand__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = char_type{'a'};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(int__bitand__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (int_type{0} & char_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(int__bitand__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = int_type{0x1700};
    const value<> v2 = int_type{0x0134};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (int_type{0x1700} & int_type{0x0134}));
  }
}
BOOST_AUTO_TEST_CASE(int__bitand__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (int_type{0} & bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(int__bitand__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__bitand__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__bitand__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__bitand__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(int__bitand__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = int_type{0};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(bool__bitand__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (char_type{false} & bool_type{'\0'}));
  }
}
BOOST_AUTO_TEST_CASE(bool__bitand__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (bool_type{false} & int_type{0}));
  }
}
BOOST_AUTO_TEST_CASE(bool__bitand__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(r));
    BOOST_CHECK(x == (bool_type{false} & bool_type{false}));
  }
}
BOOST_AUTO_TEST_CASE(bool__bitand__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__bitand__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__bitand__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__bitand__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(bool__bitand__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = bool_type{false};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(real__bitand__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__bitand__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__bitand__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__bitand__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__bitand__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__bitand__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__bitand__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(real__bitand__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = real_type{0.0};
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(string__bitand__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__bitand__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__bitand__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__bitand__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__bitand__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__bitand__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__bitand__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(string__bitand__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = string_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(regex__bitand__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__bitand__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__bitand__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__bitand__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__bitand__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__bitand__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__bitand__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(regex__bitand__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = regex_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(array__bitand__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__bitand__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__bitand__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__bitand__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__bitand__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__bitand__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__bitand__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<array_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(array__bitand__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = array_type();
    const value<> v2 = object_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}

BOOST_AUTO_TEST_CASE(object__bitand__char)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = char_type{'\0'};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__bitand__int)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = int_type{0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__bitand__bool)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = bool_type{false};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__bitand__real)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = real_type{0.0};
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__bitand__string)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = string_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__bitand__regex)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = regex_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__bitand__array)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
  {
    const value<> v1 = object_type();
    const value<> v2 = array_type();
    r = blank_type();
    BOOST_CHECK(!yaul::apply_visitor(op, v1, v2));
    BOOST_CHECK_NO_THROW(yaul::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(object__bitand__object)
{
  using namespace txpl::vm;
  value<> r;
  auto op = eval_binary_op<op_t::bitand_>(r);
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
