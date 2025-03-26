project(Google_tests)

add_subdirectory(lib)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run test1.cpp test2.cpp)

target_link_libraries(Google_Tests_run stdc++)
target_link_libraries(Google_Tests_run Library_lib)
target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(Google_Tests_run m)


add_test(runUnitTests Google_Tests_run)