# Find and include gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Find and include curl_easy
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

# Add your test executable
add_executable(unit_test main.cpp client.cpp)

# Link against gtest and curl_easy
target_link_libraries(unit_test ${GTEST_LIBRARIES} ${CURL_LIBRARIES})