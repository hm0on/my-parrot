# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(papug)

# Указываем стандарт C++ (например, C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Требуем поддержки указанного стандарта
set(CMAKE_CXX_EXTENSIONS OFF)  # Отключаем расширения компилятора

# Включаем полную статическую линковку для MinGW (чтобы избежать проблем с DLL)
if (MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")
endif()

# Добавляем исполняемый файл
add_executable(papug main.cpp)

# Если у вас несколько исходных файлов, добавьте их здесь
# add_executable(papug main.cpp other_file.cpp)

# Дополнительные настройки (опционально)
# Включить предупреждения компилятора
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(papug PRIVATE -Wall -Wextra -pedantic)
endif()

# Установка выходной директории (опционально)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)