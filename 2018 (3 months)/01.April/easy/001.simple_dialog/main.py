

#Questions
name = raw_input('\nEnter your name: ')
while True:
	try:
		age = int(input('Enter your age: '))
	except:
		print("Not a number. ")
		continue
	else:
		break

username = raw_input('Enter your username: ')

#output
print('You are ' + name + ' and you are ' + str(age) + ' years old and your username is @' + username)

#to file
file = open('info.log', 'a')
file.write('\nYou are ' + name + ' and you are ' + str(age) + ' years old and your username is @' + username + '\n')
file.close()

