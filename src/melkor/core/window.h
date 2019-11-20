#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#include "event/event.h"

/* Callback typedefs */
typedef void (*KeyCallback)(GLFWwindow *window, int key, int scancode, int action, int mods);
typedef void (*CharCallback)(GLFWwindow *window, unsigned int codepoint);
typedef void (*CursorPosCallback)(GLFWwindow *window, double xpos, double ypos);
typedef void (*MouseButtonCallback)(GLFWwindow *window, int button, int action, int mods);
typedef void (*ScrollCallback)(GLFWwindow *window, double xoffset, double yoffset);
typedef void (*WindowCloseCallback)(GLFWwindow* window);
typedef void (*WindowSizeCallback)(GLFWwindow* window, int width, int height);
typedef void (*WindowPosCallback)(GLFWwindow* window, int xpos, int ypos);
typedef void (*EventCallback)(Event*);

typedef enum CallbackType {
    KEY_CALLBACK = 0,
    CHAR_CALLBACK,
    CURSOR_POS_CALLBACK,
    MOUSE_BUTTON_CALLBACK,
    SCROLL_CALLBACK,
    WINDOW_CLOSE_CALLBACK,
    WINDOW_SIZE_CALLBACK,
    WINDOW_POS_CALLBACK
} CallbackType;

// typedef struct WindowData WindowData;
typedef struct WindowData
{
    const char *title;
    uint16_t width;
    uint16_t height;
    bool vsync;
    bool fullscreen;
    EventCallback event_callback;
} WindowData;
/* Window class */
typedef struct Window {
    WindowData data;
    GLFWwindow *handle;
} Window;


/* Functions */
void clear_window();
void update_window(Window *window);
Window* create_window(const char* title, uint16_t width,
                      uint16_t height, bool fullscreen);
void destroy_window(Window* window);
void set_callback(Window *window, CallbackType type, void* callback);

#endif // WINDOW_H
