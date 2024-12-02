cmake_minimum_required(VERSION 3.28)
project(Proyecto)

set(CMAKE_CXX_STANDARD 17)

# Set the path to your SFML installation
set(SFML_DIR "C:/Users/frpat/Downloads/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit (1)/SFML-2.6.2/lib/cmake/SFML") # Replace with your actual SFML path

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Add your executable
add_executable(Proyecto main.cpp
        SearchMenu.h
        SearchMenu.cpp
        SearchMenu.cpp
        LinearSearch.h
        LinearSearch.cpp
        BinarySearch.h
        BinarySearch.cpp
        SortMenu.h
        SortMenu.cpp
        BubbleSort.h
        BubbleSort.cpp
        SelectionSort.h
        InsertionSort.h
        MergeSort.h
        QuickSort.h
        SelectionSort.cpp
        InsertionSort.cpp
        InsertionSort.cpp
        MergeSort.cpp
        QuickSort.cpp)

# Link SFML libraries
target_link_libraries(Proyecto sfml-system sfml-window sfml-graphics)

