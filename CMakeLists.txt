cmake_minimum_required(VERSION 3.5)

project(DFB  LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(lib/cdlpp/use.cmake)

include(lib/cdlpp-db/use.cmake)

cdlpp(lib/cdlpp)

cdlppdb(lib/cdlpp-db)

add_executable(${PROJECT_NAME}
    ${CDLPP_SRC_FILES}

     ${CDLPPDB_SRC_FILES}

    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CDLPP_INCLUDE_DIRS}

     ${CDLPPDB_INCLUDE_DIRS}

    include/
)

cdlpp_libs()

cdlppdb_libs()

configure_file(config.json ./ COPYONLY)






