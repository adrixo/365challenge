import random

def playGame(first, second):
	print(first + " vs " + second)
	if first == second:
		print("Draw")
		return
	elif (first == "rock" and second == "scissors"
		or first == "paper" and second == "rock" 
		or first == "scissors" and second == "paper"):
		print("CPU1 win")
	else:
		print("CPU2 win")

print("Rock-paper-scissors CPU vs CPU. ")

choices = ( "rock", "paper", "scissors")

playGame(random.choice(choices),random.choice(choices))
