#include <ncurses.h>

int main()
{
    initscr();

    int a, b;
    char c;

    scanw("%d%c%d", &a, &c, &b);

    printw("%d %c %d = ", a, c, b);
    switch ( c )
    {
        case '+':
            printw("%d", a + b);
            break;

        case '-':
            printw("%d", a - b);
            break;

        case '*':
            printw("%d", a * b);
            break;

        case '/':
            if ( !b )
                printw("ERROR");
            else printw("%f", static_cast<double>(a) / b);
            break;
        default:
            printw("ERROR");
            break;
    }

    getch();
    endwin();
    return 0;
}
