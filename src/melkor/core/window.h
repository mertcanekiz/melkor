#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#include "event/event.h"
#include "event/callbacks.h"

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
