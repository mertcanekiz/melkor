#ifndef EVENT_H
#define EVENT_H

#include <time.h>

/* Defines */
#define EVENT_CATEGORY_NONE        0
#define EVENT_CATEGORY_APP         1 << 1
#define EVENT_CATEGORY_INPUT       1 << 2
#define EVENT_CATEGORY_KEYBOARD    1 << 3
#define EVENT_CATEGORY_MOUSE       1 << 4
#define EVENT_CATEGORY_MOUSEBUTTON 1 << 5

/* Enums */
typedef enum EventType {
    NONE = 0,
    WINDOW_CLOSE, WINDOW_SIZE, WINDOW_FOCUS, WINDOW_POS,
    KEY_PRESS, KEY_RELEASE, KEY_TYPE,
    MOUSE_BUTTON_PRESS, MOUSE_BUTTON_RELEASE, SCROLL, CURSOR_POS,
    APP_TICK, APP_UPDATE, APP_RENDER
} EventType;

/* Structs */
typedef struct Event
{
    time_t created_at;
    EventType type;
} Event;

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
    int key;
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
#endif
