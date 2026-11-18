/*
 * conio.h - Console I/O header for Turbo C compatibility
 * When compiled in Turbo C / Borland C++, the native conio.h is used.
 * When compiled on modern systems (macOS, Linux), this provides compatible stubs.
 */

#ifndef CONIO_H
#define CONIO_H

#include <stdio.h>

#if !defined(__TURBOC__) && !defined(__BORLANDC__)
static inline void clrscr(void) {
    /* Optional ANSI escape code to clear terminal screen */
    /* printf("\033[2J\033[H"); */
}

static inline int getch(void) {
    /* Return immediately or read character */
    return 0;
}
#endif

#endif /* CONIO_H */
