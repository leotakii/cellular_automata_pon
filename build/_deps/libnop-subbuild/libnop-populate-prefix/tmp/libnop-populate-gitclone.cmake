
if(NOT "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp/libnop-populate-gitinfo.txt" IS_NEWER_THAN "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp/libnop-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp/libnop-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --config "advice.detachedHead=false" "https://nop.dainf.ct.utfpr.edu.br/nop-implementations/frameworks/nop-framework-cpp-4-dot-5/nop-framework-cpp-4-dot-5-kernel.git" "libnop-src"
    WORKING_DIRECTORY "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://nop.dainf.ct.utfpr.edu.br/nop-implementations/frameworks/nop-framework-cpp-4-dot-5/nop-framework-cpp-4-dot-5-kernel.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout main --
  WORKING_DIRECTORY "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'main'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp/libnop-populate-gitinfo.txt"
    "/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp/libnop-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/mnt/c/Users/Pc/Downloads/cellular_automata_ihaaa_jun_12_2023/cellular_automata/build/_deps/libnop-subbuild/libnop-populate-prefix/src/libnop-populate-stamp/libnop-populate-gitclone-lastrun.txt'")
endif()

