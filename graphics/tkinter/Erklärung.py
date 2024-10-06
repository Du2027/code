
from ast import Compare
import tkinter as tk

from turtle import *
from tkinter import ttk
#from PIL import Image,ImageTk

root=tk.Tk()
root.geometry("800x400")

#größe des Fensters in px
root.title("HIIIIII")

#Tietel des Fensters

root.resizable(width=False, height=False)

#Ob Fenster höhen und tiefen verstellbar sein soll

root.minsize(width=800, height=400)#min. größe
root.maxsize(width=800, height=400)#max größe

label1=tk.Label(root, text="hallo", bg="pink")
label1.pack(side="top", expand=False)

quit_button = ttk.Button(root,text="Quit",command=root.destroy,compound="right")
quit_button.pack()


#label erzeugt sogesagt n textfeld
#Text = der text der da stehen soll
#bg = Hintergrundfarbe(red,green etc.)
#side = die seite (left,right,top,bottom)
#expand = musste ansehen (True,False)
#fill ist ob es eine richtung füllen soll (x,y,both)

label2=tk.Label(root, text="peace", bg="red")
label2.pack(expand=False)

label3=ttk.Label(root, text="ich bin ttk",)
label3.pack()

#Der code, der das Verhalten eines Widgets implimentiert, wird soweit wie möglich -
#Von dem code entfernt,der sein Erscheinungsbild implimentiert(ttk)

label4=tk.Label(root,)
label4.config(text="Hello world")
label4.config(bg='green')
label4.pack()

#config is dass mann es configurieren kann

#image = Image.open("360_F_281175138_tACu0FqKCDnD54rBd3cL3X8D0bqkkXeU.jpg").resize((150,50))
#photo= ImageTk.PhotoImage(image)

#label5=ttk.Label(root, image=photo)
#label5.pack()

#Drei Wege Code zu ändern
#1.Dierekt bei der Objekt erzeugung
#2.Schlüsselschreibweise zb. label1["text"] = "Das isn Text"
#3.configure methode label1.configure(...)

#image1 = Image.open("360_F_281175138_tACu0FqKCDnD54rBd3cL3X8D0bqkkXeU.jpg").resize((150,50))
#photo1= ImageTk.PhotoImage(image1)

#label6=ttk.Label(root, image=photo1)
#label6.pack()


#image = Image.open("360_F_281175138_tACu0FqKCDnD54rBd3cL3X8D0bqkkXeU.jpg").resize((150,50))
#photo2= ImageTk.PhotoImage(image)

#label7 = ttk.Label(root, text="MOINNNNN", image=photo2, compound="right")#mög sind (right,center,left,top.bottom)
#label7.pack()

#mit compund wird txt ins oder nebens bild gepackt

#print(label1.keys())

#mit .keys werden alle möglichen optionen auf der Console angezeigt

for item in label1.keys():
    print(item, ": ",label1[item])

# jetzt wird dass gleiche wie bei norm. .keys angezeitgt nur das angezeit wird auf welchem wert wir das grad haben
# es gibt auch padding=000 das macht n abstandt zwischen rand zb (root, text="MOINNNNN", image=photo2, padding=50)
# font ist schriftart ändern zb. label.configure(font=("Arial", 30)) Die 30 ist schriftgröße

def say_hello():
    print("hallo")
    
#def macht eine funktion

button1 = tk.Button(root, text="Click me" ,command=say_hello)
button1.pack(fill="x")

#command eine funktion zuordnen un die wird ausgeführt wen der butten gedrückt wird

root.mainloop()


