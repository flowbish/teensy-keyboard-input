/**
 * teensy-keyboard-input
 * Copyright (c) 2015 Porter Smith
 */

#ifndef KEYDEFS_H__
#define KEYDEFS_H__

/**
 * Use SPI with the following pins
 * SS = PIN_10
 * SCK = PIN_13
 * MOSI = PIN_11
 * MISO = PIN_12
 */

#define KEY(k) KEY_##k
#define KEY_PRESSED 0
#define KEY_RELEASED 1

typedef void (*keyfun)(void);

#define P(name) keys__press__##name
#define R(name) keys__release__##name
#define K(name) { &keys__press__##name, &keys__release__##name }
#define KF(name) key_functions__##name
#define DECL(name) void P(name)(void);\
                   void R(name)(void);



#endif 
