# CMakeList.txt : CMake project for pcap_proj, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (pcap_proj "pcap_proj.cpp" "pcap_proj.h" "PcapHandler.cpp" "PcapHandler.h" "NetworkHeaders.cpp" "NetworkHeaders.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET pcap_proj PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
