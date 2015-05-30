// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_operation_impl_14.hpp

/** // doc: txpl/vm/eval_operation_impl_14.hpp {{{
 * \file txpl/vm/eval_operation_impl_14.hpp
 * \brief Defines the \ref txpl::vm::eval_operation_impl_14() "vm::eval_operation_impl_14()"
 */ // }}}
#ifndef TXPL_VM_EVAL_OPERATION_IMPL_14_HPP_INCLUDED
#define TXPL_VM_EVAL_OPERATION_IMPL_14_HPP_INCLUDED

#include <txpl/vm/eval_operation_impl_fwd.hpp>
#include <txpl/vm/op_t.hpp>
#include <txpl/vm/eval_ternary_op.hpp>
#include <yaul/variant/apply_visitor.hpp>

namespace txpl { namespace vm {
/** // doc: eval_operation_impl<14ul> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct eval_operation_impl<14ul>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const* rhs, Ehandler f)
  {
    switch(op)
    {
      case op_t::qmark_:
        if(!yaul::apply_visitor(eval_ternary_op<op_t::qmark_>(lhs), lhs, rhs[0], rhs[1]))
          {
            f("invalid operands to conditional operator '?:'");
            return false;
          }
        break;
      default:
        f("invalid operator for level-14 operation");
        return false;
    }
    return true;
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_OPERATION_IMPL_14_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
