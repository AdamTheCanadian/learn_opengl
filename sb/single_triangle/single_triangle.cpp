#include "vis/Display.h"
#include "vis/ShaderLoader.h"
#include <iostream>
#include <cmath>

/* Callback anytime a key is pressed */
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
/* Vertex shader source */
static const char* vs_src = {
  "#version 400 core                                                 \n"
  "void main(void)                                                   \n"
  "{                                                                 \n"
  "    const vec4 vertices[] = vec4[](vec4( 0.25, -0.25, 0.5, 1.0),  \n"
  "                                   vec4(-0.25, -0.25, 0.5, 1.0),  \n"
  "                                   vec4( 0.25,  0.25, 0.5, 1.0)); \n"
  "                                                                  \n"
  "    gl_Position = vertices[gl_VertexID];                          \n"
  "}                                             \n"
};

/* Fragment shader source */
static const char* fs_src = {
    "#version 400 core                             \n"
    "out vec4 color;                               \n"
    "void main(void)                               \n"
    "{                                             \n"
    "    color = vec4(0.0, 0.8, 1.0, 1.0);         \n"
    "}                                             \n"
};

int mode = 1;

/*
  This is a modified example of drawing a single point tutorial in 
  the OpenGL Super Bible, listing 2.4
*/
int main() {
  /* Setup window and callback for user input */
  Display display("Single Triangle", 800, 600);
  std::cout << "Display a single triangle" << std::endl;
  display.SetClearColor(1.0f, 0.0f, 0.0f, 1.0f);
  glfwSetKeyCallback(display.GetWindow(), key_callback);

  /* Load shaders and create a shader program */
  unsigned int program = LoadShaders(vs_src, fs_src);
  /* In core OpenGL we require a vertex array object (vao) in order to draw anything */
  unsigned int vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  while (!display.Shutdown()) {
    /* Drawing of our single triangle */
    glUseProgram(program);
    
    if (mode == 1) {
      glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    if (mode == 2) {
      glLineWidth(2.0f);
      glDrawArrays(GL_LINES, 0, 2);
    }
    if (mode == 3) {
      glPointSize(40.0f);
      glDrawArrays(GL_POINT, 0, 1);
    }

    display.Update();
  }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
    mode = 1;
  }
  if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
    mode = 2;
  }
  if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
    mode = 3;
  }
}