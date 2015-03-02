Basic Types {#BasicTypesConcept}
===========

Description
-----------

The type system used by the \ref AstGroup "abstract syntax tree" and
\ref VmGroup "virtual machine" is based on so called basic types.  Currently
there is seven basic types, as listed below

|     Basic Type   |   Default C++ type |               Description               |   Sample value    |
| ---------------- | ------------------ | --------------------------------------- | ----------------- |
| `blank_type`     | `boost::blank`     | Used to represent uninitialized values  |                   |
| `char_type`      | `char`             | Used to represent single characters     |  `'a'`            |
| `int_type`       | `long`             | Used to represent integral numbers      |  `0x1234`         |
| `bool_type`      | `bool`             | Used to represent boolean values        |  `false`          |
| `real_type`      | `double`           | Used to represent real numbers          |  `0.123e-10`      |
| `string_type`    | `std::string`      | Used to represent strings               |  `"hello world"`  |
| `regex_type`     | `std::regex`       | Used to represent regular expressions   |  `r"match me"`    |

The default mapping between the \ref BasicTypesConcept "basic types" and C++
types is shown in the above table. There is also a concept of
\ref BasicTypesDefinerConcept which establishes actual mapping between
\ref BasicTypesConcept "basic types" and C++ types. This is a customization
point which allows to choose custom C++ types to implement
\ref BasicTypesConcept "basic types" (for example, user may pass custom
\ref BasicTypesDefinerConcept as a template parameter to
\ref txpl::vm::value "vm::value<>" or \ref txpl::ast::value "ast::value<>",
see \ref txpl::vm::basic_types "vm::basic_types<>").

Refinement of
-------------

None

Expression requirements
-----------------------

Quite too much to be mentioned on a single page. The \ref BasicTypesConcept
"basic types" should simply behave same way as their corresponding C++ types.

Expression semantics
---------------------

Quite too much to be mentioned on a single page. The \ref BasicTypesConcept
"basic types" should simply behave same way as their corresponding C++ types.

Invariants
----------

None of the basic types may be an alias to any other.

Models
------

N/A

See also
--------

- \ref BasicTypesDefinerConcept,
- \ref txpl::vm::basic_types "vm::basic_types<>", \ref txpl::vm::value "vm::value<>",
- \ref txpl::ast::basic_types "ast::basic_types<>", \ref txpl::ast::value "ast::value<>".
