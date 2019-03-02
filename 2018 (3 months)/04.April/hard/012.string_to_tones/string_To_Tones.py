#!/usr/bin/python
					#only works on linux using
					#apt-get install beep
					#on windows "winsound" should be implemented
					#import winsound
					#winsound.Beep(frequency, duration)

					#AEAACAB
import os

def playSound(frequency,duration):
	os.system('beep -f %s -l %s' % (frequency,duration))

def playSong(song):
	for i in range(len(song)):
		playSound(notes[song[i]],100)

notes = { "A":440, "B":494, "C":523, "D":587, "E":659, "F":698, "G":784}

song = raw_input("Notes: ABCDEFG \nEnter a song: ")

playSong(song)
