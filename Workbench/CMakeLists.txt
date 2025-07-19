set(CMAKE_TOOLCHAIN_FILE "C:/git/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

cmake_minimum_required(VERSION 3.31)
project(Workbench)

set(CMAKE_CXX_STANDARD 23)

# Enable OpenMP
if(WIN32)
    set(CMAKE_C_COMPILER "C:/Program Files/JetBrains/CLion 2025.1.3/bin/mingw/bin/gcc.exe")
    set(CMAKE_CXX_COMPILER "C:/Program Files/JetBrains/CLion 2025.1.3/bin/mingw/bin/g++.exe")
endif()

find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

find_package(Boost REQUIRED COMPONENTS system filesystem multiprecision)

add_executable(Workbench chapter_7/fig07_03.cpp)

if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    target_include_directories(Workbench PRIVATE C:/git/vcpkg/installed/x64-windows/include)
    target_link_libraries(Workbench PRIVATE Boost::system Boost::filesystem Boost::multiprecision)
endif()

if(OpenMP_CXX_FOUND)
    target_link_libraries(Workbench PRIVATE OpenMP::OpenMP_CXX)
endif()
