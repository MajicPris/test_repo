# CMakeList.txt: проект CMake для test_repo; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (test_repo "test_repo.cpp" "file1.cpp" "file2.cpp" "pointer_to_func.cpp" "work_with_class.cpp" "work_with_templates.cpp" "FirstNRepeatingStream_v3.cpp" "test_r_values.cpp" "test_r_values.h" "test_copy_constructor.cpp" "test_copy_constructor.h" "move_constructor.cpp" "move_constructor.h" "SmartPointers/test_weak.cpp"  "Problems/1_two_sum.cpp" "Problems/1_two_sum.h" "Problems/2_add_two_numbers.cpp" "Structures/LinkedList.cpp" "Structures/LinkedList.h" "Structures/Stack.h" "Structures/Stack.cpp" "Structures/Queue.h" "Structures/Queue.cpp" "Structures/BinaryTree.h" "Structures/BinaryTree.cpp" "Threads/test_threads.h" "Threads/test_threads.cpp" "Containers/test_containers_if.h" "Containers/test_map.cpp" "Containers/test_vector.cpp" "SmartPointers/test_smartPointers_if.h" "SmartPointers/test_unique.cpp" "SmartPointers/test_shared.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
