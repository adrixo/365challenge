#!/usr/bin/python

#implementing franciscouzco's code - https://www.reddit.com/r/dailyprogrammer/comments/pxsew/2202012_challenge_12_difficult/
#pygame and beep required

import os
import pygame
from pygame import *

def playSound(frequency,duration):
	os.system('beep -f %s -l %s' % (frequency,duration))

screen = pygame.display.set_mode((640, 480))
done = False
while not done:
    pygame.event.pump()
    keys = pygame.key.get_pressed()
    if keys[K_ESCAPE]:
        done = True
    elif keys[K_a]:
        playSound(440, 100)
    elif keys[K_b]:
        playSound(494, 100)
    elif keys[K_c]:
        playSound(523, 100)
    elif keys[K_d]:
        playSound(587, 100)
    elif keys[K_e]:
        playSound(659, 100)
    elif keys[K_f]:
        playSound(698, 100)
    elif keys[K_g]:
        playSound(784, 100)
