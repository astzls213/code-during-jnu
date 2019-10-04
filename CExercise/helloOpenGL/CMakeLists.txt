cmake_minimum_required(VERSION 3.14)
project(helloOpenGL)

set(CMAKE_CXX_STANDARD 11)


set(HEADERS /usr/local/Cellar)
set(HEADERS /usr/local/include)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3/lib/libglfw.3.3.dylib)
set(FRAMEWORKS_1 /System/Library/Frameworks/Cocoa.framework)
set(FRAMEWORKS_2 /System/Library/Frameworks/OpenGL.framework)
set(FRAMEWORKS_3 /System/Library/Frameworks/GLUT.framework)
set(FRAMEWORKS_4 /System/Library/Frameworks/CoreVideo.framework)
set(FRAMEWORKS_5 /System/Library/Frameworks/IOKit.framework)

include_directories(${HEADERS})

link_libraries(${GLFW_LINK} ${FRAMEWORKS_1} ${FRAMEWORKS_2} ${FRAMEWORKS_3} ${FRAMEWORKS_4} ${FRAMEWORKS_5})

add_executable(helloOpenGL main.cpp glad.c)
