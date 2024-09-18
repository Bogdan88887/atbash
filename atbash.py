def atbash_encrypt(plaintext):
    ciphertext = ""
    for char in plaintext:
        if char.isalpha():
            if 'а' <= char <= 'я':  # Проверка на кириллицу (строчные)
                ciphertext += chr((ord('я') - (ord(char) - ord('а'))))
            elif 'А' <= char <= 'Я':  # Проверка на кириллицу (заглавные)
                ciphertext += chr((ord('Я') - (ord(char) - ord('А'))))
            elif 'a' <= char <= 'z':  # Проверка на латиницу (строчные)
                ciphertext += chr((ord('z') - (ord(char) - ord('a'))))
            elif 'A' <= char <= 'Z':  # Проверка на латиницу (заглавные)
                ciphertext += chr((ord('Z') - (ord(char) - ord('A'))))
        else:
            ciphertext += char

    return ciphertext

def atbash_decrypt(ciphertext):
    plaintext = ""
    for char in ciphertext:
        if char.isalpha():
            if 'а' <= char <= 'я':  # Проверка на кириллицу (строчные)
                plaintext += chr((ord('я') - (ord(char) - ord('а'))))
            elif 'А' <= char <= 'Я':  # Проверка на кириллицу (заглавные)
                plaintext += chr((ord('Я') - (ord(char) - ord('А'))))
            elif 'a' <= char <= 'z':  # Проверка на латиницу (строчные)
                plaintext += chr((ord('z') - (ord(char) - ord('a'))))
            elif 'A' <= char <= 'Z':  # Проверка на латиницу (заглавные)
                plaintext += chr((ord('Z') - (ord(char) - ord('A'))))
        else:
            plaintext += char

    return plaintext

choose1 = input("Выберите операцию (1 - шифрование, 2 - расшифрование): ")

if choose1 == "1":
    plaintext = input("Введите текст для шифрования: ")
    ciphertext = atbash_encrypt(plaintext)
    print("Зашифрованный текст:", ciphertext)
elif choose1 == "2":
    ciphertext = input("Введите текст для расшифровки: ")
    print("Расшифрованный текст:", atbash_decrypt(ciphertext))
else:
    print("Выбрана неверная операция!")
