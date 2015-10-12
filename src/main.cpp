#include "WProgram.h"

#include "usb_dev.h"
#include "usb_keyboard.h"
#include "keydefs.h"
#include "chording.h"

#define DEBOUNCE_TIME 3
#define NUM_KEYS 10
int key_inputs[NUM_KEYS] = {KEY_RELEASED};
keyfun key_keycodes[NUM_KEYS][2] = {K(A),
                                    K(S),
                                    K(E),
                                    K(T),
                                    K(SPACE),
                                    K(ENTER),
                                    K(N),
                                    K(I),
                                    K(O),
                                    K(P)};
int key_pins[NUM_KEYS] = {14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
bool key_is_pressed[NUM_KEYS] = {KEY_RELEASED};
bool key_was_pressed[NUM_KEYS] = {KEY_RELEASED};

void update_keys() {
    int i;
    memcpy(key_was_pressed, key_is_pressed, sizeof(key_is_pressed));
    for (i = 0; i < NUM_KEYS; i++) {
        key_is_pressed[i] = digitalRead(key_pins[i]);
    }
}

void key_press(int i) {
    keyfun fun = key_keycodes[i][0];
    fun();
}

void key_release(int i) {
    keyfun fun = key_keycodes[i][1];
    fun();
}

extern "C" int main(void) {
    int i;

    // Set each pin for our keys as an input and enable the pullup resistor on each
    //  pin. This is necessary since we connect our switches to ground.
    for (i = 0; i < NUM_KEYS; i++) {
        pinMode(key_pins[i], INPUT_PULLUP);
    }
    
    usb_init();
	while (1) {
        update_keys();

        for (i = 0; i < NUM_KEYS; i++) {
            if (key_is_pressed[i] && !key_was_pressed[i]) {
                key_press(i);
            }
            else if (key_was_pressed[i] && key_is_pressed[i]) {
                key_release(i);
            }
        }

        usb_keyboard_send();
        delay(DEBOUNCE_TIME);
	}
}

