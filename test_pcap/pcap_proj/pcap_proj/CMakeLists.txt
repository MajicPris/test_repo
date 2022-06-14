# CMakeList.txt : CMake project for pcap_proj, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

#add_definitions( -DCURL_STATICLIB )

#set( CURL_LIBRARY ${CMAKE_SOURCE_DIR}/lib )
#set( CURL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include )
#find_package( CURL )

#include_directories( ${CURL_INCLUDE_DIRS} )
#link_directories( ${CURL_LIBRARIES} )

# Add source to this project's executable.
add_executable (pcap_proj "pcap_proj.cpp"  "PcapHandler.cpp" "PcapHandler.h" "NetworkHeaders.cpp" "NetworkHeaders.h" "Packet.h" "Packet.cpp")

#target_link_libraries(pcap_proj curl )
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET pcap_proj PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
