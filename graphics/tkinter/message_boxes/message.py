from tkinter import *
from PIL import ImageTk,Image
from tkinter import messagebox

window = Tk()
window.title("Message_box")
window.geometry("400x400")
window.resizable(width = False, height = False)
window.iconbitmap("C:/Users/px431/Downloads/Bild_2022-05-08_154102817.ico")#ändert icon muss .ico sein wenn nicht Funktioniert \ zu / machen

def popup():
    response = messagebox.showinfo("This is my popup", "Hello World") #First window title 2nd Text
    print(response) # when the entire thing is in a variable you can do something with these buttons
    #if pressed yes button output = true, 

#showinfo, showerror, showwarning, askquestion, askokcancel, askyesno

Button(window,text="Popup",command=popup,height=5).pack(fill = "x") 

window.mainloop()