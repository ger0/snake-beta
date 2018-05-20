#include "Snake.h"  // what the fuck is this
// includes all header files

void game(Snake& snake, Map& map)
{
    while (snake.isAlive)
    {
        map.draw();
        snake.play();
    }
    clear();
    printw("You scored: %u \n\nPress any key to contunue...", snake.getScore());
    refresh();
    getchar();
}

int main()
{
    srand(time(NULL));

    initscr();
    timeout(500);
    noecho();

    Map map(20, 20);
    Snake snake(map);

    game(snake, map);

    endwin();
    return 0;
}
