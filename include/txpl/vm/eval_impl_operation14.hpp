// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_operation14.hpp

/** // doc: txpl/vm/eval_impl_operation14.hpp {{{
 * \file txpl/vm/eval_impl_operation14.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_OPERATION14_HPP
#define TXPL_VM_EVAL_IMPL_OPERATION14_HPP

#include <txpl/vm/eval_impl_fwd.hpp>
#include <txpl/ast/operation.hpp>
#include <txpl/vm/eval.hpp>
#include <txpl/vm/eval_operation.hpp>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::operation<14ul>> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct eval_impl<ast::operation<Iterator, Value, 14ul> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::operation<Iterator, Value, 14ul> node_type;
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
  apply(node_type const& node, Context const& context, Result& result, Ehandler f, Range const& range)
  {
    Result rhs[2];
    if(!eval(node.expr[0], context, rhs[0], f)) return false;
    if(node.operator_ == '?')
      {
        if(!eval(node.expr[1], context, rhs[1], f)) return false;
      }
    auto ff = [f, range](std::string const& s) { f(range.begin(), range.end(), s); };
    return eval_operation<14ul>(node.operator_, result, rhs, ff);
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_OPERATION14_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
