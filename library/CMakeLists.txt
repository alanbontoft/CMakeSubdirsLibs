add_library(mathlib SHARED MathClass.cpp)

target_include_directories(mathlib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/library)