#include <gtest/gtest.h>
#include "kun/base/config.h"
#include "kun/base/types.h"
#include "kun/base/traits.h"
#include "kun/base/tools/integer_tools.h"
#include "kun/base/tools/bit.h"

TEST(TestBase, test_tools)
{
    using namespace kun;

    // test flag tools
    {
        using TestFlag = u32;
        enum TestFlag_
        {
            TestFlag_None = 0,
            TestFlag_A = 1 << 0,
            TestFlag_B = 1 << 1,
            TestFlag_C = 1 << 2,
            TestFlag_D = 1 << 3,
            TestFlag_ALL = TestFlag_A | TestFlag_B | TestFlag_C | TestFlag_D,
        };

        TestFlag flag = TestFlag_None;
        ASSERT_FALSE(allFlag<TestFlag>(flag, TestFlag_ALL));
        ASSERT_FALSE(anyFlag<TestFlag>(flag, TestFlag_ALL));

        flag = setFlag<TestFlag>(flag, TestFlag_A);
        ASSERT_EQ(flag, TestFlag_A);
        ASSERT_FALSE(allFlag<TestFlag>(flag, TestFlag_ALL));
        ASSERT_TRUE(allFlag<TestFlag>(flag, TestFlag_A));
        ASSERT_TRUE(anyFlag<TestFlag>(flag, TestFlag_ALL));
        ASSERT_FALSE(allFlag<TestFlag>(flag, TestFlag_A | TestFlag_C));
        ASSERT_TRUE(anyFlag<TestFlag>(flag, TestFlag_A | TestFlag_C));

        flag = eraseFlag<TestFlag>(flag, TestFlag_A);
        ASSERT_EQ(flag, TestFlag_None);
        ASSERT_FALSE(allFlag<TestFlag>(flag, TestFlag_ALL));
        ASSERT_FALSE(anyFlag<TestFlag>(flag, TestFlag_ALL));

        flag = setFlag<TestFlag>(flag, TestFlag_ALL);
        ASSERT_EQ(flag, TestFlag_ALL);
        ASSERT_TRUE(allFlag<TestFlag>(flag, TestFlag_ALL));
        ASSERT_TRUE(anyFlag<TestFlag>(flag, TestFlag_ALL));
        ASSERT_TRUE(allFlag<TestFlag>(flag, TestFlag_A));
        ASSERT_TRUE(anyFlag<TestFlag>(flag, TestFlag_A));
        ASSERT_TRUE(allFlag<TestFlag>(flag, TestFlag_A | TestFlag_D));
        ASSERT_TRUE(anyFlag<TestFlag>(flag, TestFlag_A | TestFlag_D));
    }

    // test integer div

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
