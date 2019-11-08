add_executable(shell-app main.cpp distance.cpp face.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(../vendor/dlib dlib_build)

 


target_link_libraries(shell-app dlib::dlib )




find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(shell-app dlib::dlib ${OpenCV_LIBS} )

