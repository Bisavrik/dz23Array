#ifndef ARRAYVALUECALCULATOR_H
#define ARRAYVALUECALCULATOR_H

#include <cstring>

using namespace std;

class ArraySizeException {
public:
    const char* what() const {
        return "Invalid array size. Expected 4x4 array.";
    }
};

class ArrayDataException {
private:
    char message[100];
public:
    explicit ArrayDataException(const char* cellInfo) {
        strcpy(message, "Invalid data at ");
        strcat(message, cellInfo);
        strcat(message, ".");
    }

    const char* what() const {
        return message;
    }
};

class ArrayValueCalculator {
public:
    static int doCalc(const char array[4][4]); // Метод для підрахунку
};

#endif // ARRAYVALUECALCULATOR_H