cmake_minimum_required(VERSION 3.18)

project(cellular_automata VERSION 0.0.1 DESCRIPTION "Sensors Application")

#find_package(libnop QUIET)
if(NOT libnop_FOUND)
	include(FetchContent)
	FetchContent_Declare(libnop
		GIT_REPOSITORY https://nop.dainf.ct.utfpr.edu.br/nop-implementations/frameworks/nop-framework-cpp-4-dot-5/nop-framework-cpp-4-dot-5-kernel.git
		GIT_TAG main
	)
	FetchContent_GetProperties(libnop)
	if(NOT libnop_POPULATED)
		FetchContent_MakeAvailable(libnop)
	endif()
endif()


include_directories(include/)

add_executable(cellular_automata src/main.cpp)

set_target_properties(cellular_automata PROPERTIES
	CXX_STANDARD 20
)
target_link_libraries(cellular_automata libnop pthread)
