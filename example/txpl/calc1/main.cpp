// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: file txpl/calc1/main.cpp {{{
 * \file txpl/calc1/main.cpp
 * \brief Provides calc1/main.cpp example.
 */ // }}}
/** // doc: example eval1.cpp {{{
 * \example calc1/main.cpp
 * \todo Write documentation
 */ // }}}
// [Code]
#include <txpl/calc1/lexer.hpp>
#include <txpl/calc1/ehandler.hpp>
#include <txpl/calc1/parser.hpp>
#include <txpl/calc1/vm.hpp>
#include <txpl/ast/expr.hpp>

/// Main function
int main(int, char**)
{
  using namespace txpl::calc1;

  // [ReadInput]
  // This read stdin until EOF
  std::cin >> std::noskipws;
  std::istream_iterator<char> io_it(std::cin);
  std::istream_iterator<char> io_end;
  std::string str(io_it, io_end);
  // [ReadInput]

  token_list tokens;
  ehandler f(str, tokens);
  txpl::ast::expr<token_iter> top;

  if(!tokenize(tokens, str, f)) return EXIT_FAILURE;
  if(!parse(top, tokens, f))    return EXIT_FAILURE;
  if(!eval(top, f))             return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
// [Code]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
