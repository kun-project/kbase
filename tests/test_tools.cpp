#include <gtest/gtest.h>
#include "kun/base/config.h"
#include "kun/base/types.h"
#include "kun/base/traits.h"
#include "kun/base/tools/integer_tools.h"
#include "kun/base/tools/bit.h"

TEST(TestBase, test_tools)
{
    using namespace kun;

    // test count right/left zero
    {
        u64 a64(12), b64(0), c64(static_cast<u64>(-1));
        u32 a32(12), b32(0), c32(static_cast<u32>(-1));

        //        ASSERT_EQ(countLZero(a64), 60);
        //        ASSERT_EQ(countLZero(b64), 64);
        //        ASSERT_EQ(countLZero(c64), 0);
        //        ASSERT_EQ(countLZero(a32), 28);
        //        ASSERT_EQ(countLZero(b32), 32);
        //        ASSERT_EQ(countLZero(c32), 0);
        //
        //        ASSERT_EQ(countRZero(a64), 2);
        //        ASSERT_EQ(countRZero(b64), 64);
        //        ASSERT_EQ(countRZero(c64), 0);
        //        ASSERT_EQ(countRZero(a32), 2);
        //        ASSERT_EQ(countRZero(b32), 32);
        //        ASSERT_EQ(countRZero(c32), 0);
    }
}
