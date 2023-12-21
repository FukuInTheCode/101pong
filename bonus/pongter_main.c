/*
** EPITECH PROJECT, 2023
** 2D pong in the terminal
** File description:
** Placeholder
*/

#include "my.h"

static int draw_map(my_map_t *map)
{
    attron(COLOR_PAIR(1));
    for (int i = 0; i < map->size; i++) {
        mvaddch(map->y + i, map->x, ACS_BLOCK);
        mvaddch(map->y + i, map->x + map->size * 2, ACS_BLOCK);
    }
    for (int i = 0; i <= map->size * 2; i++) {
        mvaddch(map->y, map->x + i, ACS_BLOCK);
        mvaddch(map->y + map->size, map->x + i, ACS_BLOCK);
    }
    attroff(COLOR_PAIR(1));
    return 0;
}

static int draw_player(my_player_t *p, my_map_t *map)
{
    attron(COLOR_PAIR(1));
    for (int i = 0; i < p->demi_size * 2; i++)
        mvaddch(p->y, p->x + i, ACS_BLOCK);
    attroff(COLOR_PAIR(1));
    return 0;
}

static int update_ball(my_ball_t *ball, my_map_t *map, my_player_t *p1, my_player_t *p2)
{
    double dx;
    double dy;

    dx = cos(ball->angle) * ball->velocity;
    dy = sin(ball->angle) * ball->velocity;
    if (!(map->x < ball->x + dx && ball->x + dx < map->x + map->size * 2)) {
        ball->angle *= 2.;
        ball->velocity *= -1.;
    }
    if (!(map->y <= ball->y + dy && ball->y + dy <= map->y + map->size)) {
        mvaddch((int)ball->y, (int)ball->x, ' ');
        ball->x = map->x + map->size;
        ball->y = map->y + map->size / 2.;
        ball->angle = rand() * M_PI * 2;
    }
    if (p1->y == (int)(ball->y + dy) && p1->x <= (int)(ball->x + dx) && (int)(ball->x + dx) <= p1->x + p1->demi_size * 2) {
        ball->angle *= 2.;
        ball->velocity *= -1;
    }
    if (p2->y == (int)(ball->y + dy) && p2->x <= (int)(ball->x + dx) && (int)(ball->x + dx) <= p2->x + p2->demi_size * 2) {
        ball->angle *= 2.;
        ball->velocity *= -1;
    }
    dx = cos(ball->angle) * ball->velocity;
    dy = sin(ball->angle) * ball->velocity;
    mvaddch(ball->y, ball->x, ' ');
    ball->x += dx;
    ball->y += dy;
    attron(COLOR_PAIR(1));
    mvaddch((int)ball->y, (int)ball->x, ACS_BLOCK);
    attroff(COLOR_PAIR(1));
    return 0;
}

static int move_player(my_player_t *p, int dx, int dy, my_map_t *map)
{
    for (int i = 0; i < p->demi_size * 2; i++)
        mvaddch(p->y, p->x + i, ' ');
    p->x += dx;
    p->y += dy;
    p->x = map->x * (p->x <= map->x) + p->x * (p->x > map->x);
    p->x = (map->x + map->size * 2 - p->demi_size * 2) *
        (p->x >= map->x + map->size * 2 - p->demi_size * 2) +
        p->x * (p->x < map->x + map->size * 2 - p->demi_size * 2);
    p->y = map->y * (p->y <= map->y) + p->y * (p->y > map->y);
    p->y = (map->y + map->size) * (p->y >= map->y + map->size) +
        p->y * (p->y < map->y + map->size);
    draw_player(p, map);
    return 0;
}

int main(void)
{
    srand(time(0));
    bool is_active = true;
    int ch = 0;
    my_map_t map = { .x = 39, .y = 6, .size = 24 };
    my_player_t p1 = { .x = map.x + map.size - 2,
        .y = map.y + 3, .demi_size = 4};
    my_player_t p2 = { .x = map.x + map.size - 2, .y = map.y +
        map.size - 3, .demi_size = 4};
    my_ball_t ball = {map.x + map.size, map.y + map.size / 2., 1e-4, rand() * M_PI * 2};

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    timeout(0);
    draw_player(&p1, &map);
    draw_player(&p2, &map);
    while (is_active) {
        ch = getch();
        if (ch != ERR && ch == 27)
            is_active = false;
        if (ch != ERR && ch == 261)
            move_player(&p1, 1, 0, &map);
        if (ch != ERR && ch == 260)
            move_player(&p1, -1, 0, &map);
        if (ch != ERR && ch == 'a')
            move_player(&p2, -1, 0, &map);
        if (ch != ERR && ch == 'd')
            move_player(&p2, 1, 0, &map);
        draw_map(&map);
        update_ball(&ball, &map, &p1, &p2);
        refresh();
    }
    endwin();
    return 0;
}
