cmake_minimum_required(VERSION 3.20)

project(MyProject CXX)



if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
file(GLOB project
    *
)
add_executable(${PROJECT_NAME} ${project})
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

# ---------------------------------------------------------------------------------------
# Example of using header-only library
# ---------------------------------------------------------------------------------------
if(SPDLOG_BUILD_EXAMPLE_HO)
    target_link_libraries(example_header_only PRIVATE spdlog::spdlog_header_only)
endif()