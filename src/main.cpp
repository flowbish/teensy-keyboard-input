#include "WProgram.h"

// define information about our usb device
#define USB_KEYBOARD
#include "usb_dev.h"
#include "usb_keyboard.h"

extern "C" int main(void) {

    uint8_t chars[] = "abcdefghijklmnopqrstuvwxyz1234567890-="
                      "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+";
    
    usb_init();
	while (1) {
        size_t c = random() % sizeof(chars);
        usb_keyboard_write(chars[c]);
        delay(30);
	}
}

