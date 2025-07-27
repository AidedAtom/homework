#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class SnakeGame {
private:
    std::vector<Point> snake;
    Point food;
    int direction;
    int score;
    int max_x, max_y;
    bool game_over;
    
    // Direction constants
    static const int UP = 1;
    static const int DOWN = 2;
    static const int LEFT = 3;
    static const int RIGHT = 4;

public:
    SnakeGame() {
        // Initialize ncurses
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        curs_set(0);
        
        // Get screen dimensions
        getmaxyx(stdscr, max_y, max_x);
        
        // Initialize game state
        initGame();
    }
    
    ~SnakeGame() {
        endwin();
    }
    
    void initGame() {
        snake.clear();
        // Start snake in the middle of screen
        Point start(max_x / 2, max_y / 2);
        snake.push_back(start);
        snake.push_back(Point(start.x - 1, start.y));
        snake.push_back(Point(start.x - 2, start.y));
        
        direction = RIGHT;
        score = 0;
        game_over = false;
        
        generateFood();
    }
    
    void generateFood() {
        do {
            food.x = rand() % (max_x - 2) + 1;
            food.y = rand() % (max_y - 2) + 1;
        } while (isSnakePosition(food));
    }
    
    bool isSnakePosition(const Point& pos) {
        for (const auto& segment : snake) {
            if (segment == pos) {
                return true;
            }
        }
        return false;
    }
    
    void handleInput() {
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                if (direction != DOWN) direction = UP;
                break;
            case KEY_DOWN:
                if (direction != UP) direction = DOWN;
                break;
            case KEY_LEFT:
                if (direction != RIGHT) direction = LEFT;
                break;
            case KEY_RIGHT:
                if (direction != LEFT) direction = RIGHT;
                break;
            case 'q':
            case 'Q':
                game_over = true;
                break;
        }
    }
    
    void moveSnake() {
        Point head = snake[0];
        
        // Calculate new head position
        switch (direction) {
            case UP:
                head.y--;
                break;
            case DOWN:
                head.y++;
                break;
            case LEFT:
                head.x--;
                break;
            case RIGHT:
                head.x++;
                break;
        }
        
        // Check wall collision
        if (head.x <= 0 || head.x >= max_x - 1 || head.y <= 0 || head.y >= max_y - 1) {
            game_over = true;
            return;
        }
        
        // Check self collision
        if (isSnakePosition(head)) {
            game_over = true;
            return;
        }
        
        // Add new head
        snake.insert(snake.begin(), head);
        
        // Check if food was eaten
        if (head == food) {
            score += 10;
            generateFood();
        } else {
            // Remove tail if no food eaten
            snake.pop_back();
        }
    }
    
    void draw() {
        clear();
        
        // Draw border
        for (int i = 0; i < max_x; i++) {
            mvprintw(0, i, "#");
            mvprintw(max_y - 1, i, "#");
        }
        for (int i = 0; i < max_y; i++) {
            mvprintw(i, 0, "#");
            mvprintw(i, max_x - 1, "#");
        }
        
        // Draw snake
        for (size_t i = 0; i < snake.size(); i++) {
            if (i == 0) {
                mvprintw(snake[i].y, snake[i].x, "O"); // Head
            } else {
                mvprintw(snake[i].y, snake[i].x, "o"); // Body
            }
        }
        
        // Draw food
        mvprintw(food.y, food.x, "*");
        
        // Draw score
        mvprintw(0, 2, " Score: %d ", score);
        
        // Draw instructions
        mvprintw(max_y - 1, 2, " Use arrow keys to move, 'q' to quit ");
        
        refresh();
    }
    
    void run() {
        srand(time(nullptr));
        
        while (!game_over) {
            handleInput();
            moveSnake();
            draw();
            usleep(150000); // Game speed (150ms delay)
        }
        
        // Game over screen
        clear();
        mvprintw(max_y / 2, max_x / 2 - 10, "GAME OVER!");
        mvprintw(max_y / 2 + 1, max_x / 2 - 10, "Final Score: %d", score);
        mvprintw(max_y / 2 + 2, max_x / 2 - 10, "Press any key to exit");
        refresh();
        
        nodelay(stdscr, FALSE);
        getch();
    }
};

int main() {
    SnakeGame game;
    game.run();
    return 0;
}