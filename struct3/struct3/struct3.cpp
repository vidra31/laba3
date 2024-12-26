#include <iostream>
#include "Header.h";
#include <locale.h>
#include <string>

int main()
{
    setlocale(LC_ALL, "Rus");
    DoubleList<char> doubleListLine;
    OneList<char> oneListLine;
    int max = 0;
    std::cout << "Введите строку:\n";
    std::string letter;
    getline(std::cin, letter);
    for (int i = 0; i < letter.length(); i++)
    {
        oneListLine.push_back(letter[i]);
        doubleListLine.push_back(letter[i]);
    }

    doubleListLine = line_transform(doubleListLine, max);
    oneListLine = line_transform(oneListLine, max);
    std::cout << "Максимальное кол-во пробелов: " << max << "\n";
    std::cout << "Результат двумерного списка: ";

    for (int i = 0; i < doubleListLine.size(); i++) {
        std::cout << doubleListLine[i] << "";
    }
    std::cout << std::endl;

    std::cout << "Результат одномерного списка: ";
    for (int i = 0; i < oneListLine.size(); i++) {
        std::cout << oneListLine[i] << "";
    }
    std::cout << std::endl;
}