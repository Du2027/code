from pyautogui import *
import pyautogui
import time
import keyboard
import win32api, win32con

def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0)
    time.sleep(0.01)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0)

while keyboard.is_pressed("q") == False:
    if pyautogui.pixel(355,742)[0] == 253:
        click(355,742)
    if pyautogui.pixel(342,765)[0] == 44:
        click(342,765)