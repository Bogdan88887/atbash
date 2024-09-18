package main

import (
 "fmt"
 "unicode"
)

func atbashEncrypt(plaintext string) string {
 ciphertext := ""
 for _, char := range plaintext {
  if unicode.IsLetter(char) {
   if 'а' <= char && char <= 'я' { // Проверка на кириллицу (строчные)
    ciphertext += string('я' - (char - 'а'))
   } else if 'А' <= char && char <= 'Я' { // Проверка на кириллицу (заглавные)
    ciphertext += string('Я' - (char - 'А'))
   } else if 'a' <= char && char <= 'z' { // Проверка на латиницу (строчные)
    ciphertext += string('z' - (char - 'a'))
   } else if 'A' <= char && char <= 'Z' { // Проверка на латиницу (заглавные)
    ciphertext += string('Z' - (char - 'A'))
   }
  } else {
   ciphertext += string(char)
  }
 }
 return ciphertext
}

func atbashDecrypt(ciphertext string) string {
 plaintext := ""
 for _, char := range ciphertext {
  if unicode.IsLetter(char) {
   if 'а' <= char && char <= 'я' { // Проверка на кириллицу (строчные)
    plaintext += string('я' - (char - 'а'))
   } else if 'А' <= char && char <= 'Я' { // Проверка на кириллицу (заглавные)
    plaintext += string('Я' - (char - 'А'))
   } else if 'a' <= char && char <= 'z' { // Проверка на латиницу (строчные)
    plaintext += string('z' - (char - 'a'))
   } else if 'A' <= char && char <= 'Z' { // Проверка на латиницу (заглавные)
    plaintext += string('Z' - (char - 'A'))
   }
  } else {
   plaintext += string(char)
  }
 }
 return plaintext
}

func main() {
 var choose1 string
 fmt.Println("Выберите операцию (1 - шифрование, 2 - расшифрование): ")
 fmt.Scanln(&choose1)

 if choose1 == "1" {
  var plaintext string
  fmt.Println("Введите текст для шифрования: ")
  fmt.Scanln(&plaintext)
  ciphertext := atbashEncrypt(plaintext)
  fmt.Println("Зашифрованный текст:", ciphertext)
 } else if choose1 == "2" {
  var ciphertext string
  fmt.Println("Введите текст для расшифровки: ")
  fmt.Scanln(&ciphertext)
  plaintext := atbashDecrypt(ciphertext)
  fmt.Println("Расшифрованный текст:", plaintext)
 } else {
  fmt.Println("Выбрана неверная операция!")
 }
}
