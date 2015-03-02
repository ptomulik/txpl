// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_operation.hpp

/** // doc: txpl/vm/eval_operation.hpp {{{
 * \file txpl/vm/eval_operation.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_OPERATION_HPP_INCLUDED
#define TXPL_VM_EVAL_OPERATION_HPP_INCLUDED

#include <txpl/vm/op_t.hpp>
#include <txpl/vm/eval_binary_op.hpp>
#include <txpl/vm/eval_ternary_op.hpp>
#include <boost/variant/apply_visitor.hpp>

namespace txpl { namespace vm {
/** // doc: eval_operation_impl<Level> {{{
 * \todo Write documentation
 */ // }}}
template<size_t Level, typename BasicTypes>
struct eval_operation_impl;
/** // doc: eval_operation_impl<14ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<14ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const* rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::qmark_:
        if(!boost::apply_visitor(eval_ternary_op<op_t::qmark_, BasicTypes>(lhs), lhs, rhs[0], rhs[1]))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'or'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-13 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<13ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<13ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::or_:
        if(!boost::apply_visitor(eval_binary_op<op_t::or_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'or'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-13 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<12ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<12ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::and_:
        if(!boost::apply_visitor(eval_binary_op<op_t::and_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'and'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-12 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<11ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<11ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::bitor_:
        if(!boost::apply_visitor(eval_binary_op<op_t::bitor_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'bitor'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-11 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<10ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<10ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::xor_:
        if(!boost::apply_visitor(eval_binary_op<op_t::xor_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'xor'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-10 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<9ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<9ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::bitand_:
        if(!boost::apply_visitor(eval_binary_op<op_t::bitand_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'bitand'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-9 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<8ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<8ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::eq_:
        if(!boost::apply_visitor(eval_binary_op<op_t::eq_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'eq'");
          return false;
        }
        break;
      case op_t::neq_:
        if(!boost::apply_visitor(eval_binary_op<op_t::neq_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'neq'");
          return false;
        }
        break;
      case op_t::match_:
        if(!boost::apply_visitor(eval_binary_op<op_t::match_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'match'");
          return false;
        }
        break;
      case op_t::nmatch_:
        if(!boost::apply_visitor(eval_binary_op<op_t::nmatch_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'nmatch'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-8 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<7ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<7ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::lt_:
        if(!boost::apply_visitor(eval_binary_op<op_t::lt_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'lt'");
          return false;
        }
        break;
      case op_t::gt_:
        if(!boost::apply_visitor(eval_binary_op<op_t::gt_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'gt'");
          return false;
        }
        break;
      case op_t::le_:
        if(!boost::apply_visitor(eval_binary_op<op_t::le_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'le'");
          return false;
        }
        break;
      case op_t::ge_:
        if(!boost::apply_visitor(eval_binary_op<op_t::ge_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'ge'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-7 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<6ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<6ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::lshift_:
        if(!boost::apply_visitor(eval_binary_op<op_t::lshift_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'lshift'");
          return false;
        }
        break;
      case op_t::rshift_:
        if(!boost::apply_visitor(eval_binary_op<op_t::rshift_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'rshift'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-6 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<5ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<5ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::plus_:
        if(!boost::apply_visitor(eval_binary_op<op_t::plus_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'plus'");
          return false;
        }
        break;
      case op_t::minus_:
        if(!boost::apply_visitor(eval_binary_op<op_t::minus_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'minus'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-5 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation_impl<0ul, BasicTypes> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct eval_operation_impl<0ul, BasicTypes>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Lhs, typename Rhs, typename Ehandler>
  static bool
  apply(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& /* ehandler */)
  {
    switch(op)
    {
      case op_t::mul_:
        if(!boost::apply_visitor(eval_binary_op<op_t::mul_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'mul'");
          return false;
        }
        break;
      case op_t::div_:
        if(!boost::apply_visitor(eval_binary_op<op_t::div_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'div'");
          return false;
        }
        break;
      case op_t::mod_:
        if(!boost::apply_visitor(eval_binary_op<op_t::mod_, BasicTypes>(lhs), lhs, rhs))
        {
          // FIXME: invoke error handler:
          // ehandler("invalid operands to binary operator 'mod'");
          return false;
        }
        break;
      default:
        // FIXME: invoke error handler:
        // ehandler("invalid operator for level-0 operation");
        return false;
    }
    return true;
  }
};
/** // doc: eval_operation<N>() {{{
 * \todo Write documentation
 */ // }}}
template<size_t Level, typename BasicTypes, typename Lhs, typename Rhs, typename Ehandler>
bool eval_operation(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler& eh)
{
  return eval_operation_impl<Level, BasicTypes>::apply(op, lhs, rhs, eh);
}
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_OPERATION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
