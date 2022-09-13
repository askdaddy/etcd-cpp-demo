cmake_minimum_required(VERSION 3.22)
project(mycpp)

set(CMAKE_CXX_STANDARD 17)
## conan install
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(NO_OUTPUT_DIRS CONANFILE conanfile.txt
        INSTALL_FOLDER ${CMAKE_BINARY_DIR}
        BUILD missing
        BASIC_SETUP
        )

message("CONAN_LIBS >> ${CONAN_LIBS}")

set(CONAN_CMAKE_FILE_PATH ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CONAN_CMAKE_FILE_PATH})
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})
set(SYSTEM_LIBS  ${CONAN_LIBS})
## end of conan
add_compile_options(-fPIC)

set(GRPC_CHANNEL_CLASS_FOUND true)
include_directories(etcd-cpp-apiv3-0.2.6)
add_subdirectory("etcd-cpp-apiv3-0.2.6")

add_executable(mycpp main.cpp)
target_link_libraries(mycpp etcd-cpp-api)
