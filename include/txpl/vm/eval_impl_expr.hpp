// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_expr.hpp.hpp

/** // doc: txpl/vm/eval_impl_expr.hpp.hpp {{{
 * \file txpl/vm/eval_impl_expr.hpp.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_EXPR_HPP
#define TXPL_VM_EVAL_IMPL_EXPR_HPP

#include <txpl/ast/nodes.hpp>
#include <txpl/vm/eval.hpp>
#include <boost/variant/apply_visitor.hpp>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::expr<14>> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes, size_t Level>
struct eval_impl<ast::expr<Iterator, BasicTypes, Level> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes, Level> node_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler>
  static bool
  apply(node_type const& node, Context const& context, Result& result, Ehandler ehandler)
  {
    typedef typename node_type::tail_type tail_type;
    typedef typename tail_type::const_iterator tail_iterator;
    Result tmp;
    if(!eval(node.head, context, tmp, ehandler)) return false;
    for(tail_iterator it = node.tail.begin(); it != node.tail.end(); ++it)
      { if(!eval(*it, context, tmp, ehandler)) return false; }
    result = tmp;
    return true;
  }
};
/** // doc: eval_impl<ast::expr<0> > {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct eval_impl<ast::expr<Iterator, BasicTypes, 0ul> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes, 0ul> node_type;
  /** // doc: braced_expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::braced_expr<Iterator, BasicTypes> braced_expr_type;
  /** // doc: unary_expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::unary_expr<Iterator, BasicTypes> unary_expr_type;
  /** // doc: name_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::name<Iterator, BasicTypes> name_type;
  /** // doc: visitor {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler>
  struct visitor
  {
    typedef bool result_type;
    visitor(Context const& c, Result& r, Ehandler e)
      : context(c), result(r), ehandler(e)
    { }
    template<typename Node>
    bool operator()(Node const& node) const
    { return eval(node, context, result, ehandler); }
    Context const& context;
    Result& result;
    Ehandler ehandler;
  };
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler>
  static bool
  apply(node_type const& node, Context const& context, Result& result, Ehandler ehandler)
  {
    auto v = visitor<Context, Result, Ehandler>(context, result, ehandler);
    return boost::apply_visitor(v, node.attrib);
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
