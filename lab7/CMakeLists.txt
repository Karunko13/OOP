cmake_minimum_required (VERSION 2.6)
project (Lab7 CXX)

include_directories(src include)
add_executable(Lab7 main.cpp  src/Dir.cpp src/File.cpp src/Object.cpp include/Dir.h include/Object.h include/File.h)

set(LIBSRC include/Dir.h include/Object.h include/File.h src/File.cpp src/Dir.cpp src/Object.cpp)
add_library(lab7 ${LIBSRC})

target_link_libraries(Lab7 lab7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab7 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab7
    DEPENDS Lab7
)
