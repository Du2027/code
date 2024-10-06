from pyautogui import *
import pyautogui
import time
import keyboard
import win32api, win32con

time.sleep(5)

#1 X:  711 Y:  558
#2 X:  871 Y:  559
#3 X: 1015 Y:  559
#4 X: 1164 Y:  567

def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0)
    time.sleep(0.01)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0)

while keyboard.is_pressed("q") == False:
    if pyautogui.pixel(711, 600)[1] <= 120:
        click(711, 558) 
    if pyautogui.pixel(871, 600)[1] <= 120:
        click(871, 600)
    if pyautogui.pixel(1015, 600)[1] <= 120:
        click(1015, 600)
    if pyautogui.pixel(1164, 600)[1] <= 120:
        click(1164, 600)