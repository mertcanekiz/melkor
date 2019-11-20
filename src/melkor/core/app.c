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
    return app;
}

void update_app(App *app)
{
    app->is_running =
        !glfwWindowShouldClose(app->window->handle);
}
