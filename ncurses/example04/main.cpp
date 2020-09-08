#include <ncurses.h>

int main()
{
    initscr();

    //Вывод символа "А" в обычном режиме
    printw("Typical symbol \'A\': "); 
    addch('A');

    //Вывод подчёркнутого и жирного символа "А"
    printw("\nUnderline and bold symbol \'A\': ");
    addch('A' | A_BOLD | A_UNDERLINE);

    printw("\nPress any key...");
    getch();
    endwin();
    return 0;
}