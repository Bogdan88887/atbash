#include <iostream>
#include <string>

using namespace std;

string atbash_encrypt(string plaintext) {
  string ciphertext = "";
  for (char& c : plaintext) {
    if (c >= 'а' && c <= 'я') {
      ciphertext += 'я' - (c - 'а');
    } else if (c >= 'А' && c <= 'Я') {
      ciphertext += 'Я' - (c - 'А');
    } else if (c >= 'a' && c <= 'z') {
      ciphertext += 'z' - (c - 'a');
    } else if (c >= 'A' && c <= 'Z') {
      ciphertext += 'Z' - (c - 'A');
    } else {
      ciphertext += c;
    }
  }
  return ciphertext;
}

string atbash_decrypt(string ciphertext) {
  string plaintext = "";
  for (char& c : ciphertext) {
    if (c >= 'а' && c <= 'я') {
      plaintext += 'я' - (c - 'а');
    } else if (c >= 'А' && c <= 'Я') {
      plaintext += 'Я' - (c - 'А');
    } else if (c >= 'a' && c <= 'z') {
      plaintext += 'z' - (c - 'a');
    } else if (c >= 'A' && c <= 'Z') {
      plaintext += 'Z' - (c - 'A');
    } else {
      plaintext += c;
    }
  }
  return plaintext;
}

int main() {
  int operation;
  string text;

  cout << "Выберите тип операции (1 - шифрование, 2 - расшифрование): ";
  cin >> operation;

  cout << "Введите текст: ";
  cin.ignore();  // Очистить буфер ввода
  getline(cin, text);

  if (operation == 1) {
    string ciphertext = atbash_encrypt(text);
    cout << "Результат: " << ciphertext << endl;
  } else if (operation == 2) {
    string plaintext = atbash_decrypt(text);
    cout << "Результат: " << plaintext << endl;
  } else {
    cout << "Выбрана неверная операция!" << endl;
  }

  return 0;
}
