#include <ncurses.h>

#if defined(_WIN32) || defined(_WIN64) 
    #include <windows.h>
    #define msleep(msec) Sleep(msec)
#else
    #include <unistd.h>
    #define msleep(msec) usleep(msec*1000)
#endif

int main()
{
    initscr();

    char str[100];
    addstr("Enter string: ");
    getstr(str); //Считваем строку
    curs_set(0); //"Убиваем" курсор, чтобы не мешался
    
    while ( true )
    {
    //Перемещаем х-координату как можно дальше вправо, и будем уменьшать её, пока она != 0
        for ( unsigned x = getmaxx(stdscr); x; x-- ) 
        {
            clear();
            mvaddstr(getmaxy(stdscr) / 2, x, str);
            refresh();
            msleep(200);
        }
    }

    endwin();
    return 0;
}