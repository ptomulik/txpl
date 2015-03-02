// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/nodes.hpp

/** // doc: txpl/ast/nodes.hpp {{{
 * \file txpl/ast/nodes.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_AST_NODES_HPP_INCLUDED
#define TXPL_AST_NODES_HPP_INCLUDED

#include <txpl/ast/node.hpp>
#include <txpl/ast/nodes_fwd.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/op_t.hpp>
#include <boost/variant.hpp>
#include <boost/variant/recursive_variant.hpp>

#include <list>
#include <string>

// NOTE: AST stands for Abstract Syntax Tree

namespace txpl { namespace ast {
template<typename Iterator, typename BasicTypes>
struct name
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename std::string value_type;
  /** // doc: value {{{
   * \todo Write documentation
   */ // }}}
  value_type value;
  /** // doc: name() {{{
   * \todo Write documentation
   */ // }}}
  name() : base_type() { }
  /** // doc: name() {{{
   * \todo Write documentation
   */ // }}}
  name(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

template<typename Iterator, typename BasicTypes>
struct literal
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::value<BasicTypes> result_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef result_type value_type;
  /** // doc: value {{{
   * \todo Write documentation
   */ // }}}
  value_type value;
  /** // doc: literal() {{{
   * \todo Write documentation
   */ // }}}
  literal() : base_type() { }
  /** // doc: literal() {{{
   * \todo Write documentation
   */ // }}}
  literal(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

template<typename Iterator, typename BasicTypes>
struct unary_expr
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::value<BasicTypes> result_type;
  /** // doc: operator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::op_t operator_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes, 0ul> expr_type;
  /** // doc: operator {{{
   * \todo Write documentation
   */ // }}}
  operator_type operator_;
  /** // doc: expr {{{
   * \todo Write documentation
   */ // }}}
  expr_type expr;
  /** // doc: unary_expr() {{{
   * \todo Write documentation
   */ // }}}
  unary_expr() : base_type() { }
  /** // doc: unary_expr() {{{
   * \todo Write documentation
   */ // }}}
  unary_expr(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

template<typename Iterator, typename BasicTypes, size_t Level>
struct operation
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::value<BasicTypes> result_type;
  /** // doc: operator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::op_t operator_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes, Level> expr_type;
  /** // doc: operator {{{
   * \todo Write documentation
   */ // }}}
  operator_type operator_;
  /** // doc: operand {{{
   * \todo Write documentation
   */ // }}}
  expr_type expr;
  /** // doc: level {{{
   * \todo Write documentation
   */ // }}}
  constexpr static size_t level = Level;
  /** // doc: operation() {{{
   * \todo Write documentation
   */ // }}}
  operation() : base_type() { }
  /** // doc: operation() {{{
   * \todo Write documentation
   */ // }}}
  operation(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

template<typename Iterator, typename BasicTypes>
struct operation<Iterator, BasicTypes, 14ul>
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::value<BasicTypes> result_type;
  /** // doc: operator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::op_t operator_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes> expr_type;
  /** // doc: operator {{{
   * \todo Write documentation
   */ // }}}
  operator_type operator_;
  /** // doc: operand {{{
   * \todo Write documentation
   */ // }}}
  expr_type expr[2];
  /** // doc: level {{{
   * \todo Write documentation
   */ // }}}
  constexpr static size_t level = 14ul;
  /** // doc: operation() {{{
   * \todo Write documentation
   */ // }}}
  operation() : base_type() { }
  /** // doc: operation() {{{
   * \todo Write documentation
   */ // }}}
  operation(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

/** // doc: operation<0> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct operation<Iterator, BasicTypes, 0ul>
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::value<BasicTypes> result_type;
  /** // doc: operator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::op_t operator_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes, 0> expr_type;
  /** // doc: operator {{{
   * \todo Write documentation
   */ // }}}
  operator_type operator_;
  /** // doc: operand {{{
   * \todo Write documentation
   */ // }}}
  expr_type expr;
  /** // doc: level {{{
   * \todo Write documentation
   */ // }}}
  constexpr static size_t level = 0ul;
  /** // doc: operation() {{{
   * \todo Write documentation
   */ // }}}
  operation() : base_type() { }
  /** // doc: operation() {{{
   * \todo Write documentation
   */ // }}}
  operation(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

template<typename Iterator, typename BasicTypes, size_t Level>
struct expr
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::value<BasicTypes> result_type;
  /** // doc: head_type {{{
   * \todo Write documentation
   */ // }}}
  typedef expr<Iterator, BasicTypes, Level-1> head_type;
  /** // doc: tail_type {{{
   * \todo Write documentation
   */ // }}}
  typedef std::list<operation<Iterator, BasicTypes, Level-1> > tail_type;
  /** // doc: head {{{
   * \todo Write documentation
   */ // }}}
  head_type head;
  /** // doc: tail {{{
   * \todo Write documentation
   */ // }}}
  tail_type tail;
  /** // doc: level {{{
   * \todo Write documentation
   */ // }}}
  constexpr static size_t level = Level;
  /** // doc: expr() {{{
   * \todo Write documentation
   */ // }}}
  expr() : base_type() { }
  /** // doc: expr() {{{
   * \todo Write documentation
   */ // }}}
  expr(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

/** // doc: expr<5> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct expr<Iterator, BasicTypes, 5ul>
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::value<BasicTypes> result_type;
  /** // doc: head_type {{{
   * \todo Write documentation
   */ // }}}
  typedef expr<Iterator, BasicTypes, 0ul> head_type;
  /** // doc: tail_type {{{
   * \todo Write documentation
   */ // }}}
  typedef std::list<operation<Iterator, BasicTypes, 0ul> > tail_type;
  /** // doc: head {{{
   * \todo Write documentation
   */ // }}}
  head_type head;
  /** // doc: tail {{{
   * \todo Write documentation
   */ // }}}
  tail_type tail;
  /** // doc: level {{{
   * \todo Write documentation
   */ // }}}
  constexpr static size_t level = 5ul;
  /** // doc: expr() {{{
   * \todo Write documentation
   */ // }}}
  expr() : base_type() { }
  /** // doc: expr() {{{
   * \todo Write documentation
   */ // }}}
  expr(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

/** // doc: expr<0> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct expr<Iterator, BasicTypes, 0ul>
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::value<BasicTypes> result_type;
  /** // doc: attrib_type {{{
   * \todo Write documentation
   */ // }}}
  typedef boost::variant<
    literal<Iterator, BasicTypes>
  , name<Iterator, BasicTypes>
  , boost::recursive_wrapper<unary_expr<Iterator, BasicTypes> >
  , boost::recursive_wrapper<braced_expr<Iterator, BasicTypes> >
  > attrib_type;
  /** // doc: tail_type {{{
   * \todo Write documentation
   */ // }}}
  typedef void tail_type;
  /** doc: attrib {{{
   * \todo Write documentation
   */ // }}}
  attrib_type attrib;
  /** // doc: level {{{
   * \todo Write documentation
   */ // }}}
  constexpr static size_t level = 0;
  /** // doc: expr() {{{
   * \todo Write documentation
   */ // }}}
  expr() : base_type() { }
  /** // doc: expr() {{{
   * \todo Write documentation
   */ // }}}
  expr(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

template<typename Iterator, typename BasicTypes>
struct braced_expr
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \todo Write documentation
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef vm::value<BasicTypes> result_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes> expr_type;
  /** // doc: expr {{{
   * \todo Write documentation
   */ // }}}
  expr_type expr;
  /** // doc: braced_expr() {{{
   * \todo Write documentation
   */ // }}}
  braced_expr() : base_type() { }
  /** // doc: braced_expr() {{{
   * \todo Write documentation
   */ // }}}
  braced_expr(Iterator const& begin, Iterator const& end)
    : base_type(begin, end)
  { }
};

} } // end namespace ast

#endif /* TXPL_AST_NODES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
