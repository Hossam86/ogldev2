#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

#define USE_GLAD

#ifdef USE_GLAD
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>

int main() {
  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    getchar();
    return -1;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  GLFWwindow *window = glfwCreateWindow(1024, 768, "Tutorial01", NULL, NULL);

  if (window == NULL) {
    fprintf(stderr, "Failed to open GLFW window");
    getchar();
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
}
