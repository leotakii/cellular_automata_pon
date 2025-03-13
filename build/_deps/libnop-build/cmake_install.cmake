# Install script for directory: /home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/libnop" TYPE STATIC_LIBRARY FILES "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-build/libnop.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/action.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/attribute.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/attributeWithHash.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/condition.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/definitions.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/fbe.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/framework.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/instigation.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/logger.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/manager.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/observable.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/observer.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/operators.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/premise.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/rule.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/scheduler.h"
    "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src/include/libnop/utils.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/libnop.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop/libnopTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop/libnopTargets.cmake"
         "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-build/CMakeFiles/Export/4a172d4dcee4c355a9685a202cf48b85/libnopTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop/libnopTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop/libnopTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop" TYPE FILE FILES "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-build/CMakeFiles/Export/4a172d4dcee4c355a9685a202cf48b85/libnopTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop" TYPE FILE FILES "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-build/CMakeFiles/Export/4a172d4dcee4c355a9685a202cf48b85/libnopTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop" TYPE FILE FILES "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-build/libnopConfig.cmake")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
