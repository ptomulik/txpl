// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_braced_expr.hpp.hpp

/** // doc: txpl/vm/eval_impl_braced_expr.hpp.hpp {{{
 * \file txpl/vm/eval_impl_braced_expr.hpp.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_BRACED_EXPR_HPP
#define TXPL_VM_EVAL_IMPL_BRACED_EXPR_HPP

#include <txpl/ast/braced_expr.hpp>
#include <txpl/vm/eval.hpp>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::braced_expr> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct eval_impl<ast::braced_expr<Iterator, Value> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::braced_expr<Iterator, Value> node_type;
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::expr_type expr_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler, typename Range>
  static bool
  apply(node_type const& node, Context const& context, Result& res, Ehandler f, Range const&)
  { return eval(node.expr, context, res, f); }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_BRACED_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
