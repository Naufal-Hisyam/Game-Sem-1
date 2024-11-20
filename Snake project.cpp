#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {
    int set[] = {7, 7, 7};
    char counter = 1;
    char key;

    while (true) {
        set[0] = 7;
        set[1] = 7;
        set[2] = 7;

        set[counter - 1] = 12;

        gotoxy(55, 23);
        color(set[0]);
        cout << "Play";

        gotoxy(55, 24);
        color(set[1]);
        cout << "Score";

        gotoxy(55, 25);
        color(set[2]);
        cout << "Exit";

        key = _getch();

        if (key == 72 && counter > 1) { 
            counter--;
        }
        if (key == 80 && counter < 3) {
            counter++;
        }

        if (key == '\r') {
            gotoxy(50, 27);
            if (counter == 1) {
                cout << "You selected Play";
            } else if (counter == 2) {
                cout << "You selected Score";
            } else if (counter == 3) {
                cout << "You selected Exit";
                break;
            }
            Sleep(1000);
            gotoxy(10, 9);
            cout << "                  ";
        }
    }

    return 0;
}
