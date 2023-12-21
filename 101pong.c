/*
** EPITECH PROJECT, 2023
** 101pong.c main
** File description:
** Placeholder
*/

#include "my.h"

static int calculate_angle(char **argv, my_vector_t *v)
{
    double t_needed = -1. * atof(argv[6]) / (v->z + (v->z == 0.));

    if ((v->z == 0 || t_needed < 0) && atof(argv[6]) != 0)
        return printf("The ball won’t reach the paddle.\n");
    printf("The incidence angle is:\n");
    printf("%.2lf degrees", 180. / PI * acosf(v->z /
        pow(v->x * v->x + v->y * v->y + v->z * v->z, 1. / 2.)) - 90.);
    return 0;
}

static int calculate_new_pos(char **argv, my_vector_t *v, int t)
{
    printf("At time t + %d, ball coordinates will be:\n", t);
    printf("(%.2lf, %.2lf, %.2lf)\n", v->x * t + atof(argv[4]),
        v->y * t + atof(argv[5]), v->z * t + atof(argv[6]));
    calculate_angle(argv, v);
    return 0;
}

static int calculate_vector(char **argv)
{
    my_vector_t velocity = {
        atof(argv[4]) - atof(argv[1]),
        atof(argv[5]) - atof(argv[2]),
        atof(argv[6]) - atof(argv[3])
    };

    printf("The velocity vector of the ball is:\n");
    printf("(%.2lf, %.2lf, %.2lf)\n", velocity.x, velocity.y, velocity.z);
    return calculate_new_pos(argv, &velocity, atoi(argv[7]));
}

static int show_usage(void)
{
    printf("%s%s%s%s%s%s%s%s%s%s", "USAGE\n",
        "    ./101pong x0 y0 z0 x1 y1 z1 n\n\n",
        "DESCRIPTION\n",
        "    x0 ball abscissa at time t - 1\n",
        "    y0 ball ordinate at time t - 1\n",
        "    z0 ball altitude at time t - 1\n",
        "    x1 ball abscissa at time t\n",
        "    y1 ball ordinate at time t\n",
        "    z1 ball altitude at time t\n",
        "    n time shift (greater than or equal to zero, integer)");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 8)
        return 84;
    if (argc == 2 && !strcmp("-h", argv[1]))
        return show_usage();
    return calculate_vector(argv);
}
