import string
import random

letters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
password = ''

quantity = int(input("Length: "))

for i in range(quantity):
	password += random.choice(letters)

print("Your new password is: %s" % password)
