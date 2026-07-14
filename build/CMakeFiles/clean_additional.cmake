# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  [[src\CMakeFiles\tictactoe_autogen.dir\AutogenUsed.txt]]
  [[src\CMakeFiles\tictactoe_autogen.dir\ParseCache.txt]]
  [[src\tictactoe_autogen]]
  )
endif()
