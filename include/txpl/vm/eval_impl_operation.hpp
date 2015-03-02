// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_operation.hpp.hpp

/** // doc: txpl/vm/eval_impl_operation.hpp.hpp {{{
 * \file txpl/vm/eval_impl_operation.hpp.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_OPERATION_HPP
#define TXPL_VM_EVAL_IMPL_OPERATION_HPP

#include <txpl/ast/operation.hpp>
#include <txpl/vm/eval.hpp>
#include <txpl/vm/eval_operation.hpp>
#include <string>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::operation<Level>> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value, size_t Level>
struct eval_impl<ast::operation<Iterator, Value, Level> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::operation<Iterator, Value, Level> node_type;
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
    Result rhs;
    if(!eval(node.expr, context, rhs, f)) return false;
    auto ff = [f, range](std::string const& s) { f(range.begin(), range.end(), s); };
    return eval_operation<Level>(node.operator_, result, rhs, ff);
  }
};
} } // end namespace txpl::vm

#include <txpl/vm/eval_impl_operation14.hpp>

#endif /* TXPL_VM_EVAL_IMPL_OPERATION_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
