# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CartoonPlugin_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CartoonPlugin_autogen.dir/ParseCache.txt"
  "CartoonPlugin_autogen"
  )
endif()
