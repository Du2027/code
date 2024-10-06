import tkinter as tk    
import time
import pyautogui
import keyboard

#tkinter window button to set pos of click and then var that stores a key and if  that key is pressed auto clicker is activated

Win = tk.Tk()
Win.geometry("600x500")
Win.title("Auto clicker")

tk.Label(text="                                                                   ").grid(column=0,row=0)

Überschrifft = tk.Label(text="AUTO CLICKER",font=("Arial",20)).grid(column=1,row=0)
Win.update()
time.sleep(3)
Win.destroy()