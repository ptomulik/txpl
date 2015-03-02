// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_unary_expr.hpp.hpp

/** // doc: txpl/vm/eval_impl_unary_expr.hpp.hpp {{{
 * \file txpl/vm/eval_impl_unary_expr.hpp.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_UNARY_EXPR_HPP
#define TXPL_VM_EVAL_IMPL_UNARY_EXPR_HPP

#include <txpl/ast/unary_expr.hpp>
#include <txpl/vm/eval.hpp>
#include <txpl/vm/eval_unary_op.hpp>
#include <boost/variant/apply_visitor.hpp>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::unary_expr> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct eval_impl<ast::unary_expr<Iterator, Value> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::unary_expr<Iterator, Value> node_type;
  /** // doc: operator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::operator_type operator_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::expr_type expr_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler, typename Range>
  static bool
  apply(node_type const& node, Context const& context, Result& result, Ehandler f, Range const&)
  {
    Result subresult;
    if(!eval(node.expr, context, subresult, f)) return false;
    auto ff = [f, node] (std::string const& s) { f(node.begin(), node.end(), s); };
    switch(node.operator_)
      {
        case op_t::plus_:
          if(!boost::apply_visitor(eval_unary_op<op_t::plus_>(result), subresult))
            {
              ff("wrong type argument to unary operator '+'");
              return false;
            }
          break;
        case op_t::minus_:
          if(!boost::apply_visitor(eval_unary_op<op_t::minus_>(result), subresult))
            {
              ff("wrong type argument to unary operator '-'");
              return false;
            }
          break;
        case op_t::not_:
          if(!boost::apply_visitor(eval_unary_op<op_t::not_>(result), subresult))
            {
              ff("wrong type argument to unary operator '!'");
              return false;
            }
          break;
        case op_t::neg_:
          if(!boost::apply_visitor(eval_unary_op<op_t::neg_>(result), subresult))
            {
              ff("wrong type argument to unary operator '~'");
              return false;
            }
          break;
        default:
          return false;
      }
    return true;
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_UNARY_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
