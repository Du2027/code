from pyautogui import *
import pyautogui
import time
import keyboard
import random
import win32api, win32con

def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0)
    time.sleep(0.01)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0)


while keyboard.is_pressed("q") == False: 
    if pyautogui.pixel(1674, 600)[0] == 59: 
        click(1674, 600)
    if pyautogui.pixel(1525, 600)[0] == 59:
        click(1525, 600)
    if pyautogui.pixel(1350, 600)[0] == 59:
        click(1350, 600)
    if pyautogui.pixel(1200, 600)[0] == 59:
        click(1200, 600)

