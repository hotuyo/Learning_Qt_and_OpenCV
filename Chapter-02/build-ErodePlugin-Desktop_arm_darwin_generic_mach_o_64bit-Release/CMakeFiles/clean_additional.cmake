# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/ErodePlugin_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ErodePlugin_autogen.dir/ParseCache.txt"
  "ErodePlugin_autogen"
  )
endif()
