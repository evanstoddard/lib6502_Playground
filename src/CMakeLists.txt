
set(CMAKECMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples)

include_directories(${lib6502_Playground_SOURCE_DIR}/include)
include_directories(${Core6502_SOURCE_DIR}/include)


add_executable(lib6502_Playground main.cpp)
target_link_libraries(lib6502_Playground Core6502)
