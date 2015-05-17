// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: file clxx/eval1.cpp {{{
 * \file clxx/eval1.cpp
 * \brief Provides eval1.cpp example.
 */ // }}}
/** // doc: example calc1/parser.cpp {{{
 * \example calc1/parser.cpp
 * This example demonstrates how one may use the txpl::parser functions.
 */ // }}}
// [Code]
#include <txpl/calc1/lexer.hpp>
#include <txpl/calc1/ehandler.hpp>
#include <txpl/parser/parse.hpp>

namespace txpl { namespace calc1 {
bool parse(ast::expr<token_iter>& top, token_list const& tokens, ehandler f)
{
  auto t_it = tokens.cbegin();
  auto t_end = tokens.cend();
  if(!parser::parse(t_it, t_end, top, f))
    return false;
  if(t_it != t_end)
    {
      f(t_it, t_end, "parse error");
      return false;
    }
  return true;
}
} } // end namespace txpl::calc1
// [Code]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
