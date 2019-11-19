#include <melkor.h>

int main(int argc, char** argv)
{
    printf("Melkor Engine v0.1\n");
    App *app = create_app("melkor engine v0.1",
                          640, 480, false);
//    set_callback(app->window, KEY_CALLBACK, &key_callback);
//    set_callback(app->window, WINDOW_CLOSE_CALLBACK, &window_close_callback);
    app->is_running = true;
    while (app->is_running) {
        clear_window();
        update_window(app->window);
        update_app(app);
    }
    destroy_window(app->window);
    free(app);
    return 0;
}
