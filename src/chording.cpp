#include "keydefs.h"
#include "chording.h"

#define DEF(name) void P(name) () {}\
                  void R(name) () {}

void P(A) () {
    usb_keyboard_press_keycode(KEY(A));
}

void R(A) () {
    usb_keyboard_release_keycode(KEY(A));
}

void P(S) () {
    usb_keyboard_press_keycode(KEY(S));
}

void R(S) () {
    usb_keyboard_release_keycode(KEY(S));
}

void P(E) () {
    usb_keyboard_press_keycode(KEY(E));
}

void R(E) () {
    usb_keyboard_release_keycode(KEY(E));
}

void P(T) () {
    usb_keyboard_press_keycode(KEY(T));
}

void R(T) () {
    usb_keyboard_release_keycode(KEY(T));
}

DEF(SPACE)
DEF(ENTER)
DEF(N)
DEF(I)
DEF(O)
DEF(P)
