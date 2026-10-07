cmake_minimum_required(VERSION 4.2)
project(ed2_elementary_sorting_list03_cpp)

set(CMAKE_CXX_STANDARD 20)

#add_executable(ed2_elementary_sorting_list03_cpp main.cpp
#        src/Exer01_BubbleSortSwapCount.cpp
#        src/Exer02_SelectionKSmallest.cpp
#        src/Exer03_InsertionKSorted.cpp
#        src/Exer04_BubbleParitySort.cpp
#        src/Exer05_InsertionInversions.cpp)

# Cada arquivo .cpp com sua própria função main ganha seu próprio executável independente:
add_executable(Exer01_BubbleSortSwapCount src/Exer01_BubbleSortSwapCount.cpp)
add_executable(Exer02_SelectionKSmallest src/Exer02_SelectionKSmallest.cpp)
add_executable(Exer03_InsertionKSorted src/Exer03_InsertionKSorted.cpp)
add_executable(Exer04_BubbleParitySort src/Exer04_BubbleParitySort.cpp)
add_executable(Exer05_InsertionInversions src/Exer05_InsertionInversions.cpp)

# Se ainda mantiver um main.cpp na raiz, declare-o aqui:
add_executable(main_app main.cpp)
