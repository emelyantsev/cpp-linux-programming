#include <ncurses.h>
#include <cstring>

int main()
{
    const char *mesg = "Just a string";

    //Количество строк и столбцов на экране терминала
    int row, col;   

    initscr();

    //Получаем максимально возможное количество строк и столбцов для окна stdscr и записываем эти данные в row и col
    getmaxyx(stdscr, row, col); 

    //Выводим сообщение в центре окна stdscr
    mvwprintw(stdscr, row / 2, (col - strlen(mesg)) / 2, "%s", mesg);

    //Выводим информацию о количестве строк и столбцов в левом нижнем углу экрана
    mvwprintw(stdscr, row - 1, 0, "The number of rows - %d and columns - %d\n", row, col);

    getch();    
    endwin();
    return 0;
}