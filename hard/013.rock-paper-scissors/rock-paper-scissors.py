import random, os

def playGame(first, second):

	resultsPath = os.getcwd() + "/results.txt";
	resultsFile = open(resultsPath, 'a')

	print(first + " vs " + second)
	resultsFile.write("\n"+first + " vs " + second + "\n\t\t")

	if first == second:
		print("Draw")
		resultsFile.write("Draw")
		return
	elif (first == "rock" and second == "scissors"
		or first == "paper" and second == "rock" 
		or first == "scissors" and second == "paper"):
		print("CPU1 win")
		resultsFile.write("CPU1 win")
	else:
		print("CPU2 win")
		resultsFile.write("CPU2 win")

	resultsFile.write("\n")
	resultsFile.close()

print("Rock-paper-scissors CPU vs CPU. ")

choices = ( "rock", "paper", "scissors")

playGame(random.choice(choices),random.choice(choices))
