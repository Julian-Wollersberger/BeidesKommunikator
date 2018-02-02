cmake_minimum_required(VERSION 3.6)
project(BeidesKommunikator)

set(CMAKE_CXX_STANDARD 11)

set(SERVER_FILES
        server/server.c)

add_executable(server ${SERVER_FILES})


set(CLIENT_FILES
        client/client.c)

add_executable(client ${CLIENT_FILES})