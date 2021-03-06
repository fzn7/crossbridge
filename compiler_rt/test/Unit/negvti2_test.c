//===-- negvti2_test.c - Test __negvti2 -----------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file tests __negvti2 for the compiler_rt library.
//
//===----------------------------------------------------------------------===//

#if __x86_64

#include "int_lib.h"
#include <stdio.h>

// Returns: -a

// Effects: aborts if -a overflows

ti_int __negvti2(ti_int a);
ti_int __negti2(ti_int a);

int test__negvti2(ti_int a)
{
    ti_int x = __negvti2(a);
    ti_int expected = __negti2(a);
    if (x != expected)
    {
        twords at;
        at.all = a;
        twords xt;
        xt.all = x;
        twords expectedt;
        expectedt.all = expected;
        printf("error in __negvti2(0x%.16llX%.16llX) = 0x%.16llX%.16llX, "
               "expected 0x%.16llX%.16llX\n",
               at.s.high, at.s.low, xt.s.high, xt.s.low, expectedt.s.high, expectedt.s.low);
    }
    return x != expected;
}

#endif

int main()
{
#if __x86_64
    if (test__negvti2(0))
        return 1;
    if (test__negvti2(1))
        return 1;
    if (test__negvti2(-1))
        return 1;
    if (test__negvti2(2))
        return 1;
    if (test__negvti2(-2))
        return 1;
    if (test__negvti2(3))
        return 1;
    if (test__negvti2(-3))
        return 1;
    if (test__negvti2(make_ti(0x0000000000000000LL, 0x00000000FFFFFFFELL)))
        return 1;
    if (test__negvti2(make_ti(0xFFFFFFFFFFFFFFFFLL, 0xFFFFFFFF00000002LL)))
        return 1;
    if (test__negvti2(make_ti(0x0000000000000000LL, 0x00000000FFFFFFFFLL)))
        return 1;
    if (test__negvti2(make_ti(0xFFFFFFFFFFFFFFFFLL, 0xFFFFFFFF00000001LL)))
        return 1;
    if (test__negvti2(make_ti(0x0000000000000000LL, 0x0000000100000000LL)))
        return 1;
    if (test__negvti2(make_ti(0xFFFFFFFFFFFFFFFFLL, 0xFFFFFFFF00000000LL)))
        return 1;
    if (test__negvti2(make_ti(0x0000000000000000LL, 0x0000000200000000LL)))
        return 1;
    if (test__negvti2(make_ti(0xFFFFFFFFFFFFFFFFLL, 0xFFFFFFFE00000000LL)))
        return 1;
    if (test__negvti2(make_ti(0x0000000000000000LL, 0x0000000300000000LL)))
        return 1;
    if (test__negvti2(make_ti(0xFFFFFFFFFFFFFFFFLL, 0xFFFFFFFD00000000LL)))
        return 1;
    if (test__negvti2(make_ti(0x0000000000000000LL, 0x7FFFFFFFFFFFFFFFLL)))
        return 1;
    if (test__negvti2(make_ti(0xFFFFFFFFFFFFFFFFLL, 0x8000000000000001LL)))
        return 1;
    if (test__negvti2(make_ti(0x0000000000000000LL, 0x7FFFFFFFFFFFFFFFLL)))
        return 1;
    if (test__negvti2(make_ti(0xFFFFFFFFFFFFFFFFLL, 0xFFFFFFFE00000000LL)))
        return 1;
    if (test__negvti2(make_ti(0x0000000000000000LL, 0x0000000200000000LL)))
        return 1;
    if (test__negvti2(make_ti(0xFFFFFFFFFFFFFFFFLL, 0xFFFFFFFF00000000LL)))
        return 1;
    if (test__negvti2(make_ti(0x0000000000000000LL, 0x0000000100000000LL)))
        return 1;
//     if (test__negvti2(make_ti(0x8000000000000000LL, 0x0000000000000000LL))) // abort
//         return 1;
    if (test__negvti2(make_ti(0x8000000000000000LL, 0x0000000000000001LL)))
        return 1;
    if (test__negvti2(make_ti(0x7FFFFFFFFFFFFFFFLL, 0xFFFFFFFFFFFFFFFFLL)))
        return 1;

#else
    printf("skipped\n");
#endif
   printf("PASS\n");
    return 0;
}
