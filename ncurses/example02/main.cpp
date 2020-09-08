#include <ncurses.h>

int main()
{
    initscr();             
    noecho();              //Выключаем отображение вводимых символов

    char str[100];
    printw("Enter string: ");
    scanw("%s", str);     

    printw("You enter: %s\n", str);
    getch();

    endwin();              
    return 0;
}
