# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\passwordManager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\passwordManager_autogen.dir\\ParseCache.txt"
  "passwordManager_autogen"
  )
endif()
