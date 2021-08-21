cmake_minimum_required (VERSION 2.6)
project (Lab9 CXX)
include_directories(src include)

add_executable(Lab9 main.cpp src/Point2D.cpp include/Point2D.h)

set(LIBSRC include/Point2D.h src/Point2D.cpp )
add_library(lab9 ${LIBSRC})

target_link_libraries(Lab9 lab9)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab9 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab9
    DEPENDS Lab9
)