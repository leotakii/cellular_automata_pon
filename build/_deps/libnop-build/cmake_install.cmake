# Install script for directory: /mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src

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

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/libnop" TYPE STATIC_LIBRARY FILES "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-build/libnop.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/action.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/attribute.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/attributeWithHash.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/condition.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/definitions.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/fbe.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/framework.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/instigation.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/logger.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/manager.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/observable.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/observer.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/operators.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/premise.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/rule.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/scheduler.h"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src/include/libnop/utils.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/libnop.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop/libnopTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop/libnopTargets.cmake"
         "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-build/CMakeFiles/Export/lib/cmake/libnop/libnopTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop/libnopTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop/libnopTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop" TYPE FILE FILES "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-build/CMakeFiles/Export/lib/cmake/libnop/libnopTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop" TYPE FILE FILES "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-build/CMakeFiles/Export/lib/cmake/libnop/libnopTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libnop" TYPE FILE FILES "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-build/libnopConfig.cmake")
endif()

