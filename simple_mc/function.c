#include "function.h"

void printLeftWindow(WINDOW *left_win, struct dirent **data, int highlight, int n) {
    int x = 1, y = 1;

    box(left_win, 0, 0);
    struct stat st;

    wbkgd(left_win, COLOR_PAIR(1));

    for (int i = n - 1; i >= 0; --i) {
        stat(data[i]->d_name, &st);
        char *time = printTime(&st);
        if (highlight == i + 1) {
            wattron(left_win, A_REVERSE);
            mvwprintw(left_win, y, x, data[i]->d_name);
            mvwprintw(left_win, y, (COLS / 2) - 24, "%d", st.st_size);
            mvwprintw(left_win, y, (COLS / 2) - 14, "%s", time);
            wattroff(left_win, A_REVERSE);
        } else {
            wrefresh(left_win);
            mvwprintw(left_win, y, x, data[i]->d_name);
            mvwprintw(left_win, y, (COLS / 2) - 24, "%d", st.st_size);
            mvwprintw(left_win, y, (COLS / 2) - 14, "%s", time);
        }

        free(time);
        ++y;
    }
}

void printRightWindow(WINDOW *right_win, struct dirent **data, int highlight, int n) {
    int x = 1, y = 1;

    box(right_win, 0, 0);
    struct stat st;

    wbkgd(right_win, COLOR_PAIR(1));

    for (int i = n - 1; i >= 0; --i) {
        stat(data[i]->d_name, &st);
        char *time = printTime(&st);
        if (highlight == i + 1) {
            wattron(right_win, A_REVERSE);
            mvwprintw(right_win, y, x, data[i]->d_name);
            mvwprintw(right_win, y, (COLS / 2) - 24, "%d", st.st_size);
            mvwprintw(right_win, y, (COLS / 2) - 14, "%s", time);
            wattroff(right_win, A_REVERSE);
        } else {
            wrefresh(right_win);
            mvwprintw(right_win, y, x, data[i]->d_name);
            mvwprintw(right_win, y, (COLS / 2) - 24, "%d", st.st_size);
            mvwprintw(right_win, y, (COLS / 2) - 14, "%s", time);
        }
        free(time);
        ++y;
    }
}

char *printTime(struct stat *st) {
    struct tm *u;
    u = localtime(&st->st_ctime);
    char f[40];
    strftime(f, 40, "%b %d %H:%M", u);
    char *tmp = (char *)malloc(sizeof(f));
    strcpy(tmp, f);
    return tmp;
}