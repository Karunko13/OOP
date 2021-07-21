cmake_minimum_required (VERSION 2.6)
project (Lab3 CXX)
include_directories(src include)

add_executable(Lab3 main.cpp src/StringBack.cpp include/StringBack.h)

set(LIBSRC include/StringBack.h src/StringBack.cpp )
add_library(lab3 ${LIBSRC})

target_link_libraries(Lab3 lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab3 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab3
    DEPENDS Lab3
)