﻿# CMakeList.txt : CMake project for FinalProj, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("FinalProj")

# Add source to this project's executable.
add_executable (FinalProj "Main.cpp"  "Test.h")

target_include_directories(FinalProj PUBLIC "../nana/include")

add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
add_definitions(-DNANA_ENABLE_AUDIO)

target_link_libraries(FinalProj "nana_v143_Release_x64")

target_link_directories(FinalProj PUBLIC "../nana/build/bin")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FinalProj PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
