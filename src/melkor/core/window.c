#include "window.h"

void clear_window()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void update_window(Window *window)
{
    glfwSwapBuffers(window->handle);
    glfwPollEvents();
}

void event_callback(Event *event)
{
    printf("[%ld] ", event->created_at);
    switch(event->type)
    {
        case KEY_PRESS:
            printf("KeyPressEvent: %d\n", ((KeyPressEvent*)event)->key);
            break;
        case KEY_RELEASE:
            printf("KeyReleaseEvent: %d\n", ((KeyReleaseEvent*)event)->key);
            break;
        case KEY_TYPE:
            printf("KeyTypeEvent: %c\n", ((KeyTypeEvent*)event)->key);
            break;
        case CURSOR_POS:
            printf("CursorPosEvent: %f, %f\n", ((CursorPosEvent*)event)->xpos, ((CursorPosEvent*)event)->ypos);
            break;
        case SCROLL:
            printf("ScrollEvent: %f, %f\n", ((ScrollEvent*)event)->xoffset, ((ScrollEvent*)event)->yoffset);
            break;
        case MOUSE_BUTTON_PRESS:
            {
                MouseButtonPressEvent* e = (MouseButtonPressEvent*)event;
                printf("MouseButtonPressEvent: %d %d\n", e->button, e->mods);
                break;
            }
        case MOUSE_BUTTON_RELEASE:
            {
                MouseButtonReleaseEvent* e = (MouseButtonReleaseEvent*)event;
                printf("MouseButtonReleaseEvent: %d %d\n", e->button, e->mods);
                break;
            }
        case WINDOW_SIZE:
        {
            WindowSizeEvent* e = (WindowSizeEvent*)event;
            printf("WindowSizeEvent: %d %d\n", e->width, e->height);
            break;
        }
        case WINDOW_POS:
        {
            WindowPosEvent* e = (WindowPosEvent*)event;
            printf("WindowPosEvent: %d %d\n", e->xpos, e->ypos);
            break;
        }
        case WINDOW_FOCUS:
        {
            WindowFocusEvent* e = (WindowFocusEvent*)event;
            printf("WindowFocusEvent: %s focus\n", e->focus ? "Gained" : "Lost");
            break;
        }
        case WINDOW_CLOSE:
        {
            printf("WindowCloseEvent\n");
            break;
        }
        default:
            printf("Unknown event\n"); // This should never happen
    }
}

Window* create_window(const char* title, uint16_t width,
                      uint16_t height, bool fullscreen)
{
    if (!glfwInit()) {
        printf("Could not initialize GLFW\n");
        return NULL;
    }
    Window *window = malloc(sizeof(Window));
    window->data.title = title;
    window->data.width = width;
    window->data.height = height;
    window->data.fullscreen = fullscreen;
    window->data.vsync = false;
    window->data.event_callback = &event_callback;
    window->handle = glfwCreateWindow(
            width, height, title, NULL, NULL);
    if (!window->handle) {
        printf("Could not create GLFW window\n");
        glfwTerminate();
        free(window);
        return NULL;
    }
    glfwMakeContextCurrent(window->handle);
    glfwSetWindowUserPointer(window->handle, &(window->data));

    /* Set default callbacks */
    glfwSetKeyCallback(window->handle, &key_callback);
    glfwSetCharCallback(window->handle, &char_callback);
    glfwSetCursorPosCallback(window->handle, &cursor_pos_callback);
    glfwSetMouseButtonCallback(window->handle, &mouse_button_callback);
    glfwSetScrollCallback(window->handle, &scroll_callback);
    glfwSetWindowCloseCallback(window->handle, &window_close_callback);
    glfwSetWindowSizeCallback(window->handle, &window_size_callback);
    glfwSetWindowPosCallback(window->handle, &window_pos_callback);
    glfwSetWindowFocusCallback(window->handle, &window_focus_callback);

    return window;
}

void destroy_window(Window* window)
{
    glfwTerminate();
    if (window) free(window);
}
