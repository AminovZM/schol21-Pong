#include <stdio.h>

void Graphic(int Rocket_1Y, int Rocket_2Y, int height, int width, int ball_X, int ball_Y) {
    printf("\033[H\033[J");
    for (int i = 0; i < height; i++) {
        if (i == 0 || i == height - 1) {
            for (int j = 0; j < width; j++) {
                if (j == 0 || j == width - 1) {
                    putchar('*');
                } else {
                    putchar('-');
                }
            }
            putchar('\n');
        } else {
            putchar('|');
            for (int j = 1; j < width - 1; j++) {
                if (j == 1) {
                    if (i > Rocket_1Y && i < Rocket_1Y + 4) {
                        putchar('R');
                    } else {
                        putchar(' ');
                    }
                } else if (j == width - 2) {
                    if (i > Rocket_2Y && i < Rocket_2Y + 4) {
                        putchar('R');
                    } else {
                        putchar(' ');
                    }
                } else if (j == ball_X && i == ball_Y) {
                    putchar('O');
                } else {
                    putchar(' ');
                }
                if (j == 38) putchar('i');
            }
            putchar('|');
            putchar('\n');
        }
    }
}

int main() {
    int Rocket_1Y = 11, Rocket_2Y = 11, ball_X = 40, ball_Y = 12, height = 25, width = 80, mov_ball_X = -1,
        mov_ball_Y = 1, Player_1 = 0, Player_2 = 0, turn = 1;
    char key;
    while (1) {
        Graphic(Rocket_1Y, Rocket_2Y, height, width, ball_X, ball_Y);
        if (Player_1 == 21) {
            printf("PLAYER 1 WIN!!");
            break;
        }
        if (Player_2 == 21) {
            printf("PLAYER 2 WIN!!");
            break;
        }
        printf("player's move %d, game score %d:%d\n", turn, Player_1, Player_2);
        scanf("%c", &key);
        if (key == 'A' || key == 'Z' || key == 'K' || key == 'M' || key == ' ' || key == 'q' || key == 'Q') {
            ball_X += mov_ball_X;
            ball_Y += mov_ball_Y;
            if (ball_Y == 23 || ball_Y == 2) mov_ball_Y = mov_ball_Y * -1;
            if (ball_X == 2 || ball_X == 77) mov_ball_X = mov_ball_X * -1;
            if (ball_X == 4 && ball_Y >= Rocket_1Y && ball_Y <= Rocket_1Y + 3) mov_ball_X = mov_ball_X * -1;
            if (ball_X == width - 3 && ball_Y >= Rocket_2Y && ball_Y <= Rocket_2Y + 3)
                mov_ball_X = mov_ball_X * -1;
            if (ball_X == 2) Player_2 += 1;
            if (ball_X == 77) Player_1 += 1;
            if (key == 'q' || key == 'Q') break;
            if (turn == 1) {
                if (key == ' ') {
                    turn = 2;
                }
                if (key == 'A' || key == 'Z') {
                    if (key == 'A' && Rocket_1Y > 0) {
                        Rocket_1Y--;
                    } else if (key == 'Z' && Rocket_1Y + 4 < height - 1) {
                        Rocket_1Y++;
                    }
                    turn = 2;
                }
            } else if (turn == 2) {
                if (key == ' ') {
                    turn = 1;
                }
                if (key == 'M' || key == 'K') {
                    if (key == 'K' && Rocket_2Y > 0) {
                        Rocket_2Y--;
                    } else if (key == 'M' && Rocket_2Y + 4 < height - 1) {
                        Rocket_2Y++;
                    }
                    turn = 1;
                }
            } else if (key == ' ') {
                printf("1");
            } else if (key == 'q' || key == 'Q') {
                break;
            }
        } else {
        }
    }
    return 0;
}
