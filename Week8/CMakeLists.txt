cmake_minimum_required(VERSION 3.10)
project(Week8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(lib_name "Week8Library")

# add the library; 'SHARED' means "make .dll instead of .lib"
add_library(${lib_name} SHARED "Week8.cpp" "Week8.h")

target_include_directories(${lib_name} PRIVATE
	#"C:\\Program Files\\Java\\jdk-20\\include"
	#"C:\\Program Files\\Java\\jdk-20\\include\\win32"
	"include"
	"include/win32"
)

add_custom_command(TARGET ${lib_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
		$<TARGET_FILE:Week8Library>
        ${CMAKE_SOURCE_DIR}
)