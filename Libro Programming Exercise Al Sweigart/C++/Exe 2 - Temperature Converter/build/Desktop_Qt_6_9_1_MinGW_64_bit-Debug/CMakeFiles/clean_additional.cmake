# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TemperatureConverter_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TemperatureConverter_autogen.dir\\ParseCache.txt"
  "TemperatureConverter_autogen"
  )
endif()
