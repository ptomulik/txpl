// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_expr3.hpp

/** // doc: txpl/vm/eval_impl_expr3.hpp {{{
 * \file txpl/vm/eval_impl_expr3.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_EXPR3_HPP
#define TXPL_VM_EVAL_IMPL_EXPR3_HPP

#include <txpl/ast/expr3.hpp>
#include <txpl/vm/eval_impl_fwd.hpp>
#include <txpl/vm/eval_variant.hpp>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::expr<3> > {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct eval_impl<ast::expr<Iterator, Value, 3ul> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, Value, 3ul> node_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler, typename Range>
  static bool
  apply(node_type const& node, Context const& context, Result& result, Ehandler f, Range const&)
  { return boost::apply_visitor(eval_variant(context, result, f), node.expr); }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_EXPR3_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
