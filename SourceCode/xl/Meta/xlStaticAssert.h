//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlStaticAssert.h
//    Author:      Streamlet
//    Create Time: 2011-04-24
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __XLSTATICASSERT_H_8D45F3AE_6AA7_436B_AB6A_2C4D7A442220_INCLUDED__
#define __XLSTATICASSERT_H_8D45F3AE_6AA7_436B_AB6A_2C4D7A442220_INCLUDED__


#include <xl/xlDef.h>
#include <xl/Meta/xlMacros.h>

namespace xl
{
    template <bool expr>
    struct StaticAssert;

    template <>
    struct StaticAssert<true>
    {

    };

    template <size_t x>
    struct StaticAssertTest
    {

    };
    
#define XL_STATIC_ASSERT(expr) typedef xl::StaticAssertTest<sizeof(xl::StaticAssert<expr>)> XL_CONN(StaticAssert_, __COUNTER__)

} // namespace xl



#endif // #ifndef __XLSTATICASSERT_H_8D45F3AE_6AA7_436B_AB6A_2C4D7A442220_INCLUDED__
