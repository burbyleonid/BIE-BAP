#ifndef EXTERNS_HPP_INCLUDED
#define EXTERNS_HPP_INCLUDED


#ifdef EXT_HERE
#  define _extern_
#else
#  define _extern_ extern
#endif

#include <chrono>
#include <set>

typedef std::chrono::duration<double> dduration;

namespace externs {
  _extern_ std::chrono::high_resolution_clock::time_point start;

  _extern_ double timeout;
  _extern_ int PLUS_INF;
  _extern_ int MINUS_INF;
//  _extern_ std::set<int> priorValues;
}

#endif

