project(PySAMP)

cmake_minimum_required(VERSION 3.15)
list(APPEND CMAKE_MODULE_PATH ${SAMPGDK_DIR}/cmake)

set(PYSAMP_MAJOR_VERSION 2)
set(PYSAMP_MINOR_VERSION 0)
set(PYSAMP_REVISION 0)

set(PYSAMP_VERSION "${PYSAMP_MAJOR_VERSION}.${PYSAMP_MINOR_VERSION}.${PYSAMP_REVISION}")
add_definitions(-DPYSAMP_VERSION=${PYSAMP_VERSION})

find_package(
    Python3
    COMPONENTS Development
    REQUIRED
)

find_library(
    SAMPGDK_LIBRARY
    NAMES sampgdk sampgdk4s
    HINTS "${CMAKE_PREFIX_PATH}/lib/"
    REQUIRED
)

include(AMXConfig)
include(AddSAMPPlugin)
include(FindSAMPSDK)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SAMPSDK_DIR}/amx
    ${SAMPGDK_DIR}/build/lib/sampgdk/
    ${SAMPSDK_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/bindings
    ${CMAKE_CURRENT_SOURCE_DIR}/pysamp
    ${Python3_INCLUDE_DIRS}
    ${CMAKE_BINARY_DIR}/generated/
)

get_filename_component(PYTHON_HOME "${Python3_INCLUDE_DIRS}/../.." REALPATH)
message(STATUS "PYTHON_HOME = ${PYTHON_HOME}")
message(STATUS "Python3_LIBRARIES = ${Python3_LIBRARIES}")
message(STATUS "Python3_INCLUDE_DIRS = ${Python3_INCLUDE_DIRS}")
message(STATUS "SAMPGDK_LIBRARY = ${SAMPGDK_LIBRARY}")

add_definitions(-DSAMPGDK_AMALGAMATION)

configure_file(config.h.in ${CMAKE_BINARY_DIR}/generated/config.h)

add_samp_plugin(PySAMP
    ${SAMPGDK_DIR}/build/lib/sampgdk/sampgdk.c
    ${SAMPGDK_DIR}/build/lib/sampgdk/sampgdk.h
    ${SAMPSDK_DIR}/amxplugin.cpp
    ${CMAKE_BINARY_DIR}/generated/config.h
    main.h
    main.cpp
    main.def
    pysamp/pysamp.cpp
    pysamp/pysamp.h
    pysamp/pygamemode.cpp
    pysamp/pygamemode.h
    pysamp/timer.cpp
    pysamp/timer.h
    pysamp/callbacks.cpp
    pysamp/callbacks.h
    pysamp/param_converter.cpp
    pysamp/param_converter.h
    bindings/samp.cpp
    bindings/samp.h
    bindings/logprintf.cpp
    bindings/logprintf.h
)

target_link_libraries(PySAMP ${Python3_LIBRARIES})
target_link_libraries(PySAMP ${SAMPGDK_LIBRARY})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif(DOXYGEN_FOUND)
