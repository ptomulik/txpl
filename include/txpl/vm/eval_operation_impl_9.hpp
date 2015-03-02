// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_operation_impl_9.hpp

/** // doc: txpl/vm/eval_operation_impl_9.hpp {{{
 * \file txpl/vm/eval_operation_impl_9.hpp
 * \brief Defines the \ref txpl::vm::eval_operation_impl_9() "vm::eval_operation_impl_9()"
 */ // }}}
#ifndef TXPL_VM_EVAL_OPERATION_IMPL_9_HPP_INCLUDED
#define TXPL_VM_EVAL_OPERATION_IMPL_9_HPP_INCLUDED

#include <txpl/vm/eval_operation_impl_fwd.hpp>
#include <txpl/vm/op_t.hpp>
#include <txpl/vm/eval_binary_op.hpp>
#include <boost/variant/apply_visitor.hpp>

namespace txpl { namespace vm {
/** // doc: eval_operation_impl<9ul> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct eval_operation_impl<9ul>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler f)
  {
    switch(op)
    {
      case op_t::bitand_:
        if(!boost::apply_visitor(eval_binary_op<op_t::bitand_>(lhs), lhs, rhs))
          {
            f("invalid operands to binary operator '&'");
            return false;
          }
        break;
      default:
        f("invalid operator for level-9 operation");
        return false;
    }
    return true;
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_OPERATION_IMPL_9_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
