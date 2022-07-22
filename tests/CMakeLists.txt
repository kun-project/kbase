# collect files
file(GLOB_RECURSE SRC_FILES *.cpp)

# add target
add_executable(test_base ${SRC_FILES})

# add package
target_link_libraries(test_base PRIVATE GTest::gtest_main)

# dependencies
target_link_libraries(test_base PRIVATE kbase)