# CMakeList.txt : CMake project for pcap_proj, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

# Add source to this project's executable.
add_executable (pcap_proj "pcap_proj.cpp" )

add_subdirectory("src")

target_link_libraries(pcap_proj PRIVATE src)



# TODO: Add tests and install targets if needed.
