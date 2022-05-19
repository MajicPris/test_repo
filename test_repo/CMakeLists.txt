# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("test_repo")

# Включите подпроекты.
add_subdirectory ("test_repo")
include_directories("${CMAKE_SOURCE_DIR}/Problems")
set_property (TARGET "test_repo"
  PROPERTY
    # Enable C++17 standard compliance
    CXX_STANDARD 17
)