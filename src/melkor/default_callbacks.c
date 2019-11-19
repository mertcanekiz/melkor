#include "default_callbacks.h"
#include "event.h"
#include <time.h>

void window_close_callback(GLFWwindow* window)
{
    printf("WindowCloseEvent\n");
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);
    switch (action) {
        case GLFW_PRESS:
            {
                KeyPressEvent event = {
                    { time(0), KEY_PRESS },
                    key,
                    0
                };
                data->event_callback((Event*)(&event));
            }
            break;
        case GLFW_RELEASE:
            {
                KeyReleaseEvent event = {
                    { time(0), KEY_RELEASE },
                    key
                };
                data->event_callback((Event*)(&event));
            }
            break;
        case GLFW_REPEAT:
            {
                KeyPressEvent event = {
                    { time(0), KEY_PRESS },
                    key,
                    1
                };
                data->event_callback((Event*)(&event));
            }
            break;
    }
}

void char_callback(GLFWwindow* window, unsigned int codepoint)
{
    WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);
    KeyTypeEvent event = {
        { time(0), KEY_TYPE },
        codepoint
    };
    data->event_callback((Event*)(&event));
}

void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos)
{
    WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);
    CursorPosEvent event = {
        { time(0), CURSOR_POS },
        xpos, ypos
    };
    data->event_callback((Event*)(&event));
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);
    ScrollEvent event = {
        { time(0), SCROLL },
        xoffset, yoffset
    };
    data->event_callback((Event*)(&event));
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);
    switch (action) {
        case GLFW_PRESS:
        {
            MouseButtonPressEvent event = {
                { time(0), MOUSE_BUTTON_PRESS },
                button, mods
            };
            data->event_callback((Event*)(&event));
            break;
        }
        case GLFW_RELEASE:
        {
            MouseButtonReleaseEvent event = {
                { time(0), MOUSE_BUTTON_RELEASE },
                button, mods
            };
            data->event_callback((Event*)(&event));
            break;
        }
    }
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
    WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);
    WindowSizeEvent event = {
        { time(0), WINDOW_SIZE },
        width,
        height
    };
    data->event_callback((Event*)(&event));
}

void window_pos_callback(GLFWwindow* window, int xpos, int ypos)
{
    WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);
    WindowPosEvent event = {
        { time(0), WINDOW_POS },
        xpos,
        ypos
    };
    data->event_callback((Event*)(&event));
}

