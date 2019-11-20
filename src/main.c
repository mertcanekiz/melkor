#include <melkor.h>

void custom_event_callback(Event* event)
{
    print_event(event);
}

int main(int argc, char** argv)
{
    printf("Melkor Engine v0.1\n");
    App *app = create_app("melkor engine v0.1",
                          640, 480, false);
    app->is_running = true;
    set_event_callback(&custom_event_callback);
    while (app->is_running) {
        clear_window();
        update_window(app->window);
    }
    destroy_window(app->window);
    free(app);
    return 0;
}
