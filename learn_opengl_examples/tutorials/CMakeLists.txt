## Chapter 1
add_executable(hello_window hello_window.cpp)
target_link_libraries(hello_window vis)

## Chapter 2
add_executable(simple_triangle simple_triangle.cpp)
target_link_libraries(simple_triangle vis)
add_executable(simple_rectangle_index simple_rectangle_index.cpp)
target_link_libraries(simple_rectangle_index vis)
add_executable(colorful_triangle colorful_triangle.cpp)
target_link_libraries(colorful_triangle vis)

add_executable(textured_container textured_container.cpp)
target_link_libraries(textured_container vis)

add_executable(transformations transformations.cpp)
target_link_libraries(transformations vis)

add_executable(transformations_user_control transformations_user_control.cpp)
target_link_libraries(transformations_user_control vis)

add_executable(coordinate_system coordinate_system.cpp)
target_link_libraries(coordinate_system vis)

add_executable(cubes cubes.cpp)
target_link_libraries(cubes vis)

add_executable(camera camera.cpp)
target_link_libraries(camera vis)

add_executable(camera_mouse camera_mouse.cpp)
target_link_libraries(camera_mouse vis)