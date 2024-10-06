from pyautogui import *
import pyautogui
import time
import keyboard
import random
import win32api, win32con

#open python 3.10....
#write import pyautogui
#pyautogui.displayMousePosition()
#it will display the RGB values and the x and y cordinates from the pixel youre pointing at
#control + c to end it

#1.1674 x 600
#2.1525 x 600
#3.1350 x 600
#4.1200 x 600

#2 ways to do a click (actually a lot more)
#pyautogui.click(x=,y=) #move to x,y and then click left mouse

def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0)#L.M.Drücken
    time.sleep(0.01)#0.01 sek. warten
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0)#L.M.loslassen

#It runs a LOT faster than the other one

while keyboard.is_pressed("q") == False: # if you press q the thing stops
    if pyautogui.pixel(1674, 600)[0] == 59: # that checks if the pixel 1674, 600s R(red) value is 59, 0 = R value 1 Green value 2 = B value
        click(1674, 600)
    if pyautogui.pixel(1525, 600)[0] == 59:
        click(1525, 600)
    if pyautogui.pixel(1350, 600)[0] == 59:
        click(1350, 600)
    if pyautogui.pixel(1200, 600)[0] == 59:
        click(1200, 600)

