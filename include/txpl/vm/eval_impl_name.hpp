// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_name.hpp.hpp

/** // doc: txpl/vm/eval_impl_name.hpp.hpp {{{
 * \file txpl/vm/eval_impl_name.hpp.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_NAME_HPP
#define TXPL_VM_EVAL_IMPL_NAME_HPP

#include <txpl/ast/nodes.hpp>
#include <txpl/vm/scope_lookup.hpp>
#include <boost/variant/get.hpp>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::name> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct eval_impl<ast::name<Iterator, BasicTypes> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::name<Iterator, BasicTypes> node_type;
  /** // doc: string_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::value_type value_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler>
  static bool
  apply(node_type const& node, Context const& context, Result& res, Ehandler)
  {
    typename Context::symbol_type sym;
    // FIXME: implement error handler
    if(!scope_lookup(context.global_scope, context.current_scope, node.value, sym))
      return false;
    Result *rp = boost::get<Result>(&sym);
    if(!rp)
      {
        // FIXME: invoke error handler
        return false;
      }
    res = *rp;
    return true;
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_NAME_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
