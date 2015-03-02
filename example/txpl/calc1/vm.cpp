// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: file txpl/calc1/vm.cpp {{{
 * \file txpl/calc1/vm.cpp
 * \brief Provides calc1/vm.cpp example.
 */ // }}}
/** // doc: example calc1/vm.cpp {{{
 * \example calc1/vm.cpp
 * \todo Write documentation
 */ // }}}
// [Code]
#include <txpl/calc1/vm.hpp>
#include <txpl/vm/eval.hpp>
#include <txpl/vm/context.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/dump.hpp>

namespace txpl { namespace calc1 {
bool eval(ast::expr<token_iter> const& top, ehandler f)
{
  // [Eval]
  vm::context<> ctx;
  vm::value<> res;
  if(!vm::eval(top, ctx, res, f)) return EXIT_FAILURE;
  // [Eval]
  vm::dump(std::cout, res) << std::endl;
  return true;
}
} } // end namespace txpl::calc1
// [Code]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
