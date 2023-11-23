get_filename_component(LIBNNOP_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

set(libnop_INCLUDE_DIRS )

if(NOT TARGET libnop AND NOT libnop_BINARY_DIR)
    include("${LIBNNOP_CMAKE_DIR}/libnopTargets.cmake")
endif()

set(libnop_LIBRARIES
    libnop
)
