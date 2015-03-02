// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval.hpp

/** // doc: txpl/vm/eval.hpp {{{
 * \file txpl/vm/eval.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_HPP_INCLUDED
#define TXPL_VM_EVAL_HPP_INCLUDED

#include <txpl/vm/eval_impl_fwd.hpp>

namespace txpl { namespace vm {
/** // doc: eval() {{{
 * \todo Write documentation
 */ // }}}
template<typename Node, typename Context, typename Result, typename Ehandler>
bool eval(Node const& node, Context const& context, Result& result, Ehandler eh)
{ return eval_impl<Node>::apply(node, context, result, eh); }
/** // doc: eval() {{{
 * \todo Write documentation
 */ // }}}
template<typename Node, typename Context, typename Result>
bool eval(Node const& node, Context const& context, Result& result)
{ return eval(node, context, result, util::fake_functor<void>()); }
} } // end namespace txpl::vm

#include <txpl/vm/eval_impl.hpp>

#endif /* TXPL_VM_EVAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
