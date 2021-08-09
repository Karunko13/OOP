cmake_minimum_required (VERSION 2.6)
project (Lab6 CXX)

include_directories(src include)
add_executable(Lab6 main.cpp  src/Primitive.cpp src/Product.cpp src/Ratio.cpp src/Sum.cpp include/Sum.h include/Primitive.h include/Ratio.h include/Product.h)

set(LIBSRC include/Sum.h include/Primitive.h include/Ratio.h include/Product.h  src/Product.cpp src/Primitive.cpp src/Ratio.cpp src/Sum.cpp)
add_library(lab6 ${LIBSRC})

target_link_libraries(Lab6 lab6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab6 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab6
    DEPENDS Lab6
)
