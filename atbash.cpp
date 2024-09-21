#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

std::wstring atbashEncryptDecrypt(const std::wstring& input) {
    std::wstring output;
    for (wchar_t ch : input) {
        if (ch >= L'a' && ch <= L'z') {
            output += L'z' - (ch - L'a');
        } else if (ch >= L'A' && ch <= L'Z') {
            output += L'Z' - (ch - L'A');
        } else if (ch >= L'а' && ch <= L'я') {
            output += L'я' - (ch - L'а');
        } else if (ch >= L'А' && ch <= L'Я') {
            output += L'Я' - (ch - L'А');
        } else {
            output += ch; // не изменяем символы, которые не в алфавите
        }
    }
    return output;
}

int main() {
    setlocale(LC_ALL, ""); // Поддержка русского языка в консоли

    int option;
    std::wstring text;

    while (true) {
        std::wcout << L"Выберите опцию: 1 - Шифрование, 2 - Расшифровка, 0 - Выход\n";
        std::wcin >> option;
        std::wcin.ignore(); // Игнорируем символ новой строки после ввода числа

        if (option == 0) {
            break;
        }

        std::wcout << L"Введите текст: ";
        std::getline(std::wcin, text);

        if (option == 1) {
            std::wstring encrypted = atbashEncryptDecrypt(text);
            std::wcout << L"Зашифрованный текст: \"" << encrypted << L"\"\n";
        } else if (option == 2) {
            std::wstring decrypted = atbashEncryptDecrypt(text);
            std::wcout << L"Расшифрованный текст: \"" << decrypted << L"\"\n";
        } else {
            std::wcout << L"Некорректный выбор, попробуйте еще раз.\n";
        }
    }

    return 0;
}
