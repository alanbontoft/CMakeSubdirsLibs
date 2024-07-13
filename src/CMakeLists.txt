
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} mathlib pthread)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../library)