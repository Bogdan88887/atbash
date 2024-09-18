#include <iostream>
#include <string>

std::string atbashEncrypt(const std::string& plaintext) {
    std::string ciphertext;
    for (char charac : plaintext) {
        if (isalpha(charac)) {
            if ('а' <= charac && charac <= 'я') { // Проверка на кириллицу (строчные)
                ciphertext += 'я' - (charac - 'а');
            } else if ('А' <= charac && charac <= 'Я') { // Проверка на кириллицу (заглавные)
                ciphertext += 'Я' - (charac - 'А');
            } else if ('a' <= charac && charac <= 'z') { // Проверка на латиницу (строчные)
                ciphertext += 'z' - (charac - 'a');
            } else if ('A' <= charac && charac <= 'Z') { // Проверка на латиницу (заглавные)
                ciphertext += 'Z' - (charac - 'A');
            }
        } else {
            ciphertext += charac;
        }
    }
    return ciphertext;
}

std::string atbashDecrypt(const std::string& ciphertext) {
    std::string plaintext;
    for (char charac : ciphertext) {
        if (isalpha(charac)) {
            if ('а' <= charac && charac <= 'я') { // Проверка на кириллицу (строчные)
                plaintext += 'я' - (charac - 'а');
            } else if ('А' <= charac && charac <= 'Я') { // Проверка на кириллицу (заглавные)
                plaintext += 'Я' - (charac - 'А');
            } else if ('a' <= charac && charac <= 'z') { // Проверка на латиницу (строчные)
                plaintext += 'z' - (charac - 'a');
            } else if ('A' <= charac && charac <= 'Z') { // Проверка на латиницу (заглавные)
                plaintext += 'Z' - (charac - 'A');
            }
        } else {
            plaintext += charac;
        }
    }
    return plaintext;
}

int main() {
    std::string choose1;
    std::cout << "Выберите операцию (1 - шифрование, 2 - расшифрование): ";
    std::cin >> choose1;

    if (choose1 == "1") {
        std::string plaintext;
        std::cout << "Введите текст для шифрования: ";
        std::cin.ignore(); // Игнорируем символ новой строки после ввода числа
        std::getline(std::cin, plaintext);
        std::string ciphertext = atbashEncrypt(plaintext);
        std::cout << "Зашифрованный текст: " << ciphertext << std::endl;
    } else if (choose1 == "2") {
        std::string ciphertext;
        std::cout << "Введите текст для расшифровки: ";
        std::cin.ignore(); // Игнорируем символ новой строки после ввода числа
        std::getline(std::cin, ciphertext);
        std::string plaintext = atbashDecrypt(ciphertext);
        std::cout << "Расшифрованный текст: " << plaintext << std::endl;
    } else {
        std::cout << "Выбрана неверная операция!" << std::endl;
    }

    return 0;
}
