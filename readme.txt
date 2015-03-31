README
------
The project deals with development of a lexer and parser for our language

The following are the files and corresponding use
1. lexemes.h - has definition of various tokens
2. lexer.c - The lexer code
3. parse_table.h - The parse table and rule list
4. parser.c - The parser code
5. symbol_table.h - The symbol table code which is populated with requisite data


Data flow
---------

The lexer takes in the input of a source code written in the language, it scans it character by character in order to detect lexemes which are listed as an enum in the lexemes.h file. Once it does, it writes it to a .lexer file which can be read during later processing stages, it also writes into a symbol table (as defined in symbol_table.h) the necessary details when it scans a identifier.

The parser now reads this file and derives a top-down Left most derivation with one lookup. The LL(1) parse table is available in the parse_table.h file and is used to look up which rule to use for expansion from an list of rules also available in parse_table.h. If any errors are detected, it is thrown with appropriate error messages.

As this is done, a parse tree is simultaneously generated which is used to generate AST later on.Once the complete parse table is available, it is pruned and unnecessary nodes are removed to give us the AST

How to use?
-----------
run "make" in the directory
Pass the input program as a command line argument to the necessary executable
Note: "make clean" removes all system generated files in the current directory
