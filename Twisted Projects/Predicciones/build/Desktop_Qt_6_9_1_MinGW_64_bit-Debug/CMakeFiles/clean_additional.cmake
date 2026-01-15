# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Predicciones_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Predicciones_autogen.dir\\ParseCache.txt"
  "Predicciones_autogen"
  )
endif()
