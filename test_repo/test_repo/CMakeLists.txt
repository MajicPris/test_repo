# CMakeList.txt: проект CMake для test_repo; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (test_repo "test_repo.cpp" "file1.cpp" "file2.cpp" "pointer_to_func.cpp" "work_with_class.cpp" "work_with_templates.cpp" "FirstNRepeatingStream_v3.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
