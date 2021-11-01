##########################################
## main library ##
##########################################

# /W3 warning in msvc fixed with 3.15
cmake_minimum_required(VERSION 3.15 FATAL_ERROR)


project(
    modern-pokerstove
    VERSION 0.1.0
    LANGUAGES CXX
    DESCRIPTION "A PokerStove revamp with modern cmake and C++."
)


# project options, these are off by default to not install gtest, propagate -Wpedantic etc.
option(MODERNPOKERSTOVE_BUILD_EXAMPLES "Enable building the examples" OFF)
option(MODERNPOKERSTOVE_BUILD_TESTS "Enable building the tests" OFF)


# do not allow building in-source
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.")
endif()


# dependencies
include(cmake/CPM.cmake)
# boost
CPMAddPackage("gh:Orphis/boost-cmake#7f97a08b64bd5d2e53e932ddf80c40544cf45edf@1.71.0")
# create license disclaimer
CPMAddPackage("gh:cpm-cmake/CPMLicenses.cmake@0.0.5")
# PackageProject.cmake will be used to make our project installable
CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.8.0")


# peval library
FILE(GLOB_RECURSE src_peval CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/peval/*.cpp")
add_library(peval STATIC ${src_peval})
target_include_directories(
    peval
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)
target_compile_features(peval PUBLIC cxx_std_17)
target_compile_options(peval PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/permissive->)
target_link_libraries(peval PUBLIC Boost::boost)


# configure according to options, build examples, tests etc.
if(MODERNPOKERSTOVE_BUILD_EXAMPLES)
    message(STATUS "Building samples enabled")
    add_subdirectory(example)
else()
    message(STATUS "Building samples DISABLED")
endif()
if(MODERNPOKERSTOVE_BUILD_TESTS)
    message(STATUS "Testing enabled")
    enable_testing()
    add_subdirectory(test)
else()
    message(STATUS "Testing DISABLED")
endif()


# make installable target
string(TOLOWER ${PROJECT_NAME}-peval/version.h VERSION_HEADER_LOCATION_PEVAL)
packageProject(
    NAME peval
    VERSION ${PROJECT_VERSION}
    NAMESPACE ${PROJECT_NAMESPACE}
    BINARY_DIR ${PROJECT_BINARY_DIR}
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
    INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION}
    VERSION_HEADER "${VERSION_HEADER_LOCATION_PEVAL}"
    DEPENDENCIES "boost 1.7.1"
)
#string(TOLOWER ${PROJECT_NAME}-penum/version.h VERSION_HEADER_LOCATION_PENUM)
#packageProject(
#    NAME penum
#    VERSION ${PROJECT_VERSION}
#    NAMESPACE ${PROJECT_NAMESPACE}
#    BINARY_DIR ${PROJECT_BINARY_DIR}
#    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
#    INCLUDE_DESTINATION include/peval-${PROJECT_VERSION}
#    VERSION_HEADER "${VERSION_HEADER_LOCATION_PENUM}"
#    DEPENDENCIES ""
#)
