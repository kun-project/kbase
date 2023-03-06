#include <gtest/gtest.h>
#include "kun/base/config.h"
#include "kun/base/types.h"
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

    // test countLZero & countRZero
    {
        u8  test_u8[3] = {12, 0, static_cast<u8>(-1)};
        u16 test_u16[3] = {12, 0, static_cast<u16>(-1)};
        u32 test_u32[3] = {12, 0, static_cast<u32>(-1)};
        u64 test_u64[3] = {12, 0, static_cast<u64>(-1)};

#define TEST_TYPE(type)                                                                                                                              \
    ASSERT_EQ(countLZero(test_##type[0]), std::numeric_limits<type>::digits - 4);                                                                    \
    ASSERT_EQ(countLZero(test_##type[1]), std::numeric_limits<type>::digits);                                                                        \
    ASSERT_EQ(countLZero(test_##type[2]), 0);                                                                                                        \
    ASSERT_EQ(countRZero(test_##type[0]), 2);                                                                                                        \
    ASSERT_EQ(countRZero(test_##type[1]), std::numeric_limits<type>::digits);                                                                        \
    ASSERT_EQ(countRZero(test_##type[2]), 0);

        TEST_TYPE(u8)
        TEST_TYPE(u16)
        TEST_TYPE(u32)
        TEST_TYPE(u64)

#undef TEST_TYPE
    }

    // test countLOne & countROne
    {
        u8  test_u8[3] = {0xCF, static_cast<u8>(-1), 0};
        u16 test_u16[3] = {0xC00F, static_cast<u16>(-1), 0};
        u32 test_u32[3] = {0xC000000F, static_cast<u32>(-1), 0};
        u64 test_u64[3] = {0xC00000000000000F, static_cast<u64>(-1), 0};

#define TEST_TYPE(type)                                                                                                                              \
    ASSERT_EQ(countLOne(test_##type[0]), 2);                                                                                                         \
    ASSERT_EQ(countLOne(test_##type[1]), std::numeric_limits<type>::digits);                                                                         \
    ASSERT_EQ(countLOne(test_##type[2]), 0);                                                                                                         \
    ASSERT_EQ(countROne(test_##type[0]), 4);                                                                                                         \
    ASSERT_EQ(countROne(test_##type[1]), std::numeric_limits<type>::digits);                                                                         \
    ASSERT_EQ(countROne(test_##type[2]), 0);

        TEST_TYPE(u8)
        TEST_TYPE(u16)
        TEST_TYPE(u32)
        TEST_TYPE(u64)

#undef TEST_TYPE
    }

    // test bitWidth
    {
        u8  test_u8[3] = {52, static_cast<u8>(-1), 0};
        u16 test_u16[3] = {52, static_cast<u16>(-1), 0};
        u32 test_u32[3] = {52, static_cast<u32>(-1), 0};
        u64 test_u64[3] = {52, static_cast<u64>(-1), 0};

#define TEST_TYPE(type)                                                                                                                              \
    ASSERT_EQ(bitWidth(test_##type[0]), 6);                                                                                                          \
    ASSERT_EQ(bitWidth(test_##type[1]), std::numeric_limits<type>::digits);                                                                          \
    ASSERT_EQ(bitWidth(test_##type[2]), 0);

        TEST_TYPE(u8)
        TEST_TYPE(u16)
        TEST_TYPE(u32)
        TEST_TYPE(u64)

#undef TEST_TYPE
    }

    // bitFloor & bitCeil
    {
        u8  test_u8[3] = {52, static_cast<u8>(-1) >> 1, 0};
        u16 test_u16[3] = {52, static_cast<u16>(-1) >> 1, 0};
        u32 test_u32[3] = {52, static_cast<u32>(-1) >> 1, 0};
        u64 test_u64[3] = {52, static_cast<u64>(-1) >> 1, 0};

#define TEST_TYPE(type)                                                                                                                              \
    ASSERT_EQ(bitFloor(test_##type[0]), 32);                                                                                                         \
    ASSERT_EQ(bitFloor(test_##type[1]), type(1) << (std::numeric_limits<type>::digits - 2));                                                         \
    ASSERT_EQ(bitFloor(test_##type[2]), 0);                                                                                                          \
    ASSERT_EQ(bitCeil(test_##type[0]), 64);                                                                                                          \
    ASSERT_EQ(bitCeil(test_##type[1]), type(1) << (std::numeric_limits<type>::digits - 1));                                                          \
    ASSERT_EQ(bitCeil(test_##type[2]), 1);

        TEST_TYPE(u8)
        TEST_TYPE(u16)
        TEST_TYPE(u32)
        TEST_TYPE(u64)

#undef TEST_TYPE
    }

    // bitFloorLog2 & bitCeilLog2
    {
        u8  test_u8[3] = {52, static_cast<u8>(-1) >> 1, 0};
        u16 test_u16[3] = {52, static_cast<u16>(-1) >> 1, 0};
        u32 test_u32[3] = {52, static_cast<u32>(-1) >> 1, 0};
        u64 test_u64[3] = {52, static_cast<u64>(-1) >> 1, 0};

#define TEST_TYPE(type)                                                                                                                              \
    ASSERT_EQ(bitFloorLog2(test_##type[0]), 5);                                                                                                      \
    ASSERT_EQ(bitFloorLog2(test_##type[1]), std::numeric_limits<type>::digits - 2);                                                                  \
    ASSERT_EQ(bitFloorLog2(test_##type[2]), 0);                                                                                                      \
    ASSERT_EQ(bitCeilLog2(test_##type[0]), 6);                                                                                                       \
    ASSERT_EQ(bitCeilLog2(test_##type[1]), std::numeric_limits<type>::digits - 1);                                                                   \
    ASSERT_EQ(bitCeilLog2(test_##type[2]), 0);

        TEST_TYPE(u8)
        TEST_TYPE(u16)
        TEST_TYPE(u32)
        TEST_TYPE(u64)

#undef TEST_TYPE
    }

    // pop count
    {
        u8  test_u8[3] = {181, static_cast<u8>(-1), 0};
        u16 test_u16[3] = {17584, static_cast<u16>(-1), 0};
        u32 test_u32[3] = {270549136, static_cast<u32>(-1), 0};
        u64 test_u64[3] = {72058148357144592, static_cast<u64>(-1), 0};

#define TEST_TYPE(type)                                                                                                                              \
    ASSERT_EQ(popCount(test_##type[0]), 5);                                                                                                          \
    ASSERT_EQ(popCount(test_##type[1]), std::numeric_limits<type>::digits);                                                                          \
    ASSERT_EQ(popCount(test_##type[2]), 0);

        TEST_TYPE(u8)
        TEST_TYPE(u16)
        TEST_TYPE(u32)
        TEST_TYPE(u64)

#undef TEST_TYPE
    }
}
