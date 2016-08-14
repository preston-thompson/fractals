#include <stdio.h>
#include <math.h>

#include "../graphics/graphics.h"
#include "../graphics/turtle.h"

#define WIDTH 800
#define HEIGHT 600
#define FILENAME "output.ppm"
#define ITERATIONS 10
#define ANGLE (M_PI_2 / 5)

void draw_branch(
    int i,
    float a,
    struct turtle *t1
) {
    struct turtle t2;

    if (!i)
        return;

    move_turtle(t1, 6 * i, 1);
    t2 = *t1;
    turn_turtle(t1, a);
    turn_turtle(&t2, -a);
    draw_branch(i - 1, a, t1);
    draw_branch(i - 1, a, &t2);
}

int main(int argc, char **argv) {
    int i;
    struct image *img = new_image(WIDTH, HEIGHT);
    struct turtle t = {
        WIDTH / 2,
        HEIGHT,
        0,
        (struct color){0, 0, 0},
        img
    };

    fill_image(img, (struct color){255, 255, 255});

    turn_turtle(&t, M_PI_2);
    draw_branch(ITERATIONS, ANGLE, &t);

    save_image(img, FILENAME);
    return 0;
}
