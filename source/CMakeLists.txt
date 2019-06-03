# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  circle.cpp
  rectangle.cpp
  vec2.cpp
  mat2.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

add_executable(aufgabe_2_und_3 aufgabe_2_und_3.cpp)
add_executable(aufgabe_6 aufgabe_6.cpp)
add_executable(aufgabe_9 aufgabe_9.cpp)


add_executable(aufgabe_12 aufgabe_12.cpp)
add_executable(aufgabe_13 aufgabe_13.cpp)
add_executable(aufgabe_14 aufgabe_14.cpp)

add_executable(testList testList.cpp
  vec2.cpp
  mat2.cpp
  circle.cpp

)

# Build tests
add_executable(tests
  glew.c
  tests.cpp
  vec2.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  window.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )


