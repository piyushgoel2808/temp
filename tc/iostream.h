/*
 * iostream.h - Stream I/O header for Turbo C++ compatibility
 * When compiled in Turbo C++ 3.0, the native iostream.h is used.
 * When compiled on modern C++ systems, this provides standard C++ stream mappings.
 */

#ifndef IOSTREAM_H
#define IOSTREAM_H

#if !defined(__TURBOC__) && !defined(__BORLANDC__)
#include <iostream>
using namespace std;
#endif

#endif /* IOSTREAM_H */
