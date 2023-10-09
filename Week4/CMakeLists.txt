cmake_minimum_required (VERSION 3.2)

project ("Week4")

# Add source to this project's executable.
add_executable (Week4 "Week4.cpp" "Vehicle.h" "Vehicle.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Week4 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
