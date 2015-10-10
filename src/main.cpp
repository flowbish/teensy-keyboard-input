#include "WProgram.h"

#include "usb_dev.h"
#include "usb_keyboard.h"
#include "keydefs.h"


#define USB_IDLE_RATE 500

/**
 * Use SPI with the following pins
 * SS = PIN_10
 * SCK = PIN_13
 * MOSI = PIN_11
 * MISO = PIN_12
 */

#define NUM_KEYS 10
int key_inputs[NUM_KEYS] = {KEY_RELEASED};
int key_keycodes[NUM_KEYS] = {KEY(A),
                              KEY(S),
                              KEY(E),
                              KEY(T),
                              KEY(SPACE),
                              KEY(ENTER),
                              KEY(N),
                              KEY(I),
                              KEY(O),
                              KEY(P)};
int key_pins[NUM_KEYS] = {14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

extern "C" int main(void) {
    int i;

    // Set each pin for our keys as an input and enable the pullup resistor on each
    //  pin. This is necessary since we connect our switches to ground.
    for (i = 0; i < NUM_KEYS; i++) {
        pinMode(key_pins[i], INPUT_PULLUP);
    }
    
    usb_init();
	while (1) {
        int current_inputs[NUM_KEYS] = {KEY_PRESSED};

        // Read the status of each switch connected (digital 0 means pressed).
        for (i = 0; i < NUM_KEYS; i++) {
            current_inputs[i] = digitalRead(key_pins[i]);

            // test for falling edge (press)
            // TODO: debounce
            if (current_inputs[i] == KEY_PRESSED && key_inputs[i] == KEY_RELEASED) {
                usb_keyboard_press_keycode(key_keycodes[i]);
            }

            // test for rising edge (release)
            // TODO: debounce
            else if (current_inputs[i] == KEY_RELEASED && key_inputs[i] == KEY_PRESSED) {
                usb_keyboard_release_keycode(key_keycodes[i]);
            }

            key_inputs[i] = current_inputs[i];
        }
        delayMicroseconds(3000);
	}
}

