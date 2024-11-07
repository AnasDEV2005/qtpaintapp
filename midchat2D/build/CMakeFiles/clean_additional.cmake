# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Midchat2D_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Midchat2D_autogen.dir/ParseCache.txt"
  "Midchat2D_autogen"
  )
endif()
