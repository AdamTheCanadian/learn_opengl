#include "vis/Display.h"
#include "vis/ShaderLoader.h"
#include <iostream>

const char *vs_src = "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "void main()\n"
  "{\n"
  "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
  "}\0";
  
const char *fs_src = "#version 330 core\n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
  "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
  "}\n\0";


int main() {
  Display display("Simple Triangle", 800, 600);
  /* Coordinates of the triangle corners in NDC (normalized device coordinates) */
  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f, 
    0.0f,  0.5f, 0.0f};

  /* 
    Vertex buffer object (VBO) 
    We are allocating memory (buffer) on the GPU that we can then index
    or reference by using the vbo int value 
  */
  unsigned int vbo, vao;
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  /* This sends the vertices data to the GPU. */
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  /* 
    Tells the GPU how to use vertices[]. 
    0 is the layout location (for use in the shader)  
    3 the number of components in the vertex attribute (x y z coordinates)
    GL_FLOAT type
    GL_FALSE because the inputs are already normalized (-1 to 1)
    12 (3 * 4 bytes for a float) stride. This is how many bytes until the next attribute in the buffer
    0 because we are starting at the front of the buffer

    NOTE: notice the first 0 (layout) is the same value as the layout value in the 
    vertex shader source at the top of the program
  */
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  unsigned int shader_program = LoadShaders(vs_src, fs_src);

  while (!display.Shutdown()) {
    glUseProgram(shader_program);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    display.Update();
  }
}