#include <iostream>
#include <fstream>
#include <chrono>  // для std::chrono
#include <thread>  // для std::this_thread::sleep_for
#include <sstream> // для std::stringstream

// ANSI-коды для цветов
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void framePrinter(const std::string& filePath, const std::string& color) {
    // Открываем файл для чтения
    std::ifstream file(filePath);

    // Проверяем, удалось ли открыть файл
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filePath << std::endl;
        return;
    }

    // Читаем весь файл в строку
    std::stringstream buffer;
    buffer << file.rdbuf() << std::endl;  // Читаем всё содержимое файла
    std::string frame = buffer.str();  // Сохраняем содержимое в строку

    // Закрываем файл
    file.close();

    // Очищаем консоль и выводим кадр с цветом
    clearConsole();
    std::cout << color << frame << COLOR_RESET;  // Применяем цвет и сбрасываем его после вывода
}

int main() {
    // Задержка между фреймами (в миллисекундах)
    const int frameDelay = 40;  // 100 мс = 0.1 секунды

    // Список цветов для каждого кадра
    const std::string colors[] = {
        COLOR_RED,
        COLOR_GREEN,
        COLOR_YELLOW,
        COLOR_BLUE,
        COLOR_MAGENTA,
        COLOR_CYAN,
        COLOR_WHITE,
        COLOR_RED,
        COLOR_GREEN,
        COLOR_YELLOW
    };

    while (true) {
        for (int i = 0; i < 10; ++i) {
            framePrinter("../frames/" + std::to_string(i) + ".txt", colors[i]);
            std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay));  // Задержка
        }
    }

    return 0;
}