##########################################
## tests ##
##########################################

# /W3 warning in msvc fixed with 3.15, also supports FetchContent
cmake_minimum_required(VERSION 3.15 FATAL_ERROR)


# add gtest
CPMAddPackage("gh:google/googletest#release-1.11.0")
# for gtest_discover_tests
include(GoogleTest)


macro(package_add_test TESTNAME TESTFILE)
    add_executable(${TESTNAME} ${TESTFILE})
    target_link_libraries(${TESTNAME} PRIVATE GTest::gtest GTest::gtest_main ${ARGN})
    gtest_discover_tests(${TESTNAME})
endmacro()

# actual tests #
package_add_test(suit_test Suit.test.cpp ${PROJECT_NAME}::peval)
package_add_test(rank_test Rank.test.cpp ${PROJECT_NAME}::peval)
package_add_test(cardset_test CardSet.test.cpp ${PROJECT_NAME}::peval)
