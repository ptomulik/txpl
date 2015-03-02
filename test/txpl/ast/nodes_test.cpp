// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_nodes

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_NODES

#include <txpl/ast/nodes.hpp>
#include <txpl/ast/squash_heads.hpp>

BOOST_AUTO_TEST_CASE(test__literal)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  using boost::get;

  typedef basic_types<>::char_type char_type;
  typedef basic_types<>::int_type int_type;
  typedef basic_types<>::bool_type bool_type;
  typedef basic_types<>::real_type real_type;
  typedef basic_types<>::string_type string_type;
  typedef basic_types<>::regex_type regex_type;

  typedef const char* Iterator; // this should be token iterator in fact

  BOOST_CHECK_NO_THROW(literal<Iterator>());

  {
    char_type x;
    literal<Iterator> l;
    l.value = char_type{'a'};
    BOOST_CHECK_NO_THROW(x = boost::get<char_type>(l.value));
    BOOST_CHECK_EQUAL(x, char_type{'a'});
  }
  {
    int_type x;
    literal<Iterator> l;
    l.value = int_type{123};
    BOOST_CHECK_NO_THROW(x = boost::get<int_type>(l.value));
    BOOST_CHECK_EQUAL(x, int_type{123});
  }
  {
    bool_type x;
    literal<Iterator> l;
    l.value = bool_type{true};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(l.value));
    BOOST_CHECK_EQUAL(x, bool_type{true});
  }
  {
    bool_type x;
    literal<Iterator> l;
    l.value = bool_type{false};
    BOOST_CHECK_NO_THROW(x = boost::get<bool_type>(l.value));
    BOOST_CHECK_EQUAL(x, bool_type{false});
  }
  {
    real_type x;
    literal<Iterator> l;
    l.value = real_type{.123};
    BOOST_CHECK_NO_THROW(x = boost::get<real_type>(l.value));
    BOOST_CHECK_EQUAL(x, real_type{.123});
  }
  {
    string_type x;
    literal<Iterator> l;
    l.value  = string_type("a string");
    BOOST_CHECK_NO_THROW(x = boost::get<string_type>(l.value));
    BOOST_CHECK_EQUAL(x, string_type("a string"));
  }
  {
    regex_type x;
    literal<Iterator> l;
    l.value = regex_type("a regex");
    BOOST_CHECK_NO_THROW(x = boost::get<regex_type>(l.value));
    BOOST_CHECK(std::regex_match("a regex", x));
  }
}

BOOST_AUTO_TEST_CASE(test__name)
{
  using namespace txpl::ast;
  using namespace txpl::vm;

  typedef const char* Iterator; // this should be token iterator in fact

  BOOST_CHECK_NO_THROW(name<Iterator>());
  {
    name<Iterator> n;
    BOOST_CHECK_NO_THROW(n.value = "n1");
    BOOST_CHECK_EQUAL(n.value.size(),2);
  }
}
BOOST_AUTO_TEST_CASE(test__expr_0__literal)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  literal<Iterator> l2;
  literal<Iterator> l1;
  expr<Iterator, basic_types<>, 0ul> e;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    e.attrib = l1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(e.attrib));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l2.value));
    BOOST_CHECK_EQUAL(x, 'a');
  }
}
BOOST_AUTO_TEST_CASE(test__expr_0__name)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  name<Iterator> n2;
  name<Iterator> n1;
  expr<Iterator, basic_types<>, 0ul> e;
  {
    n1.value = "the name";
    e.attrib = n1;
    BOOST_CHECK_NO_THROW(n2 = get<name<Iterator> >(e.attrib));
    BOOST_CHECK_EQUAL(n2.value, "the name");
  }
}
BOOST_AUTO_TEST_CASE(test__expr_0__unary_expr)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  literal<Iterator> l2;
  literal<Iterator> l1;
  expr<Iterator, basic_types<>, 0ul> e;
  unary_expr<Iterator> u1;
  unary_expr<Iterator> u2;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    u1.operator_ = static_cast<op_t>('+');
    u1.expr.attrib = l1;
    e.attrib = u1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(u2 = get<unary_expr<Iterator> >(e.attrib));
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(u2.expr.attrib));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l2.value));
    BOOST_CHECK_EQUAL(x, 'a');
  }
}
BOOST_AUTO_TEST_CASE(test__expr_0__braced_expr)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  literal<Iterator> l2;
  literal<Iterator> l1;
  expr<Iterator, basic_types<>, 0ul> e;
  braced_expr<Iterator> b1;
  braced_expr<Iterator> b2;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    squash_heads(b1.expr) = l1;
    e.attrib = b1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(b2 = get<braced_expr<Iterator> >(e.attrib));
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(squash_heads(b2.expr)));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l2.value));
    BOOST_CHECK_EQUAL(x, 'a');
  }
}
BOOST_AUTO_TEST_CASE(test__unary_expr__literal)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  unary_expr<Iterator> u;
  literal<Iterator> l1;
  literal<Iterator> l2;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    u.operator_ = static_cast<op_t>('-');
    u.expr.attrib = l1;
    char_type x = char_type{'z'};
    BOOST_CHECK_EQUAL(static_cast<int>(u.operator_), '-');
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(u.expr.attrib));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l2.value));
    BOOST_CHECK_EQUAL(x, 'a');
  }
}
BOOST_AUTO_TEST_CASE(test__braced_expr__literal)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  braced_expr<Iterator> b;
  literal<Iterator> l1;
  literal<Iterator> l2;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    squash_heads(b.expr) = l1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(squash_heads(b.expr)));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l2.value));
    BOOST_CHECK_EQUAL(x, 'a');
  }
}
BOOST_AUTO_TEST_CASE(test__expr__literal)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  expr<Iterator> e;
  literal<Iterator> l1;
  literal<Iterator> l2;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    squash_heads(e) = l1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(squash_heads(e)));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l2.value));
    BOOST_CHECK_EQUAL(x, 'a');
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  BOOST_CHECK(true);
}
#endif
