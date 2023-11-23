# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.18.4)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(libnop-populate NONE)

include(ExternalProject)
ExternalProject_Add(libnop-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://nop.dainf.ct.utfpr.edu.br/nop-implementations/frameworks/nop-framework-cpp-4-dot-5/nop-framework-cpp-4-dot-5-kernel.git" "GIT_TAG" "main"
                    SOURCE_DIR          "/home/ljtakii/Desktop/cellular_automata/_deps/libnop-src"
                    BINARY_DIR          "/home/ljtakii/Desktop/cellular_automata/_deps/libnop-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


