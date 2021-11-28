add_executable(TestConfiguration TestConfiguration.cpp)
target_link_libraries(TestConfiguration PUBLIC MRQM GTest::gtest GTest::gtest_main jsoncpp_lib)

# allow user to run tests with `make test` or `ctest`
gtest_discover_tests(TestConfiguration)
add_test(
    NAME TestConfiguration
    COMMAND TestConfiguration
    WORKING_DIRECTORY tests
)
