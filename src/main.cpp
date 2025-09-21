#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

void fast_write(const char* data, size_t length) {
    write(STDOUT_FILENO, data, length);
}

int main() {
    // Отключаем буферизацию stdout для мгновенного вывода
    setvbuf(stdout, NULL, _IONBF, 0);
    
    char screen[HEIGHT * (WIDTH + 1) + 1];
    int offset = 0;
    
    size_t counter = 0;

    while(counter++ < 200) {
        offset = 0;

        memcpy(screen, "\033[2J\033[H", 7);
        offset += 7;
        
        // Формируем кадр
        for(int y = 0; y < HEIGHT; y++) {
            for(int x = 0; x < WIDTH; x++) {
                screen[offset++] = (x * y + y + counter) % 26 + 'A';
            }
            screen[offset++] = '\n';
        }
        screen[offset] = '\0';
        
        fast_write(screen, offset);
        
        
        // Микро-задержка
        usleep(50000); // 50ms
    }
    
    return 0;
}