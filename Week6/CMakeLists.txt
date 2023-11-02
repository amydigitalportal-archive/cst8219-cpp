# CMakeList.txt : CMake project for Week6, include source and define
# project specific logic here.
#
# Refs:
# [1] KamilCuk (2019), "CMake: set directory for target sources"
#     - https://stackoverflow.com/a/55494263
cmake_minimum_required (VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Week6")

set(target_includes
	ElectricVehicle.h
	GasolineVehicle.h
	HybridVehicle.h
	Vehicle.h
)
list(TRANSFORM target_includes PREPEND "include/") # Prepend dir-path to each entry on the list [1]

set(target_sources
	ElectricVehicle.cpp
	GasolineVehicle.cpp
	HybridVehicle.cpp
	Vehicle.cpp
	Week6.cpp
)
list(TRANSFORM target_sources PREPEND "src/")

# Add source to this project's executable.
add_executable (Week6 ${target_sources} ${target_includes})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Week6 PROPERTY CXX_STANDARD 20)
endif()
