# CMakeList.txt : CMake project for bitwuzla_api_from_cpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project("bitwuzla_jni")

SET(BITBUZLA_INCLUDE_DIR "C:\\repositories\\OpenSource\\bitwuzla\\bitwuzla_jni\\lib\\include")
SET(BITWUZLA_BIN "C:\\repositories\\OpenSource\\bitwuzla\\bitwuzla_jni\\lib\\bin\\bitwuzla.lib")
SET(LIBGIMP_BIN "C:\\repositories\\OpenSource\\bitwuzla\\bitwuzla_jni\\lib\\bin\\libgmp-10.lib")
include_directories("c:\\Program Files\\Java\\jdk-17.0.1\\include") #JAVA_HOME
include_directories("c:\\Program Files\\Java\\jdk-17.0.1\\include\\win32")
link_directories("c:\\Program Files\\Java\\jdk-17.0.1\\include")
link_directories("c:\\Program Files\\Java\\jdk-17.0.1\\include\\win32")

add_library (bitwuzla_jni SHARED "bitwuzla_jni.cpp" "bitwuzla_jni.hpp" "bzla_proxy.c" "bzla_proxy.h")
target_include_directories(bitwuzla_jni PRIVATE ${BITBUZLA_INCLUDE_DIR})
target_link_libraries(bitwuzla_jni PRIVATE ${BITWUZLA_BIN})
target_link_libraries(bitwuzla_jni PRIVATE ${LIBGIMP_BIN})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET bitwuzla_jni PROPERTY CXX_STANDARD 20)
endif()

if (MSVC)
    # remove default warning level from CMAKE_CXX_FLAGS
    string (REGEX REPLACE "EHsc" "EHs" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()