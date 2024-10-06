from pyautogui import *
import pyautogui
import time
import keyboard
import win32api, win32con

while 1:
    if pyautogui.locateOnScreen('C:\Python\st_image_reg\stickman.png', confidence=0.8, grayscale = True) != None:
        #Pyautogui would only locate the picture if its 100% the same-
        #with confidence we can chane it cofidence 0.8 = 80%, 0.7 = 70% etc.
        #You can use grayscale = True to make it run faster but dont use it with colors
        print("i can see it")
        time.sleep(0.5)
    else:
        print("im unable to see it")
        time.sleep(0.5)
