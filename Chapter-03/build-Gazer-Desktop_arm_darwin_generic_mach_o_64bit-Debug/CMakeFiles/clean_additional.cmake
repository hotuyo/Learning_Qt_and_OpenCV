# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Gazer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Gazer_autogen.dir/ParseCache.txt"
  "Gazer_autogen"
  )
endif()
