// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_operation_impl_fwd.hpp

/** // doc: txpl/vm/eval_operation_impl_fwd.hpp {{{
 * \file txpl/vm/eval_operation_impl_fwd.hpp
 * \brief Defines the \ref txpl::vm::eval_operation_impl_fwd() "vm::eval_operation_impl_fwd()"
 */ // }}}
#ifndef TXPL_VM_EVAL_OPERATION_IMPL_FWD_HPP_INCLUDED
#define TXPL_VM_EVAL_OPERATION_IMPL_FWD_HPP_INCLUDED

#include <txpl/vm/op_t.hpp>
#include <txpl/vm/eval_binary_op.hpp>
#include <txpl/vm/eval_ternary_op.hpp>
#include <yaul/variant/apply_visitor.hpp>

namespace txpl { namespace vm {
/** // doc: eval_operation_impl<Level> {{{
 * \todo Write documentation
 */ // }}}
template<size_t Level>
struct eval_operation_impl;
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_OPERATION_IMPL_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
