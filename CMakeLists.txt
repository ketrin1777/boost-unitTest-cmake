cmake_minimum_required(VERSION 3.20.0)
set(CMAKE_CXX_STANDARD 20)
project(helloworld VERSION 0.0.1$ENV{TRAVIS_BUILD_NUMBER})

add_subdirectory(include/spdlog)
find_package(Threads REQUIRED)

enable_testing()

add_subdirectory(test_version)
add_subdirectory(src)



# install(TARGETS MyProject RUNTIME DESTINATION bin)

# set(CPACK_GENERATOR DEB)

# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)



