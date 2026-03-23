#include <GLFW/glfw3.h>
#include <cmath> // Needed for sin and cos
#include <iostream>

int main() {
  if (!glfwInit())
    return -1;

  GLFWwindow *window =
      glfwCreateWindow(800, 800, "Black Hole Singularity", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f); // Darker space
    glClear(GL_COLOR_BUFFER_BIT);

    // --- DRAW CIRCLE START ---
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f); // White circle

    glVertex2f(0.0f, 0.0f); // Center of circle

    int segments = 100;
    float radius = 0.5f;
    for (int i = 0; i <= segments; i++) {
      float theta = 2.0f * M_PI * float(i) / float(segments);
      float x = radius * cosf(theta);
      float y = radius * sinf(theta);
      glVertex2f(x, y);
    }
    glEnd();
    // --- DRAW CIRCLE END ---

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
