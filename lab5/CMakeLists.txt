cmake_minimum_required (VERSION 2.6)
project (Lab5 CXX)

include_directories(src include)
add_executable(Lab5 main.cpp  src/ShapeContainer.cpp src/Vertex.cpp src/Shape2D.cpp src/Rectangle.cpp include/Rectangle.h include/ShapeContainer.h include/Shape2D.h include/Vertex.h)

set(LIBSRC include/Rectangle.h include/ShapeContainer.h include/Shape2D.h include/Vertex.h  src/Vertex.cpp src/ShapeContainer.cpp src/Shape2D.cpp src/Rectangle.cpp)
add_library(lab5 ${LIBSRC})

target_link_libraries(Lab5 lab5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS Lab5 DESTINATION bin)

add_custom_target(info # ALL # target zoo is always built
    COMMAND echo "Build commands:"
    COMMAND cat compile_commands.json 
    COMMAND echo ""
    COMMAND echo ""
    COMMAND echo "Debug info:"
    COMMAND readelf --debug-dump=decodedline Lab5
    DEPENDS Lab5
)
