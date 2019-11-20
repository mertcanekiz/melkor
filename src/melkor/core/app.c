#include "app.h"

/* Global app */
App *app = NULL;

App* create_app(const char* title, uint16_t width,
                uint16_t height, bool fullscreen)
{
    app = malloc(sizeof(App));
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
    app->window->data.event_callback = &on_app_update;
    return app;
}

void on_app_update(Event *event)
{
    dispatch_event(event, WINDOW_CLOSE, &on_window_close);
    app->event_callback(event);
}

void set_event_callback(EventCallback callback)
{
    app->event_callback = callback;
}

void on_window_close(Event *event)
{
    app->is_running = false;
}

void update_app(App *app)
{
    app->is_running =
        !glfwWindowShouldClose(app->window->handle);
}
