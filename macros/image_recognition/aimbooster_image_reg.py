from pyautogui import *
import pyautogui
import keyboard

def click(x_y):
    pyautogui.moveTo(x_y)
    pyautogui.click()

while keyboard.is_pressed("q") == False:
    cords = pyautogui.locateOnScreen('C:\Python\st_image_reg\point.png', confidence = 0.8)
    if cords != None:
        cords = center(cords) # To transform the left top cords to x,y
        click(cords)
