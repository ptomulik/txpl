Scope {#VmScopeConcept}
=====

Description
-----------

A \ref VmScopeConcept object maps strings to \ref VmSymbolConcept
"symbols". The concept of \ref VmScopeConcept is similar to C++ namespace.
\ref VmSymbolConcept "Symbols" stored in a \ref VmScopeConcept "scope"
represent named entities that get part in a name lookup. Keys of the
\ref VmScopeConcept "scope" map represent symbol names, whereas the mapped
objects are the \ref VmSymbolConcept "symbols" itself.

\ref VmSymbolConcept "Symbols" stored in a \ref VmScopeConcept "scope" are
identified using nested names such as "foo", "::foo", or
"foo::bar". \ref VmSymbolConcept "Scope symbols" may be accessed
using \ref txpl::vm::scope_find() "vm::scope_find()",
\ref txpl::vm::scope_lookup() "vm::scope_lookup()",
\ref txpl::vm::scope_insert() "vm::scope_insert()", and
\ref txpl::vm::scope_erase() "vm::scope_erase()".

Refinement of
-------------

None

Expression requirements
-----------------------

Expression semantics
---------------------

Invariants
----------

Models
------

- \ref txpl::vm::scope "vm::scope<>"

See also
--------

