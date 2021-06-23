cmake_minimum_required(VERSION 3.7)

project(lib6502_Playground)

configure_file(cmake/libcore6502.txt.in libCore6502-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libCore6502-download )


if(result)
	message(FATAL_ERROR "CMake step for libCore6502 failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libCore6502-download )
if(result)
	message(FATAL_ERROR "Build step for libCore6502 failed: ${result}")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/libCore6502-src
		 ${CMAKE_CURRENT_BINARY_DIR}/libCore6502-build
		 EXCLUDE_FROM_ALL)

set(PROJECT_BINARY_DIR ${CMAKE_BINARY_DIR}/build)
set (CMAKE_CXX_STANDARD 11)
add_subdirectory(src)

