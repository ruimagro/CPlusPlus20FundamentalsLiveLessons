# Platform-specific vcpkg toolchain file

set(Boost_DEBUG ON)

if(WIN32)
    message("I should not his this line")
    set(CMAKE_TOOLCHAIN_FILE "C:/git/vcpkg/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "Vcpkg toolchain file")
elseif(APPLE)
    # Uncomment and adjust the path below if using vcpkg on macOS
    # set(CMAKE_TOOLCHAIN_FILE "/usr/local/share/vcpkg/scripts/buildsystems/vcpkg.cmake"
    #         CACHE STRING "Vcpkg toolchain file")
endif()



cmake_minimum_required(VERSION 3.31)
project(Workbench)

set(CMAKE_CXX_STANDARD 23)

# Enable OpenMP and platform-specific compiler settings
if(WIN32)
    set(CMAKE_C_COMPILER "C:/Program Files/JetBrains/CLion 2025.1.3/bin/mingw/bin/gcc.exe")
    set(CMAKE_CXX_COMPILER "C:/Program Files/JetBrains/CLion 2025.1.3/bin/mingw/bin/g++.exe")
elseif(APPLE)
    # On macOS, use system default compilers or Homebrew-installed ones
    # Uncomment below if you want to use specific compiler paths
    # set(CMAKE_C_COMPILER "/usr/bin/clang")
    # set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif()

# Platform-specific Boost and OpenMP configuration
if(APPLE)
    if(CMAKE_C_COMPILER_ID MATCHES "Clang")
        set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp")
        set(OpenMP_C_LIB_NAMES "omp")
        set(OpenMP_omp_LIBRARY "/opt/homebrew/opt/libomp/lib/libomp.dylib")

        set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp")
        set(OpenMP_CXX_LIB_NAMES "omp")
        set(OpenMP_CXX_LIBRARIES "/opt/homebrew/opt/libomp/lib/libomp.dylib")

        include_directories("/opt/homebrew/opt/libomp/include")

        # Add these before any find_package calls
        set(BOOST_ROOT "/Users/rui/git/boost_1_88_0")
        set(BOOST_LIBRARYDIR "/Users/rui/git/boost_1_88_0/stage/lib")
        set(Boost_NO_SYSTEM_PATHS ON)

        # Add this line to help CMake find Boost
        set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/Users/rui/git/boost_1_88_0")

        # These settings can help with finding Boost
        set(Boost_USE_STATIC_LIBS OFF)
        set(Boost_USE_MULTITHREADED ON)
        set(Boost_USE_STATIC_RUNTIME OFF)
        set(Boost_DEBUG ON)  # This will show detailed debug information about Boost discovery

        # Alternative approach using Boost_DIR if the above doesn't work
        set(Boost_DIR "/Users/rui/git/boost_1_88_0/stage/lib/cmake/Boost-1.88.0")

        find_package(Boost REQUIRED COMPONENTS system filesystem)

    endif()
endif()


find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()



add_executable(Workbench chapter_8/fig08_05.cpp)

if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    # Platform-specific include directories
    if(WIN32)
        target_include_directories(Workbench PRIVATE C:/git/vcpkg/installed/x64-windows/include)
    elseif(APPLE)
        # On macOS, Boost include directories are handled automatically by find_package
        # or you can specify Homebrew path if needed:
        # target_include_directories(Workbench PRIVATE /usr/local/include)
    endif()

    target_link_libraries(Workbench PRIVATE Boost::system Boost::filesystem)
endif()

if(OpenMP_CXX_FOUND)
    target_link_libraries(Workbench PRIVATE OpenMP::OpenMP_CXX)
endif()


# The Boost C++ Libraries were successfully built!
#
# The following directory should be added to compiler include paths:
#
# /Users/rui/git/boost_1_88_0
#
# The following directory should be added to linker library paths:
#
# /Users/rui/git/boost_1_88_0/stage/lib
#