#ifndef DEFAULT_CALLBACKS_H
#define DEFAULT_CALLBACKS_H

#include "core/window.h"

void window_close_callback(GLFWwindow*);
void window_size_callback(GLFWwindow* window, int width, int height);
void window_pos_callback(GLFWwindow* window, int xpos, int ypos);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void char_callback(GLFWwindow* window, unsigned int codepoint);
void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

#endif // DEFAULT_CALLBACKS
