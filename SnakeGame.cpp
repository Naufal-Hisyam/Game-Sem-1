#include <ncurses\ncurses.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Point {
    int x, y;
};

int readHighScore() {
    ifstream file("highscore.txt");
    int highScore = 0;
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}

void writeHighScore(int score) {
    ofstream file("highscore.txt");
    if (file.is_open()) {
        file << score;
        file.close();
    }
}

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    int termWidth, termHeight;
    getmaxyx(stdscr, termHeight, termWidth);
    if (termWidth < 100 || termHeight < 30) {
        endwin();
        printf("Terminal terlalu kecil! Harap gunakan terminal dengan ukuran minimal 100x30.\n");
        return 1;
    }

    const int WIDTH = termWidth - 30;
    const int HEIGHT = termHeight;

    WINDOW* gameWin = newwin(HEIGHT, WIDTH, 0, 0);
    WINDOW* scoreWin = newwin(HEIGHT, 30, 0, WIDTH);
    keypad(gameWin, true);
    nodelay(gameWin, true);

    vector<Point> snake = {{WIDTH / 2, HEIGHT / 2}};
    Point food = {rand() % (WIDTH - 2) + 1, rand() % (HEIGHT - 2) + 1};
    int direction = KEY_RIGHT;
    int score = 0;
    int highScore = readHighScore();
    bool gameOver = false;

    while (!gameOver) {
        box(gameWin, 0, 0);
        box(scoreWin, 0, 0);

        mvwprintw(scoreWin, 1, 1, "Score: %d", score);
        mvwprintw(scoreWin, 2, 1, "High Score: %d", highScore);
        wrefresh(scoreWin);

        mvwaddch(gameWin, food.y, food.x, '*');

        for (size_t i = 0; i < snake.size(); i++) {
            mvwaddch(gameWin, snake[i].y, snake[i].x, i == 0 ? 'O' : 'o');
        }

        wrefresh(gameWin);

        int newDirection = wgetch(gameWin);
        if (newDirection == KEY_UP || newDirection == KEY_DOWN || 
            newDirection == KEY_LEFT || newDirection == KEY_RIGHT) {
            if ((direction == KEY_UP && newDirection != KEY_DOWN) ||
                (direction == KEY_DOWN && newDirection != KEY_UP) ||
                (direction == KEY_LEFT && newDirection != KEY_RIGHT) ||
                (direction == KEY_RIGHT && newDirection != KEY_LEFT)) {
                direction = newDirection;
            }
        }

        Point newHead = snake[0];
        switch (direction) {
            case KEY_UP:    newHead.y--; break;
            case KEY_DOWN:  newHead.y++; break;
            case KEY_LEFT:  newHead.x--; break;
            case KEY_RIGHT: newHead.x++; break;
        }
        snake.insert(snake.begin(), newHead);

        if (newHead.x == food.x && newHead.y == food.y) {
            score++;
            if (score > highScore) highScore = score;
            food = {rand() % (WIDTH - 2) + 1, rand() % (HEIGHT - 2) + 1};
        } else {
            snake.pop_back();
        }

        if (newHead.x <= 0 || newHead.x >= WIDTH - 1 ||
            newHead.y <= 0 || newHead.y >= HEIGHT - 1) {
            gameOver = true;
        }
        for (size_t i = 1; i < snake.size(); i++) {
            if (newHead.x == snake[i].x && newHead.y == snake[i].y) {
                gameOver = true;
            }
        }

        napms(100);
        werase(gameWin);
    }

    mvwprintw(gameWin, HEIGHT / 2, WIDTH / 2 - 5, "GAME OVER!");
    wrefresh(gameWin);
    napms(2000);

    writeHighScore(highScore);

    delwin(gameWin);
    delwin(scoreWin);
    endwin();

    return 0;
}

