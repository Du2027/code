import tkinter as tk

window_name = tk.Tk()
window_name.geometry("500x500")
window_name.title("title")
window_name.resizable(width=False,height=False)

lab1 = tk.Label(window_name,text="text")
lab1.grid(row=0,column=0)

window_name.mainloop()
