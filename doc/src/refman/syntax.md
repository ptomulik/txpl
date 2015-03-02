Expression Syntax {#ExpressionSyntax}
=================

This page defines the syntax implemented in \ref ParserGroup "parser" and
\ref LexerGroup "lexer". The syntax definition is split onto two groups of
rules -- those implemented in parser and those implemented in lexer.

## Parser rules ##

\anchor ExpressionSyntaxParserRules

Non-terminal symbols are marked with italics (e.g. *expr*). Terminal
symbols are marked with true-type (e.g. ``real``). Verbatim literals are
enclosed in single quotes (e.g. ``':'``).

*expr*   :=  *expr15*

*expr15* :=  *expr14* &nbsp; ( ``'?'`` *expr* ``':'`` &nbsp; *expr* )\*

*expr14* :=  *expr13* &nbsp; ( ``'||'`` &nbsp; *expr13* )\*

*expr13* :=  *expr12* &nbsp; ( ``'&&'`` &nbsp; *expr12* )\*

*expr12* :=  *expr11* &nbsp; ( ``'|'``  &nbsp;  *expr11* )\*

*expr11* :=  *expr10* &nbsp; ( ``'^'``  &nbsp; *expr10* )\*

*expr10* :=  *expr9* &nbsp; ( ``'&'``   &nbsp; *expr9* )\*

*expr9*  :=  *expr8* &nbsp; ( (``'=='`` | ``'!='`` | ``'=~'`` | ``'!~'``) &nbsp; *expr8* )\*

*expr8*  :=  *expr7* &nbsp; ( (``'<'`` | ``'>'`` | ``'<='`` | ``'>='``) &nbsp; *expr7* )\*

*expr7*  :=  *expr6* &nbsp; ( (``'<<'`` | ``'>>'``) &nbsp; *expr6* )\*

*expr6*  :=  *expr5* &nbsp; ( (``'+'`` | ``'-'``) &nbsp; *expr5* )\*

*expr5*  :=  *expr3* &nbsp; ( (``'*'`` | ``'/'`` | ``'%'``) &nbsp; *expr3* )\*

*expr3*  := *unary_expr* | *expr2*

*expr2*  := *expr0* &nbsp; ( ``'['`` *expr* ``']'`` )\*

*expr0*  :=  *braced_expr* | *array_expr* | *dict_expr* | *literal* | *symbol*

*braced_expr* := ``'('`` *expr* ``')'``

*array_expr*  := ``'['`` ( *expr* &nbsp; ( ``','`` *expr* )\* )? ``']'``

*dict_expr*   := ``'{'`` ( *dict_pair* &nbsp; ( ``','`` *dict_pair* )\* )? ``'}'``

*dict_pair*   := ``qstring`` ``':'`` *expr* 

*unary_expr*  := (``'+'`` | ``'-'`` | ``'!'`` | ``'~'``) &nbsp; *expr0*

*symbol*  := ``word`` ( ``'::'`` ``word`` )\*

*literal* :=  ``'true'`` | ``'false'`` |  ``int`` | ``real`` | ``qchar`` | ``qstring`` | ``qregex``

### Notes ###

1. The numbers appearing after the *expr* prefix correspond to the precedence
   of a given expression type. The higher is the number, the lower is the
   corresponding precedence. These precedence levels are taken from 
   <a href="http://en.cppreference.com/w/cpp/language/operator_precedence">cppreference</a>
   page. Note, that the particular numbers are not standardized by the C++
   committee.
2. Only a subset of C++ operators is implemented in TXPL.

## Lexer rules ##

\anchor ExpressionSyntaxLexerRules

Non-terminal lexer symbols are marked in italics (e.g. *qchar*). The syntax
is specified via regular expressions. The strings in <em>italics</em> appearing
inside the regular expressions should be interpreted as a subexpressions
defined by other productions. Note, that parser's terminal symbols appear here
as non-terminals.

*word*        ~ ``[_a-zA-Z][_0-9a-zA-Z]*``

*int*         ~ (<em>oct-number</em>``|``<em>dec-number</em>``|``<em>hex-number</em>)

*oct-number*  ~ ``0[0-7]+``

*dec-number*  ~ ``[0-9]+``

*hex-number*  ~ ``0[xX][0-9a-fA-F]+``

*real*        ~ ``([0-9]+((\.([0-9]+)|(``<em>exp</em>``))|(``<em>exp</em>``))|(\.[0-9]+(``<em>exp</em>``)?))``

*exp*         ~ ``[eE][+-]?[0-9]+``

*qchar*       ~ ``'``<em>char</em>``'``

*qstring*     ~ ``&quot;``(<em>char</em>)\*``&quot;``

*char*        ~ ``(``<em>escape</em>``|``<em>cprint</em>``)``

*escape*      ~ ``\\(([0-7]{1-3})|([xX][0-9a-fA-F]+)|(["'?\\abfnrtv]))``

*cprint*      ~ ``[\x20-\x21\x23-\x5B\x5D-\x7E]``

*qregex*      ~ ``(r|b|x|a|g|e)&quot;``(<em>regex-char</em>)\*``&quot;(i|c|ic|ci)?``

*regex-char*  ~ ``(\\"|[^"])``


### Notes ###

1. The <em>cprint</em> represent any printable character except ``"`` (double
   quote) and ``\`` (backslash).
2. The <em>regex-char</em> is either an escape sequence for the double quote
   (``"``) or a single character. Other possible escape sequences are not
   interpreted by the TXPL scanner but they may be interpreted internally by a
   regular expression compiler.
