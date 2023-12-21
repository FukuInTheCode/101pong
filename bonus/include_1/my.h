/*
** EPITECH PROJECT, 2023
** Bonus1 my.h
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <curses.h>
    #include <pthread.h>
    #include <stdlib.h>
    #include <criterion/criterion.h>
    #include <criterion/redirect.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/GPUPreference.h>
    #include <SFML/Network.h>
    #include <SFML/OpenGL.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

typedef struct {
    int x;
    int y;
    int demi_size;
} my_player_t;

typedef struct {
    int x;
    int y;
    int size;
} my_map_t;

typedef struct {
    double x;
    double y;
    double velocity;
    float angle;
} my_ball_t;

#endif
