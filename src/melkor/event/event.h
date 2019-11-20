#ifndef EVENT_H
#define EVENT_H

#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

/* Enums */
typedef enum EventType {
    EVENTTYPE_NONE = 0,
    WINDOW_CLOSE, WINDOW_SIZE, WINDOW_FOCUS, WINDOW_POS,
    KEY_PRESS, KEY_RELEASE, KEY_TYPE,
    MOUSE_BUTTON_PRESS, MOUSE_BUTTON_RELEASE, SCROLL, CURSOR_POS,
    APP_TICK, APP_UPDATE, APP_RENDER
} EventType;

typedef enum EventCategory {
    EVENTCATEGORY_NONE = 0,
    APP           = 1 << 0,
    INPUT         = 1 << 1,
    KEYBOARD      = 1 << 2,
    MOUSE         = 1 << 3,
    MOUSEBUTTON   = 1 << 4
} EventCategory;

/* Structs */
typedef struct Event
{
    time_t created_at;
    EventType type;
    EventCategory category;
} Event;

typedef void (*EventCallback)(Event*);
typedef struct WindowCloseEvent
{
    Event super;
} WindowCloseEvent;

typedef struct KeyPressEvent
{
    Event super;
    int key;
    int repeats;
} KeyPressEvent;

typedef struct KeyReleaseEvent {
    Event super;
    int key;
} KeyReleaseEvent;

typedef struct KeyRepeatEvent {
    Event super;
    int key;
    int repeat;
} KeyRepeatEvent;

typedef struct KeyTypeEvent {
    Event super;
    int codepoint;
} KeyTypeEvent;

typedef struct CursorPosEvent {
    Event super;
    double xpos;
    double ypos;
} CursorPosEvent;

typedef struct ScrollEvent {
    Event super;
    double xoffset;
    double yoffset;
} ScrollEvent;

typedef struct MouseButtonPressEvent {
    Event super;
    int button;
    int mods;
} MouseButtonPressEvent;

typedef struct MouseButtonReleaseEvent {
    Event super;
    int button;
    int mods;
} MouseButtonReleaseEvent;

typedef struct WindowPosEvent {
    Event super;
    int xpos;
    int ypos;
} WindowPosEvent;

typedef struct WindowSizeEvent {
    Event super;
    int width;
    int height;
} WindowSizeEvent;

typedef struct WindowFocusEvent {
    Event super;
    bool focus;
} WindowFocusEvent;

void dispatch_event(Event* event, EventType type, EventCallback callback);
void print_event(Event* event);
#endif
