#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <ctime>

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

void drawMenuFrame() {
    color(14); 
    gotoxy(95, 48); cout << " __| |____________________________________________| |__";
    gotoxy(95, 49); cout << "(__   ____________________________________________   __)";
    gotoxy(95, 50); cout << "   | |                                            | |";
    gotoxy(95, 51); cout << "   | |                                            | |";
    gotoxy(95, 52); cout << "   | |                                            | |";
    gotoxy(95, 53); cout << " __| |____________________________________________| |__";
    gotoxy(95, 54); cout << "(__   ____________________________________________   __)";
    gotoxy(95, 55); cout << "   | |                                            | |";
}

int main() {
    system("mode con cols=1750 lines=60");
    int set[] = {7, 7, 7};
    char counter = 1, key;
    time_t lastTime = time(0);

    while (true) {
        time_t currentTime = time(0);
        if (difftime(currentTime, lastTime) >= 1) {
            lastTime = currentTime;
            color(10);
            gotoxy(55, 5); cout << "          _____                    _____                    _____                    _____                    _____          ";
            gotoxy(55, 6); cout << "         /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\         ";
            gotoxy(55, 7); cout << "        /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\         ";
            gotoxy(55, 8); cout << "       /::::\\    \\              /::::|   |               /::::\\    \\              /:::/    /               /::::\\    \\      ";
            gotoxy(55, 9); cout << "      /::::::\\    \\            /:::::|   |              /::::::\\    \\            /:::/    /               /::::::\\    \\    ";
            gotoxy(55, 10); cout << "     /:::/\\:::\\    \\          /::::::|   |             /:::/\\:::\\    \\          /:::/    /               /:::/\\:::\\    \\   ";
            gotoxy(55, 11); cout << "    /:::/__\\:::\\    \\        /:::/|::|   |            /:::/__\\:::\\    \\        /:::/____/               /:::/__\\:::\\    \\ ";
            gotoxy(55, 12); cout << "    \\\:::\\   \\\:::\\    \\      /:::/ |::|   |           /::::\\   \\\:::\\    \\      /::::\\    \\              /::::\\   \\\:::\\    \\ ";
            gotoxy(55, 13); cout << "  ___\\:::\\   \\\:::\\    \\    /:::/  |::|   | _____    /::::::\\   \\\:::\\    \\    /::::::\\____\\________    /::::::\\   \\\:::\\    \\ ";
            gotoxy(55, 14); cout << " /\\   \\\:::\\   \\\:::\\    \\  /:::/   |::|   |/\\    \\  /:::/\\:::\\   \\\:::\\    \\  /:::/\\:::::::::::\\\\\    \\  /:::/\\:::\\   \\\:::\\    \\ ";
            gotoxy(55, 15); cout << "/::\\   \\\:::\\   \\\:::\\____\\/:: /    |::|   /::\\____\\/:::/  \\\:::\\   \\\:::\\____\\/:::/  |:::::::::::\\\____\\/:::/__\\:::\\   \\\:::\\____\\";
            gotoxy(55, 16); cout << "\\:::\\   \\\:::\\   \\\::/    /\\::/    /|::|  /:::/    /\\::/    \\\:::\\  /:::/    /\\::/   |::|   |          \\\:::\\   \\\:::\\   \\\::/    /";
            gotoxy(55, 17); cout << " \\\:::\\   \\\:::\\   \\\/____/  \\\/____/ |::| /:::/    /  \\\/____/ \\\:::\\/:::/    /  \\\/____|::|   |           \\\:::\\   \\\:::\\   \\\/____/ ";
            gotoxy(55, 18); cout << "  \\\:::\\   \\\:::\\    \\              |::|/:::/    /            \\\::::::/    /         |::|   |            \\\:::\\   \\\:::\\    \\ ";
            gotoxy(55, 19); cout << "   \\\:::\\   \\\:::\\____\\             |::::::/    /              \\\::::/    /          |::|   |             \\\:::\\   \\\:::\\____\\ ";
            gotoxy(55, 20); cout << "    \\\:::\\  /:::/    /             |:::::/    /               /:::/    /           |::|   |              \\\:::\\   \\\::/    / ";
            gotoxy(55, 21); cout << "     \\\:::\\/:::/    /              |::::/    /               /:::/    /            |::|   |               \\\:::\\   \\\/____/  ";
            gotoxy(55, 22); cout << "      \\\::::::/    /               /:::/    /               /:::/    /             |::|   |                \\\:::\\    \\       ";
            gotoxy(55, 23); cout << "       \\\::::/    /               /:::/    /               /:::/    /              \\\|   |                 \\\:::\\____\\      ";
            gotoxy(55, 24); cout << "        \\\::/    /                \\\::/    /                \\\::/    /                \\\|   |                  \\\::/    /      ";
            gotoxy(55, 25); cout << "         \\\/____/                  \\\/____/                  \\\/____/                  \\\|___|                   \\\/____/       ";
        }

        drawMenuFrame();
        set[0] = set[1] = set[2] = 7;
        set[counter - 1] = 12;
        gotoxy(120, 50); color(set[0]); cout << "Play";
        gotoxy(120, 51); color(set[1]); cout << "Score";
        gotoxy(120, 52); color(set[2]); cout << "Exit";

        key = _getch();
        if (key == 72 && counter > 1) counter--;
        if (key == 80 && counter < 3) counter++;
        if (key == '\r') {
            gotoxy(115, 55); color(10);
            if (counter == 1) cout << "Entering Game...";
            else if (counter == 2) cout << "Checking Score...";
            else if (counter == 3) cout << "     Exit";
            Sleep(1000);
            gotoxy(118, 55); cout << "                    ";
            if (counter == 3) break;
        }
        Sleep(100);
    }

    return 0;
}
