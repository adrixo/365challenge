#!/usr/bin/python

key = "GLADOSGLADOSG"
#	   1234567890123
message = input("Enter the message to encrypt: ")

message = message.upper()

def encrypt(message, key):
	first = ord('A')
	last = ord('Z')

	encryptedMsg = ''

	i = 0;
	for c in message:
		encryptedInt = ((ord(c) - first) + (ord(key[i]) - first)) % (last-first+1)
		encryptedChar = chr(encryptedInt + first)
		encryptedMsg = encryptedMsg + encryptedChar
		i+=1

	return encryptedMsg

def decrypt(message, key):
	first = ord('A')
	last = ord('Z')

	decryptedMsg = ''

	i = 0;
	for c in message:
		decryptedInt = ((ord(c) - first) - (ord(key[i]) - first)) % (last-first+1)
		decryptedChar = chr(decryptedInt + first)
		decryptedMsg = decryptedMsg + decryptedChar
		i+=1

	return decryptedMsg


encrypted = encrypt(message, key)
print("Encrypted: " + encrypted)
decrypted = decrypt(encrypted, key)
print("Decrypted: " + decrypted)
