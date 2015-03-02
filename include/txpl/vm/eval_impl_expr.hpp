// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_expr.hpp

/** // doc: txpl/vm/eval_impl_expr.hpp {{{
 * \file txpl/vm/eval_impl_expr.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_EXPR_HPP
#define TXPL_VM_EVAL_IMPL_EXPR_HPP

#include <txpl/ast/expr.hpp>
#include <txpl/vm/eval_impl_fwd.hpp>
#include <txpl/vm/eval.hpp>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::expr<> > {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value, size_t Level>
struct eval_impl<ast::expr<Iterator, Value, Level> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, Value, Level> node_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler, typename Range>
  static bool
  apply(node_type const& node, Context const& context, Result& result, Ehandler f, Range const&)
  {
    typedef typename node_type::tail_type tail_type;
    typedef typename tail_type::const_iterator tail_iterator;
    Result tmp;
    if(!eval(node.head, context, tmp, f)) return false;
    for(tail_iterator it = node.tail.begin(); it != node.tail.end(); ++it)
      { if(!eval(*it, context, tmp, f, node.range)) return false; }
    result = tmp;
    return true;
  }
};
} } // end namespace txpl::vm

#include <txpl/vm/eval_impl_expr3.hpp>
#include <txpl/vm/eval_impl_expr0.hpp>

#endif /* TXPL_VM_EVAL_IMPL_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
