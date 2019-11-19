#ifndef APP_H
#define APP_H

#include "window.h"
#include "default_callbacks.h"
#include "event.h"

typedef struct App {
    Window *window;
    bool is_running;
} App;

/* Functions */
App* create_app(const char* title, uint16_t width, uint16_t height, bool fullscreen);
void update_app(App *app);

#endif // APP_H
