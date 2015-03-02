// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: file txpl/calc1/lexer.cpp {{{
 * \file txpl/calc1/lexer.cpp
 * \brief Provides eval1.cpp example.
 */ // }}}
/** // doc: example calc1/lexer.cpp {{{
 * \example calc1/lexer.cpp
 * This example demonstrates how one may use the txpl::eval functions
 * to parse simple mathematical expressions and clxx.
 */ // }}}
// [Code]
#include <txpl/calc1/lexer.hpp>
#include <txpl/calc1/ehandler.hpp>
#include <txpl/lexer/tokenize.hpp>

namespace txpl { namespace calc1 {
bool tokenize(token_list& tokens, std::string const& str, ehandler f)
{
  using namespace txpl;
  // [Tokenize]
  auto s_it = str.cbegin();
  auto s_end = str.cend();
  if(!lexer::tokenize(s_it, s_end, tokens))
    {
      std::string::const_iterator s_next;
      lexer::try_token(s_it, s_end, s_next);
      f(s_it, s_next, "invalid token");
      return false;
    }
  return true;
  // [Tokenize]
}
} } // end namespace txpl::calc1
// [Code]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
