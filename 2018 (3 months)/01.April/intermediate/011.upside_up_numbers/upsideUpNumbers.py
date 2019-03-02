#!/usr/bin/python
#An “upside up” number is a number that reads the same 
#when it is rotated 180°. 
#For instance, 689 and 1961 are upside up numbers.

# My program only check if an entered number is "upside up"
# we can follow the statement:
####Your task is to find the next upside up number greater than 1961
# implementing trial and error method

code = { "1" : "1" , "2" : "5" , "5" : "2" , "6" : "9" , "8" : "8" , "9" : "6"}

number = raw_input("Enter one number: ")

flag = True

for i in range(len(number)//2): #we just need to check half string; and in case of being odd, we omit the central number 

	#reverse use of the dictionary
	for num, upsideUp in code.iteritems():

		if upsideUp == number[i]:
			try:
				if number[i] != code[number[len(number)-i-1]]:
					flag = False
					break
			except KeyError:
				flag = False

	else:
		continue

	break


if not flag:
	print("The number does not follow the rules. ")
else:
	print("Great upside up number. ")
