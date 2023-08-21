# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AffinePlugin_autogen"
  "CMakeFiles/AffinePlugin_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/AffinePlugin_autogen.dir/ParseCache.txt"
  )
endif()
