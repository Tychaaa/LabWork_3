#include "functions.h"

// Функция для вывода результатов на экран
void displayWordFrequency(const map<string, int>& wordFrequency)
{
    // Итерация по всем парам ключ-значение в map
    for (const auto& pair : wordFrequency)
    {
        // Вывод ключа (слова) и значения (частоты), разделенных двоеточием
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Функция для записи результатов в файл
void writeWordFrequencyToFile(const map<string, int>& wordFrequency, const string& outputFilePath)
{
    // Открываем файл для записи
    ofstream outFile(outputFilePath);

    // Проверяем, удалось ли открыть файл
    if (!outFile.is_open())
    {
        // Если не удалось открыть файл, выводим сообщение об ошибке и выходим из функции
        cerr << "Не удалось создать файл " << outputFilePath << endl;
        return;
    }

    // Итерируем по всем парам ключ-значение в map
    for (const auto& pair : wordFrequency)
    {
        // Записываем в файл ключ (слово) и значение (частоту), разделенные двоеточием
        outFile << pair.first << ": " << pair.second << endl;
    }

    // Закрываем файл
    outFile.close();
}

// Функция для удаления пунктуации из слова
string removePunctuation(const string& word)
{
    string result;  // Строка для хранения результата без пунктуации

    // Копирование символов из word в result, если они не являются пунктуацией
    copy_if(word.begin(), word.end(), back_inserter(result),
        [](char c)  // Лямбда-функция как предикат для copy_if
        {
            // Приведение типа char к unsigned char для корректной работы ispunct
            // и возврат true, если символ не является пунктуацией
            return !ispunct(static_cast<unsigned char>(c));
        });

    return result;  // Возврат новой строки без пунктуации
}

// Основная функция для подсчета частотности слов
void countWordFrequency(const string& inFileName, const string& outFileName)
{
    // Открываем файл для чтения
    ifstream file(inFileName);

    map<string, int> wordCount; // Словарь для подсчета слов и их частот

    // Проверяем, удалось ли открыть файл
    if (!file.is_open())
    {
        // Если не удалось открыть файл, выводим сообщение об ошибке и выходим из функции
        cerr << "Не удалось открыть файл!" << endl;
        return;
    }

    string word;    // Строка для хранения каждого слова, считываемого из файла

    // Чтение файла слово за словом
    while (file >> word)
    {
        // Удаление пунктуации из слов
        word = removePunctuation(word);
        // Преобразовать слово к нижнему регистру
        transform(word.begin(), word.end(), word.begin(), tolower);

        // Учет слова в словаре, если оно не пустое
        if (!word.empty())
        {
            wordCount[word]++; // Увеличить счетчик слова
        }
    }

    // Вывод частоты слов на экран
    displayWordFrequency(wordCount);
    // Запись частоты слов в файл
    writeWordFrequencyToFile(wordCount, outFileName);

    // Закрытие файла
    file.close();
}