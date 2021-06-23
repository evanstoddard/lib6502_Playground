
set(CMAKECMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${lib6502_Playground_SOURCE_DIR}/include)
include_directories(${Core6502_SOURCE_DIR}/include)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(lib6502_Playground main.cpp)
target_link_libraries(lib6502_Playground Core6502)
target_link_libraries(lib6502_Playground ${GTKMM_LIBRARIES})
