#include <gtest/gtest.h>
#include "kun/base/config.h"
#include "kun/base/types.h"
#include "kun/base/traits.h"

TEST(TestBase, test_traits)
{
    using namespace kun;

    // test types
    {
        ASSERT_EQ(sizeof(u8), 1);
        ASSERT_EQ(sizeof(i8), 1);
        ASSERT_EQ(sizeof(u16), 2);
        ASSERT_EQ(sizeof(i16), 2);
        ASSERT_EQ(sizeof(u32), 4);
        ASSERT_EQ(sizeof(i32), 4);
        ASSERT_EQ(sizeof(u64), 8);
        ASSERT_EQ(sizeof(i64), 8);
    }

    // test traits

}
