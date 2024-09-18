def atbash_encrypt(plaintext):
	
  ciphertext = ""
  for char in plaintext:
    if char.isalpha():
      if char.islower():
        ciphertext += chr((ord('z') - (ord(char) - ord('a'))) % 0x10FFFF)
      else:
        ciphertext += chr((ord('Z') - (ord(char) - ord('A'))) % 0x10FFFF)
    else:
      ciphertext += char

  return ciphertext
  
def atbash_decrypt(ciphertext):
  
  plaintext = ""
  for char in ciphertext:
    if char.isalpha():
      if char.islower():
        plaintext += chr((ord('z') - (ord(char) - ord('a'))) % 0x10FFFF)
      else:
        plaintext += chr((ord('Z') - (ord(char) - ord('A'))) % 0x10FFFF)
    else:
      plaintext += char

  return plaintext

choose1 = input("Выберите операцию: ")

if choose1 == "1":
	plaintext = input("Введите текст для шифрования: ")
	ciphertext = atbash_encrypt(plaintext)
	print("Зашифрованный текст:",ciphertext)
elif choose1 == "2":
	ciphertext = input("Введите текст для расшифровки: ")
	print("Расшифрованный текст:",atbash_decrypt(ciphertext))
else:
	print("Выбранна неверная операция!")
