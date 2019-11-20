#ifndef APP_H
#define APP_H

#include "window.h"
#include "event/event.h"

typedef struct App {
    Window *window;
    bool is_running;
    EventCallback event_callback;
} App;

/* Functions */
App* create_app(const char* title, uint16_t width, uint16_t height, bool fullscreen);
void on_app_update(Event*);
void on_window_close(Event*);
void set_event_callback(EventCallback callback);

#endif // APP_H
