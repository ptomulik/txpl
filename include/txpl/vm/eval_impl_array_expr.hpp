// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_array_expr.hpp.hpp

/** // doc: txpl/vm/eval_impl_array_expr.hpp.hpp {{{
 * \file txpl/vm/eval_impl_array_expr.hpp.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_ARRAY_EXPR_HPP
#define TXPL_VM_EVAL_IMPL_ARRAY_EXPR_HPP

#include <txpl/ast/array_expr.hpp>
#include <txpl/vm/eval.hpp>
#include <txpl/vm/array.hpp>
#include <yaul/variant/apply_visitor.hpp>
#include <utility>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::array_expr> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct eval_impl<ast::array_expr<Iterator, Value> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::array_expr<Iterator, Value> node_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::expr_type expr_type;
  /** // doc: expr_list_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::expr_list_type expr_list_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler, typename Range>
  static bool
  apply(node_type const& node, Context const& context, Result& result, Ehandler f, Range const&)
  {
    array<Result> arr;
    for(auto it = node.expr_list.begin(); it != node.expr_list.end(); ++it)
      {
        Result elm;
        if(!eval(*it, context, elm, f)) return false;
        arr.push_back(std::move(elm));
      }
    result = std::move(arr);
    return true;
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_ARRAY_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
