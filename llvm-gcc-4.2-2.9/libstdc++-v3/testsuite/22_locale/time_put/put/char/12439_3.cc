// Copyright (C) 2003 Free Software Foundation
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// 22.2.5.3.1 time_put members

#include <locale>
#include <sstream>
#include <ctime>
#include <testsuite_hooks.h>

class TP : public std::time_put<char>
{
public:
  mutable std::string format_chars;

protected:
  iter_type do_put(iter_type s, std::ios_base&, char_type,
		   const std::tm*, char format, char) const
  {
    format_chars.push_back(format);
    return s;
  }
};

// libstdc++/12439
// time_put::put reads past end of format string
void test03()
{
  using namespace std;
  bool test __attribute__((unused)) = true;
  
  ostringstream stream;
  time_t tt = time(NULL);
  
  const char* fmt = "%c";
  
  TP tp;
  tp.put(TP::iter_type(stream), stream, stream.fill(), localtime(&tt),
	 fmt, fmt + 1);
  VERIFY( tp.format_chars.empty() );
}

int main()
{
  test03();
  return 0;
}
