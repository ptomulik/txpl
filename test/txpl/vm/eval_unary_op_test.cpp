// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_eval_unary_op

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_EVAL_UNARY_OP

#include <txpl/vm/eval_unary_op.hpp>
#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/array.hpp>
#include <txpl/vm/object.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/get.hpp>

BOOST_AUTO_TEST_CASE(plus_)
{
  using namespace txpl::vm;
  typedef basic_types<>::char_type   char_type;
  typedef basic_types<>::int_type    int_type;
  typedef basic_types<>::bool_type   bool_type;
  typedef basic_types<>::real_type   real_type;
  typedef basic_types<>::string_type string_type;
  typedef basic_types<>::regex_type  regex_type;
  typedef basic_types<>::blank_type  blank_type;
  typedef array<> array_type;
  typedef object<> object_type;
  value<> r;
  auto op = eval_unary_op<op_t::plus_>(r);
  {
    r = blank_type();
    const value<> v = char_type{'a'};
    BOOST_CHECK(boost::apply_visitor(op, v));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(r));
    BOOST_CHECK(x == +char_type{'a'});
  }
  {
    r = blank_type();
    const value<> v = int_type{100};
    BOOST_CHECK(boost::apply_visitor(op, v));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(r));
    BOOST_CHECK(x == +int_type{100});
  }
  {
    r = blank_type();
    const value<> v = bool_type{true};
    BOOST_CHECK(boost::apply_visitor(op, v));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(r));
    BOOST_CHECK(x == +bool_type{true});
  }
  {
    r = blank_type();
    const value<> v = real_type{.123};
    BOOST_CHECK(boost::apply_visitor(op, v));
    real_type x = real_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<real_type>(r));
    BOOST_CHECK(x == +real_type{.123});
  }
  {
    r = blank_type();
    const value<> v = string_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
  {
    r = blank_type();
    const value<> v = regex_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
  {
    r = blank_type();
    const value<> v = array_type();
    BOOST_CHECK(boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<array_type>(r));
  }
  {
    r = blank_type();
    const value<> v = object_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(minus_)
{
  using namespace txpl::vm;
  typedef basic_types<>::char_type   char_type;
  typedef basic_types<>::int_type    int_type;
  typedef basic_types<>::bool_type   bool_type;
  typedef basic_types<>::real_type   real_type;
  typedef basic_types<>::string_type string_type;
  typedef basic_types<>::regex_type  regex_type;
  typedef basic_types<>::blank_type  blank_type;
  typedef array<> array_type;
  typedef object<> object_type;

  value<> r;
  auto op = eval_unary_op<op_t::minus_>(r);
  {
    r = blank_type();
    const value<> v = char_type{'a'};
    BOOST_CHECK(boost::apply_visitor(op, v));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(r));
    BOOST_CHECK(x == -char_type{'a'});
  }
  {
    r = blank_type();
    const value<> v = int_type{100};
    BOOST_CHECK(boost::apply_visitor(op, v));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(r));
    BOOST_CHECK(x == -int_type{100});
  }
  {
    r = blank_type();
    const value<> v = bool_type{true};
    BOOST_CHECK(boost::apply_visitor(op, v));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(r));
    BOOST_CHECK(x == -bool_type{true});
  }
  {
    r = blank_type();
    const value<> v = real_type{.123};
    BOOST_CHECK(boost::apply_visitor(op, v));
    real_type x = real_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<real_type>(r));
    BOOST_CHECK(x == -real_type{.123});
  }
  {
    r = blank_type();
    const value<> v = string_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
  {
    r = blank_type();
    const value<> v = regex_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
  {
    r = blank_type();
    const value<> v = array_type();
    BOOST_CHECK(boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<array_type>(r));
  }
  {
    r = blank_type();
    const value<> v = object_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(not_)
{
  using namespace txpl::vm;
  typedef basic_types<>::char_type   char_type;
  typedef basic_types<>::int_type    int_type;
  typedef basic_types<>::bool_type   bool_type;
  typedef basic_types<>::real_type   real_type;
  typedef basic_types<>::string_type string_type;
  typedef basic_types<>::regex_type  regex_type;
  typedef basic_types<>::blank_type  blank_type;
  typedef array<> array_type;
  typedef object<> object_type;
  value<> r;
  auto op = eval_unary_op<op_t::not_>(r);
  {
    r = blank_type();
    const value<> v = char_type{'a'};
    BOOST_CHECK(boost::apply_visitor(op, v));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == !char_type{'a'});
  }
  {
    r = blank_type();
    const value<> v = int_type{100};
    BOOST_CHECK(boost::apply_visitor(op, v));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == !int_type{100});
  }
  {
    r = blank_type();
    const value<> v = bool_type{true};
    BOOST_CHECK(boost::apply_visitor(op, v));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == !bool_type{true});
  }
  {
    r = blank_type();
    const value<> v = real_type{.123};
    BOOST_CHECK(boost::apply_visitor(op, v));
    bool_type x = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(r));
    BOOST_CHECK(x == !real_type{.123});
  }
  {
    r = blank_type();
    const value<> v = string_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
  {
    r = blank_type();
    const value<> v = regex_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
  {
    r = blank_type();
    const value<> v = array_type();
    BOOST_CHECK(boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<array_type>(r));
  }
  {
    r = blank_type();
    const value<> v = object_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
BOOST_AUTO_TEST_CASE(neg_)
{
  using namespace txpl::vm;
  typedef basic_types<>::char_type   char_type;
  typedef basic_types<>::int_type    int_type;
  typedef basic_types<>::bool_type   bool_type;
  typedef basic_types<>::real_type   real_type;
  typedef basic_types<>::string_type string_type;
  typedef basic_types<>::regex_type  regex_type;
  typedef basic_types<>::blank_type  blank_type;
  typedef array<> array_type;
  typedef object<> object_type;
  value<> r;
  auto op = eval_unary_op<op_t::neg_>(r);
  {
    r = blank_type();
    const value<> v = char_type{'a'};
    BOOST_CHECK(boost::apply_visitor(op, v));
    int_type x = int_type{'x'};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(r));
    BOOST_CHECK(x == ~char_type{'a'});
  }
  {
    r = blank_type();
    const value<> v = int_type{100};
    BOOST_CHECK(boost::apply_visitor(op, v));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(r));
    BOOST_CHECK(x == ~int_type{100});
  }
  {
    r = blank_type();
    const value<> v = bool_type{true};
    BOOST_CHECK(boost::apply_visitor(op, v));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(r));
    BOOST_CHECK(x == ~bool_type{true});
  }
  {
    r = blank_type();
    const value<> v = real_type{.123};
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
  {
    r = blank_type();
    const value<> v = string_type();
    BOOST_CHECK(~boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
  {
    r = blank_type();
    const value<> v = regex_type();
    BOOST_CHECK(~boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
  {
    r = blank_type();
    const value<> v = array_type();
    BOOST_CHECK(boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<array_type>(r));
  }
  {
    r = blank_type();
    const value<> v = object_type();
    BOOST_CHECK(!boost::apply_visitor(op, v));
    BOOST_CHECK_NO_THROW(boost::get<blank_type>(r));
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
