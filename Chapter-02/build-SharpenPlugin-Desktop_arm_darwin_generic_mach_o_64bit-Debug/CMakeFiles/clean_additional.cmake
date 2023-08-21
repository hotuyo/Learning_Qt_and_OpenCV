# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SharpenPlugin_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SharpenPlugin_autogen.dir/ParseCache.txt"
  "SharpenPlugin_autogen"
  )
endif()
