# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src")
  file(MAKE_DIRECTORY "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-src")
endif()
file(MAKE_DIRECTORY
  "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-build"
  "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-subbuild/libnop-populate-prefix"
  "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-subbuild/libnop-populate-prefix/tmp"
  "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp"
  "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-subbuild/libnop-populate-prefix/src"
  "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/ljtakii/Downloads/cellular_automata_takii/cellular_automata_pon/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
