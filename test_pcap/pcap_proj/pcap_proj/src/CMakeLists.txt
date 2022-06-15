
cmake_minimum_required (VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
add_library(src "")

target_sources(src
  PRIVATE
    PcapHandler.cpp
    NetworkHeaders.cpp
    Packet.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/PcapHandler.h
    ${CMAKE_CURRENT_LIST_DIR}/NetworkHeaders.h
    ${CMAKE_CURRENT_LIST_DIR}/Packet.h
  )
target_include_directories(src
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

