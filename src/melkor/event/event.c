#include "event.h"
#include <stdio.h>

void dispatch_event(Event* event, EventType type, EventCallback callback)
{
    if (event->type == type)
    {
        callback(event);
    }
}

void print_event(Event* event)
{
    printf("[%ld] ", event->created_at);
    switch(event->type)
    {
        case KEY_PRESS:
        {
            KeyPressEvent* e = (KeyPressEvent*)event;
            printf("KeyPressEvent: %d\n", e->key);
            break;
        }
        case KEY_RELEASE:
        {
            KeyReleaseEvent* e = (KeyReleaseEvent*)event;
            printf("KeyReleaseEvent: %d\n", e->key);
            break;
        }
        case KEY_TYPE:
        {
            KeyTypeEvent* e = (KeyTypeEvent*)event;
            printf("KeyTypeEvent: %c\n", e->codepoint);
            break;
        }
        case CURSOR_POS:
        {
            CursorPosEvent* e = (CursorPosEvent*)event;
            printf("CursorPosEvent: %g %g\n", e->xpos, e->ypos);
            break;
        }
        case SCROLL:
        {
            ScrollEvent* e = (ScrollEvent*)event;
            printf("ScrollEvent: %g %g\n", e->xoffset, e->yoffset);
            break;
        }
        case MOUSE_BUTTON_PRESS:
        {
            MouseButtonPressEvent* e = (MouseButtonPressEvent*)event;
            printf("MouseButtonPressEvent: %d\n", e->button);
            break;
        }
        case MOUSE_BUTTON_RELEASE:
        {
            MouseButtonReleaseEvent* e = (MouseButtonReleaseEvent*)event;
            printf("MouseButtonReleaseEvent: %d\n", e->button);
            break;
        }
        case WINDOW_CLOSE:
            printf("WindowCloseEvent\n");
            break;
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
            printf("WindowFocusEvent: %s focus\n", e->focus ? "Gained": "Lost");
            break;
        }
        default:
            printf("Unknown event\n");
    }
}
