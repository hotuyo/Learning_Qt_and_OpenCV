# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles/ImageEditor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ImageEditor_autogen.dir/ParseCache.txt"
  "ImageEditor_autogen"
  )
endif()
