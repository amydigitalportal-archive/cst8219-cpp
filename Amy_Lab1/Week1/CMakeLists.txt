# CMakeLists.txt : Directives and instructions for project's source files and targets.
# CST8219 C++ Programming (23F)
# Week 1 - Lab1
# Student: Amy Novun - 040 757 422

# Add source to this project's executable.
add_executable (Amy_Lab1 "Week1.cpp" "Week1.h")

if (CMAKE_VERSION VERSION_GREATER 3.2)
  set_property(TARGET Amy_Lab1 PROPERTY CXX_STANDARD 20)
endif()