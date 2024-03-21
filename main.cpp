#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <Windows.h>

#include "functions.h"  // Заголовочный файл с функциями

using namespace std;

int main() 
{
    // Устанавливаем русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inputFilePath = "input.txt";    // Путь к файлу для чтения
    string outputFilePath = "output.txt";  // Путь к файлу для записи результатов

    // Вызываем основную функцию для подсчета частотности слов
    countWordFrequency(inputFilePath, outputFilePath);

    return 0;
}