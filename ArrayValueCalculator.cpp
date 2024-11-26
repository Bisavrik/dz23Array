#include "ArrayValueCalculator.h"

// Перевіряємо, чи рядок є числом (може включати від'ємні числа)
bool isValidInteger(const char* str) {
    if (str == nullptr || *str == '\0') {
        return false; // Порожній рядок
    }

    int i = 0;

    // Перевірка на від'ємне число
    if (str[0] == '-') {
        i = 1;
        if (str[1] == '\0') {
            return false; // "-" не може бути числом
        }
    }

    // Перевіряємо, чи всі символи — цифри
    for (; str[i] != '\0'; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }

    return true;
}

int ArrayValueCalculator::doCalc(const char array[4][4]) {
    int sum = 0;

    // Перебір елементів масиву
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            const char* value = array[i][j];

            // Перевірка, чи рядок є валідним числом
            if (!isValidInteger(value)) {
                char cellInfo[20];
                strcpy(cellInfo, "[");
                char buffer[5];
                sprintf(buffer, "%d", i);
                strcat(cellInfo, buffer);
                strcat(cellInfo, "][");
                sprintf(buffer, "%d", j);
                strcat(cellInfo, buffer);
                strcat(cellInfo, "]");
                throw ArrayDataException(cellInfo);
            }

            // Перетворення рядка на число та додавання до суми
            sum += atoi(value);
        }
    }

    return sum;
}