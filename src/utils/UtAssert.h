/* Copyright 2013 the SumatraPDF project authors (see AUTHORS file).
   License: Simplified BSD (see COPYING.BSD) */

#ifndef UtAssert_h
#define UtAssert_h

/* This is assert for unit tests that can be used in non-interactive usage.
Instead of showing a UI to the user, like regular assert(), it simply
remembers number of failed asserts. */

void utassert_func(bool ok, const char *exprStr, const char *file, int lineNo);
int  utassert_print_results();

#define utassert(_expr) \
    utassert_func(_expr, #_expr, __FILE__, __LINE__)

// TODO: temporary. Unit tests should use utassert explicitly
#undef assert
#define assert utassert

#endif