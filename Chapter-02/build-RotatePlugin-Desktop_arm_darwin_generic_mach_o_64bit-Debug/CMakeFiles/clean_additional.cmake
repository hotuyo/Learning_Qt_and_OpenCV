# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/RotatePlugin_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/RotatePlugin_autogen.dir/ParseCache.txt"
  "RotatePlugin_autogen"
  )
endif()
