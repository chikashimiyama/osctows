cmake_minimum_required(VERSION 3.13.2)

project(osctows)

add_executable(osctows
        src/Application.cpp
        src/UDPServer.cpp
        src/WebSocketServer.cpp)


target_include_directories(osctows PRIVATE
        include
        asio/asio/include)
target_compile_features(osctows PRIVATE cxx_std_17)
