#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include <iostream>

#define GL_SILENCE_DEPRECATION

int main(void) {
  GLFWwindow *window;

  // initialize library
  if (!glfwInit())
    return -1;

  // create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(640, 480, "black hole sim", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  // make the window's context current
  glfwMakeContextCurrent(window);

  // glewExperimental must be set to true in order to use modern OpenGL
  // functions
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cout << "GLEW error!" << std::endl;
  }

  std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

  float positions[6] = {
      -0.5f, -0.5f, // vertex 1
      0.0f,  0.5f,  // vertex 2
      0.5f,  -0.5f  // vertex 3
  };

  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

  // loop until the user closes the window
  while (!glfwWindowShouldClose(window)) {
    // render here
    glClear(GL_COLOR_BUFFER_BIT);

    // draw a triangle from the 3 vertices
    glDrawArrays(GL_CIRCULAR_CCW_ARC_TO_NV, 0, 3);

    // swap front and back buffers
    glfwSwapBuffers(window);

    // poll for and process events
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
