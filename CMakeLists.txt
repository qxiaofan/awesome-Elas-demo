# project
cmake_minimum_required (VERSION 2.8)
project (Elas)

# make release version
set(CMAKE_BUILD_TYPE Release)

SET(CMAKE_CXX_FLAGS "-msse3 -std=c++11")

set(OpenCV_DIR "/usr/local/include/opencv3.2.0/share/OpenCV")
find_package( OpenCV REQUIRED )
find_package(PCL REQUIRED)

message(${OpenCV_VERSION})
message(${OpenCV_INSTALL_PATH})

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/include
  ${OpenCV_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

set(Elas_LIBS elas_libs)

add_library(${Elas_LIBS} SHARED
     src/descriptor.cpp
     src/elas.cpp
     src/filter.cpp
     src/matrix.cpp
     src/triangle.cpp
)

add_executable(elas src/main.cpp)
target_link_libraries(elas ${Elas_LIBS} ${OpenCV_LIBS} ${PCL_LIBRARIES})

