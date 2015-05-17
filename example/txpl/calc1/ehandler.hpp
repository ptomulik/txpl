// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/calc1/ehandler.hpp

/** // doc: txpl/calc1/ehandler.hpp {{{
 * \file txpl/calc1/ehandler.hpp
 * \todo Write documentation
 */ // }}}
/** // doc: example calc1/ehandler.cpp {{{
 * \example calc1/ehandler.cpp
 * \todo Write documentation
 */ // }}}
// [Code]
#ifndef TXPL_CALC1_EHANDLER_HPP
#define TXPL_CALC1_EHANDLER_HPP

#include <txpl/calc1/lexer.hpp>
#include <string>

namespace txpl { namespace calc1 {
struct ehandler
{
  typedef std::string::const_iterator string_iter;
  /// Constructor
  ehandler(std::string const& input, token_list const& tokens)
    : _input(input), _tokens(tokens)
  {}
  /// Handler for parser-level error
  void operator() (token_iter const& first,
                   token_iter const& last,
                   std::string const& msg) const;
  /// Handler for token-level errors
  void operator() (string_iter const& first,
                   string_iter const& last,
                   std::string const& msg) const;
private:
  std::string const& _input;
  token_list const& _tokens;
};
} } // end namespace txpl::calc1
// [Code]
#endif /* TXPL_CALC1_EHANDLER_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
