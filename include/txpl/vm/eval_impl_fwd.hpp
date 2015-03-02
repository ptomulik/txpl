// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_fwd.hpp

/** // doc: txpl/vm/eval_impl_fwd.hpp {{{
 * \file txpl/vm/eval_impl_fwd.hpp
 * \brief Provides forward declaration of the \ref txpl::vm::eval_impl "vm::eval_impl<>"
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_FWD_HPP
#define TXPL_VM_EVAL_IMPL_FWD_HPP

namespace txpl { namespace vm {
/** // doc: eval_impl {{{
 * \ingroup VmGroup
 * \brief Implements \ref txpl::vm::eval() "vm::eval()" for a particular node
 *
 * \tparam Node type of the abstract syntax tree (AST) node evaluated by
 *              a particular specialization of the
 *              \ref txpl::vm::eval_impl "vm::eval_impl<>" template
 *
 *  Specializations of the \ref txpl::vm::eval_impl "vm::eval_impl<>" shall
 *  define a static method `apply()` with the following prototype
 *
 *  \code
 *    template<typename Conext, typename Value, typename Ehandler>
 *    static bool apply(Node const& node, Context const& context, Value& result, Ehandler f);
 *  \endcode
 *
 *  The method should implement the evaluation algorithm for a given Node type.
 *  The arguments \e node, \e context, \e result and \e f are passed directly
 *  from \ref txpl::vm::eval() "vm::eval()" function.
 */ // }}}
template<typename Node> struct eval_impl;
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_FWD_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
