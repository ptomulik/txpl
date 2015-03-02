// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: file txpl/parse1.cpp {{{
 * \file txpl/parse1.cpp
 * \brief Provides parse1.cpp example.
 */ // }}}
/** // doc: example parse1.cpp {{{
 * \example parse1.cpp
 * This example demonstrates how one may use the txpl::parse functions
 * to parse simple mathematical expressions.
 */ // }}}
// [Program]
#include <txpl/lexer/api.hpp>
#include <txpl/parser/api.hpp>
#include <txpl/ast/api.hpp>
#include <iostream>
#include <iterator>
#include <string>
#include <list>
#include <algorithm>

// [Typedefs]
typedef std::string::const_iterator     string_iter;
typedef txpl::lexer::token<string_iter>  token_type;
typedef std::list<token_type>           token_list;
typedef token_list::const_iterator      token_iter;
// [Typedefs]

// [ErrorHandler]
/// Error Handler
struct error_handler
{
  /// Constructor
  error_handler(string_iter s)
    : start(s)
  { }
  /// Handler for parser-level errors
  void
  operator() (token_iter const& first, token_iter const& last, std::string const& msg) const
  {
    if(first != last)
      std::cerr << "at: " << 1 + std::count(start, first->begin(), '\n')
                << ": " << std::string(first->begin(), first->end()) << std::endl;
    else
      std::cerr << "at: eof" << std::endl;
    std::cerr << "error: " << msg << std::endl;
  }
  /// Handler for token-level errors
  void
  operator()(string_iter const& begin, string_iter const& end, std::string const& msg) const
  {
    if(begin != end)
      std::cerr << "at: " << 1 + std::count(start, begin, '\n')
                << ": " << std::string(begin, end) << std::endl;
    else
      std::cerr << "at: eof" << std::endl;
    std::cerr << "error: " << msg << std::endl;
  }
private:
  string_iter start;
};
// [ErrorHandler]

/// Main function
int main(int, char**)
{
  using namespace txpl;
  // [ReadInput]
  // This read stdin until EOF
  std::cin >> std::noskipws;
  std::istream_iterator<char> io_it(std::cin);
  std::istream_iterator<char> io_end;
  std::string str(io_it, io_end);
  // [ReadInput]

  // [Tokenize]
  token_list tokens;
  string_iter s_it = str.cbegin();
  string_iter s_end = str.cend();
  if(!lexer::tokenize(s_it, s_end, tokens))
    {
      string_iter s_next;
      lexer::try_token(s_it, s_end, s_next);
      error_handler(str.cbegin())(s_it, s_next, "invalid token");
      return EXIT_FAILURE;
    }
  // [Tokenize]

  // [Parse]
  token_iter t_it = tokens.cbegin();
  token_iter t_end = tokens.cend();
  ast::expr<token_iter> top;
  if(!parser::parse(t_it, t_end, top, error_handler(str.cbegin())))
    return EXIT_FAILURE;
  if(t_it != t_end)
    {
      error_handler(str.cbegin())(t_it, t_end, "parse error");
      return EXIT_FAILURE;
    }
  std::cout << "expression parsed successfully" << std::endl;
  // [Parse]

  return EXIT_SUCCESS;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
