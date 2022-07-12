cmake_minimum_required (VERSION 3.20)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/test_version/version.h)

IF (WIN32)
    set(BOOST_ROOT "c:/DevSoft/boost")
    set(BOOST_INCLUDE_DIR "c:/DevSoft/boost/include/")
ENDIF()

set(Boost_INCLUDE_DIR "c:/DevSoft/boost/include")
# Boost filesystem library (debug)
set(Boost_FILESYSTEM_LIBRARY_DEBUG "C:/DevSoft/boost/lib/libboost_filesystem-mgw12-mt-d-x64-1_79.a")
# Boost filesystem library (release)
set(Boost_FILESYSTEM_LIBRARY_RELEASE "C:/DevSoft/boost/lib/libboost_filesystem-mgw12-mt-x64-1_79.a")

# Boost system library (debug)
set(Boost_SYSTEM_LIBRARY_DEBUG "C:/DevSoft/boost/lib/libboost_system-mgw12-mt-d-x64-1_79.a")
# Boost system library (release)
set(Boost_SYSTEM_LIBRARY_RELEASE "C:/DevSoft/boost/lib/libboost_system-mgw12-mt-x64-1_79.a")

# Boost unit_test_framework library (debug)
set(Boost_UNIT_TEST_FRAMEWORK_LIBRARY_DEBUG "C:/DevSoft/boost/lib/libboost_unit_test_framework-mgw12-mt-d-x64-1_79.a")
# Boost unit_test_framework library (release)
set(Boost_UNIT_TEST_FRAMEWORK_LIBRARY_RELEASE "C:/DevSoft/boost/lib/libboost_unit_test_framework-mgw12-mt-x64-1_79.a")

find_package( Boost REQUIRED COMPONENTS system filesystem unit_test_framework)
project(MyProject_test)

file(GLOB prTest 
	*
)

add_executable (${PROJECT_NAME} 
	${prTest}
)

set(BOOST_LIBRARIES Boost::unit_test_framework Boost::system Boost::filesystem)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${Boost_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} ${BOOST_LIBRARIES})

add_test(MyBoostModule ${PROJECT_NAME})