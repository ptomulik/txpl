// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_symbol.hpp.hpp

/** // doc: txpl/vm/eval_impl_symbol.hpp.hpp {{{
 * \file txpl/vm/eval_impl_symbol.hpp.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_SYMBOL_HPP
#define TXPL_VM_EVAL_IMPL_SYMBOL_HPP

#include <txpl/ast/symbol.hpp>
#include <txpl/vm/scope_lookup.hpp>
#include <yaul/variant/get.hpp>
#include <string>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::symbol> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
struct eval_impl<ast::symbol<Iterator> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::symbol<Iterator> node_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Value, typename Ehandler, typename Range>
  static bool
  apply(node_type const& node, Context const& context, Value& res, Ehandler f, Range const&)
  {
    typename Context::symbol_type sym;
    auto ff = [f, node] (std::string const& s) { f(node.begin(), node.end(), s); };
    if(!scope_lookup(context.global_scope, context.current_scope, node.name, sym, ff))
      return false;
    Value *vp = yaul::get<Value>(&sym);
    if(!vp)
      {
        // FIXME: once the type names get implemented, this message should be
        // precisely state what was the destination type.
        ff(node.name + " is not a value");
        return false;
      }
    res = *vp;
    return true;
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_SYMBOL_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
