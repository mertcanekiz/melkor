#include "app.h"

App* create_app(const char* title, uint16_t width,
                uint16_t height, bool fullscreen)
{
    App *app = malloc(sizeof(App));
    app->window = create_window(
            title,
            width,
            height,
            fullscreen
            );
    if (!app->window) {
        printf("Error while creating window!\n");
        exit(EXIT_FAILURE);
    }
    set_callback(app->window, KEY_CALLBACK, &key_callback);
    set_callback(app->window, WINDOW_CLOSE_CALLBACK, &window_close_callback);
    set_callback(app->window, CHAR_CALLBACK, &char_callback);
    set_callback(app->window, MOUSE_BUTTON_CALLBACK, &mouse_button_callback);
    set_callback(app->window, CURSOR_POS_CALLBACK, &cursor_pos_callback);
    set_callback(app->window, SCROLL_CALLBACK, &scroll_callback);
    set_callback(app->window, WINDOW_POS_CALLBACK, &window_pos_callback);
    set_callback(app->window, WINDOW_SIZE_CALLBACK, &window_size_callback);
    return app;
}

void update_app(App *app)
{
    app->is_running =
        !glfwWindowShouldClose(app->window->handle);
}
