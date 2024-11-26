#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <fstream>

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

bool isAccountExist(const string& username, const string& password) {
    ifstream file("accounts.txt");
    string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }
    return false;
}

void registerAccount() {
    string username, password;
    gotoxy(55, 20); cout << "=== Register ===" << endl;
    gotoxy(50, 22); cout << "Username: ";
    cin >> username;
    gotoxy(50, 23); cout << "Password: ";
    cin >> password;

ofstream file("accounts.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    gotoxy(50, 25); color (9); cout << "Akun berhasil dibuat!" << endl;
    Sleep(1000);
}

bool login() {
    string username, password;
    gotoxy(57, 20); cout << "=== Login ===" << endl;
    gotoxy(50, 22); cout << "Username: ";
    cin >> username;
    gotoxy(50, 23); cout << "Password: ";
    cin >> password;

    if (isAccountExist(username, password)) {
        gotoxy(55, 25); color (9); cout << "Login berhasil!" << endl;
        Sleep(1000);
        return true;
    } else {
        gotoxy(40, 25); color (12); cout << "Username atau password salah, silakan coba lagi!" << endl;
        Sleep(1000);
        return false;
    }
}

void drawLoginFrame() {
    color(14); 
    gotoxy(35, 9); cout <<  " __| |____________________________________________| |__";
    gotoxy(35, 10); cout << "(__   ____________________________________________   __)";
    gotoxy(35, 11); cout << "   | |                                            | |";
    gotoxy(35, 11); cout << "   | |                                            | |";
    gotoxy(35, 12); cout << "   | |                                            | |";
    gotoxy(35, 13); cout << "   | |                                            | |";
    gotoxy(35, 14); cout << "   | |                                            | |";
    gotoxy(35, 15); cout << " __| |____________________________________________| |__";
    gotoxy(35, 16); cout << "(__   ____________________________________________   __)";
    gotoxy(35, 17); cout << "   | |                                            | |";
}

bool loginMenu() {
    int choice = 1;  
    char key;
    while (true) {
        system("cls");
        
        drawLoginFrame(); 
        gotoxy(56, 6); cout << "=== Main Menu ===" << endl;
        if (choice == 1) {
            gotoxy(55, 12); color(11); cout << "> Login" << endl;
            gotoxy(55, 13); color(7); cout << "  Register" << endl;
            gotoxy(55, 14); color(7); cout << "  Exit" << endl;
        } else if (choice == 2) {
            gotoxy(55, 12); color(7); cout << "  Login" << endl;
            gotoxy(55, 13); color(11); cout << "> Register" << endl;
            gotoxy(55, 14); color(7); cout << "  Exit" << endl;
        } else {
            gotoxy(55, 12); color(7); cout << "  Login" << endl;
            gotoxy(55, 13); color(7); cout << "  Register" << endl;   
            gotoxy(55, 14); color(11); cout << "> Exit" << endl;
        }
key = _getch();  
        if (key == 72 && choice > 1) choice--;  
        if (key == 80 && choice < 3) choice++;  
        if (key == '\r') {  
            if (choice == 1) {
                if (login()) return true;
            } else if (choice == 2) {
                registerAccount();
            } else if (choice == 3) {
                exit(0);  
            }
        }
    }
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

void drawSnakeASCII() {
    color(10);
    gotoxy(55, 5); cout << "          _____                    _____                    _____                    _____                    _____          ";
    gotoxy(55, 6); cout << "         /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\         ";
    gotoxy(55, 7); cout << "        /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\         ";
    gotoxy(55, 8); cout << "       /::::\\    \\              /::::|   |               /::::\\    \\              /:::/    /               /::::\\    \\      ";
    gotoxy(55, 9); cout << "      /::::::\\    \\            /:::::|   |              /::::::\\    \\            /:::/    /               /::::::\\    \\    ";
    gotoxy(55, 10); cout << "     /:::/\\:::\\    \\          /::::::|   |             /:::/\\:::\\    \\          /:::/    /               /:::/\\:::\\    \\   ";
    gotoxy(55, 11); cout << "    /:::/__\\:::\\    \\        /:::/|::|   |            /:::/__\\:::\\    \\        /:::/____/               /:::/__\\:::\\    \\ ";
    gotoxy(55, 12); cout << "    \\:::\\   \\:::\\    \\      /:::/ |::|   |           /::::\\   \\:::\\    \\      /::::\\    \\              /::::\\   \\:::\\    \\ ";
    gotoxy(55, 13); cout << "  ___\\:::\\   \\:::\\    \\    /:::/  |::|   | _____    /::::::\\   \\:::\\    \\    /::::::\\____\\________    /::::::\\   \\:::\\    \\ ";
    gotoxy(55, 14); cout << " /\\   \\:::\\   \\:::\\    \\  /:::/   |::|   |/\\    \\  /:::/\\:::\\   \\:::\\    \\  /:::/\\:::::::::::\\    \\  /:::/\\:::\\   \\:::\\    \\ ";
    gotoxy(55, 15); cout << "/::\\   \\:::\\   \\:::\\____\\/:: /    |::|   /::\\____\\/:::/  \\:::\\   \\:::\\____\\/:::/  |:::::::::::\\____\\/:::/__\\:::\\   \\:::\\____\\";
    gotoxy(55, 16); cout << "\\:::\\   \\:::\\   \\::/    /\\::/    /|::|  /:::/    /\\::/    \\:::\\  /:::/    /\\::/   |::|   |          \\:::\\   \\:::\\   \\::/    /";
    gotoxy(55, 17); cout << " \\:::\\   \\:::\\   \\/____/  \\/____/ |::| /:::/    /  \\/____/ \\:::\\/:::/    /  \\/____|::|   |           \\:::\\   \\:::\\   \\/____/ ";
    gotoxy(55, 18); cout << "  \\:::\\   \\:::\\    \\              |::|/:::/    /            \\::::::/    /         |::|   |            \\:::\\   \\:::\\    \\ ";
    gotoxy(55, 19); cout << "   \\:::\\   \\:::\\____\\             |::::::/    /              \\::::/    /          |::|   |             \\:::\\   \\:::\\____\\ ";
    gotoxy(55, 20); cout << "    \\:::\\  /:::/    /             |:::::/    /               /:::/    /           |::|   |              \\:::\\   \\::/    / ";
    gotoxy(55, 21); cout << "     \\:::\\/:::/    /              |::::/    /               /:::/    /            |::|   |               \\:::\\   \\/____/  ";
    gotoxy(55, 22); cout << "      \\::::::/    /               /:::/    /               /:::/    /             |::|   |                \\:::\\    \\       ";
    gotoxy(55, 23); cout << "       \\::::/    /               /:::/    /               /:::/    /              \\::|   |                 \\:::\\____\\      ";
    gotoxy(55, 24); cout << "        \\::/    /                \\::/    /                \\::/    /                \\:|   |                  \\::/    /      ";
    gotoxy(55, 25); cout << "         \\/____/                  \\/____/                  \\/____/                  \\|___|                   \\/____/       ";
}

int main() {
    system("mode con cols=1750 lines=60");

    if (loginMenu()) {  
    }
    system("cls");
    
    drawSnakeASCII();
    
    int set[] = {7, 7, 7};
    char counter = 1, key;
    time_t lastTime = time(0);

    while (true) {
        time_t currentTime = time(0);
        if (difftime(currentTime, lastTime) >= 1) {
            lastTime = currentTime;
            drawSnakeASCII();
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
