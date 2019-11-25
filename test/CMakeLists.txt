set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    Gmock.h
    face.h
    ../app/distance.cpp
    ../app/face.cpp
)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(../vendor/dlib dlib_build)


target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest dlib::dlib ${OpenCV_LIBS})

