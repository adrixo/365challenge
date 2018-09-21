#!/usr/bin/python

def isLeapYear(year):
	leap = False
	if(year%4 == 0):
		leap = True
		if(year%100 == 0):
			leap = False
			if(year%400 == 0):
				leap = True
	#((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0)
	return leap


MonthDay = { #month/memorableDay
	1 : 3,
	2 : 28,
	3 : 0,
	4 : 4,
	5 : 9,
	6 : 6,
	7 : 11,
	8 : 8,
	9 : 5,
	10: 10,
	11: 7,
	12: 12
}

DictDay = {
	1 : "Monday",
	2 : "Tuesday",
	3 : "Wednesday",
	4 : "Thusday",
	5 : "Friday",
	6 : "Saturday",
	0 : "Sunday"
}

rawInput = input("Enter a day (yyyy:mm:dd): ")

year = int(rawInput.split(":")[0])
month = int(rawInput.split(":")[1])
day = int(rawInput.split(":")[2])
print("year:", year, "month:", month, "day:", day)

#Variables used:
anchorDay = 0
y = year%100 #last two digits of year
if isLeapYear(year):
	MonthDay[1] = 4
	MonthDay[2] = 29

# https://en.wikipedia.org/wiki/Doomsday_rule
# 1. We first take the anchor day for the century (00-99)
# "switch case" to determine it:
if int(year)//100 == 18:
	#Friday
	anchorDay = 5

if int(year)//100 == 19:
	#Wednesday
	anchorDay = 3

if int(year)//100 == 20:
	#Tuesday
	anchorDay = 2

if int(year)//100 == 21:
	#Sunday
	anchorDay = 7

# 2.Fin the years doomsday
# 2.1 Divide the year's last two digits (y) by 12 and let
#		a be the floor of the quotient
y = year%100
A = y//12

# 2.2 let b be the remainder of the same quotient
B = y%12

# 2.3 Divide that remainder by 4 and let c be the floor of the quotient
C = B//4

# 2.4 Let d be the sum of the three numbers
D = (A+B+C)%7

# 2.5 Count forward the specified number of days from the anchor day to get the year's Doomsday
doomsday = (D+anchorDay)%7

print("Doomsday: ", doomsday)

# 3. calc the day counting from a memorable day
finalDay = (day - MonthDay[month] + doomsday)%7

print(year, month, day,":",  DictDay[finalDay])
