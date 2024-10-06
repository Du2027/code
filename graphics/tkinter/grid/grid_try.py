from tkinter import *
from PIL import Image,ImageTk

window = Tk()
window.geometry("400x400")


lab = Label(window, text="hi tho")
lab.grid(row=0, column=0)

lab2 = Label(window, text="           ")
lab2.grid(row=0, column=1)

lab1 = Label(window, text="Bye tho")
lab1.grid(row=0, column=2)

logo = Image.open('C:\Python\st_image_reg\point.png')
logo = ImageTk.PhotoImage(logo)
logo_label = Label(image=logo)
logo_label.grid(row=2, column=1)

window.mainloop()

#rowspan  and columnspan to increase size of it 