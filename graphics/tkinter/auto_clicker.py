import time
import pyautogui
import keyboard
import tkinter as tk

window = tk.Tk()
window.geometry("200x200")
window.title("Cicker")
window.resizable(width=False, height=False)

def get_mouse():
    time.sleep(2)
    mp = pyautogui.displayMousePosition()

b1 = tk.Button(text="get pos", command=get_mouse).pack()
label1 = tk.Label(text="SELECT OPTION:" )
label1.pack()

window.mainloop()
print(mp)