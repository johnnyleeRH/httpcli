cmake_minimum_required(VERSION 2.8)
project(httpclient)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-a17.cortex-a7 -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-a17.cortex-a7 -std=c++11 -fPIC -ldl")

set(TOOLCHAIN "/opt/hisi-linux/x86-arm/arm-hisiv500-linux/target/bin/")
set(CMAKE_C_COMPILER ${TOOLCHAIN}/arm-hisiv500-linux-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/arm-hisiv500-linux-g++)
set(AR ${TOOLCHAIN}/arm-hisiv500-linux-ar)
link_directories(${PROJECT_SOURCE_DIR}/lib)

include_directories(
        ${PROJECT_SOURCE_DIR}/
        ${PROJECT_SOURCE_DIR}/curlpp
        ${PROJECT_SOURCE_DIR}/rapidjson/include
)

set(SRC
        ${PROJECT_SOURCE_DIR}/httpcli.cc
        ${PROJECT_SOURCE_DIR}/clicreator.cc
        ${PROJECT_SOURCE_DIR}/sample/sample.cc
)
set(LIBS
        curlpp
        curl
        ssl
        crypto
)
add_executable(httpcli ${SRC})
target_link_libraries(httpcli ${LIBS})