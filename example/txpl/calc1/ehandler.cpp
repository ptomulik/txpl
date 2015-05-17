// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/calc1/ehandler.cpp

/** // doc: txpl/calc1/ehandler.cpp {{{
 * \file txpl/calc1/ehandler.cpp
 * \todo Write documentation
 */ // }}}
/** // doc: example calc1/ehandler.cpp {{{
 * \example calc1/ehandler.cpp
 * \todo Write documentation
 */ // }}}
// [Code]
#include <txpl/calc1/ehandler.hpp>
#include <iostream>
#include <string>
#include <algorithm>

namespace txpl { namespace calc1 {
void ehandler::
operator() (token_iter const& first, token_iter const& last, std::string const& msg) const
{
  if(first == last)
    std::cerr << "at: eof" << std::endl;
  else
    {
      token_iter it = last;
      std::cerr << "at: " << 1 + std::count(_input.begin(), first->begin(), '\n') << ": ";
      std::cerr << std::string(first->begin(), (--it)->end()) << std::endl;
    }
  std::cerr << "error: " << msg << std::endl;
}
void ehandler::
operator() (string_iter const& first, string_iter const& last, std::string const& msg) const
{
  if(first == last)
    std::cerr << "at: eof" << std::endl;
  else
    {
      std::cerr << "at: " << 1 + std::count(_input.begin(), first, '\n') << ": ";
      std::cerr << std::string(first, last) << std::endl;
    }
  std::cerr << "error: " << msg << std::endl;
}
} } // end namespace txpl::calc1
// [Code]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
