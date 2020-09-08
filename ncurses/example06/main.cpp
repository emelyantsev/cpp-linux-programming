#include <ncurses.h>

int main()
{
    const char *mesg = "Just a string";

    initscr();

    addstr(mesg);

    getch();    
    endwin();
    return 0;
}
