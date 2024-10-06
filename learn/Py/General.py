#Genaral----------------------------------------------------------------------------------------------------------

#With # can you create a comment that wont do anythig to your code

#With print() can you display something in the console
print("Hello world")

#You can create a variable with name = content (its like putting something in a box you name the box)
Hello = "World"

#You can use variables to output something
name = "johann"
print(name)

#To wait for user input to the console
input("Write something")

#You can store the user input to the console in a variable
print("Whats youre name?")
name = input()

#Data types------------------------------------------------------------------------------------------------------------------

#Text Type:	       str                                  ("hello")
#Number Types:	   int, float,                          (234)(2.11)
#Boolean Type:	   bool                                 (True/False)
#list Type:        list

#do eval() to do math - operations between strings
x = "20 + 20"
print(eval(x))

#Strings are Words with these "dubble" or 'single' quotes around them like: 
q = "hello"
q = 'hello again'

#If you dount know what type something is type:
x = 5
print(type(x))

#Convert int to a float and a float to an int via int(),float()but remember when you make a int out of a float it will always round down.
print(float(0))
print(int(0.99))

#You can round a number with:
print(round(1.99))
print(round(1.40))

#When you want to make a string containing quotion marks do it like here:
aa = "a hungry pig once said 'oink' "
print(aa)

#Notice the backslash character in 'Facebook\'s'
motto = 'Facebook\'s old motto was "move fast and break things".'
print(motto)

#We can add striongs with +
print("hello" + "xx")
#We call the process of linking two or more strings together concatenation

#We can also concatenate a string with one or more copies of itself using the * operator followed by a number that specifies how many times to multiply the string
print("hi+" *2)

#We can also write strings over many lines using the triple quotation mark symbol (''' or """).
text_1 = '''This is a sentence.
This is another sentence, on a different line.
This is a third sentence.'''

text_2 = """__________________
Line 1.
Line 2.
Line 3."""

print(text_1)
print(text_2)

#We can use int() and float() to convert a str(string) into a int or float
print(int('4') + 1)
print(float('3.3') + 1) 

#We can use str() to convert something into a string
print(str(11))

#Lists--------------------------------------------------------------------------------------------------------

#lists are a better alternative than using one variable per data point

#This is how we can create a list of data points
row_1 = ['Facebook', 0.0, 'USD', 2974676, 3.5]
print(row_1)
print(type(row_1))

#To find the length of a list, we can use the len() function
print(len(row_1))

#To print a part of the list and not all of it:
row_5 = ['Facebook', 0.0, 'USD', 2974676, 3.5]
print(row_5[2])
print(row_5[0])

#To print everything that is in the list
for element in row_5:
    print(element)

#You can also do things like this:
row_a = ['Facebook', 0.0, 'USD', 2974676, 3.5]
row_b = ['Instagram', 0.0, 'USD', 2161558, 4.5]

difference = row_b[4] - row_a[4]
average_rating = (row_a[4] + row_b[4]) / 2

print(difference)
print(average_rating)

#You can use positve indexing:
print(row_a[4])
#Or negative indexing
print(row_a[-1])

#You can store elements from a list into a list
row_q = ['Facebook', 0.0, 'USD', 2974676, 3.5]

fb_rating_data = [row_q[0], row_q[3], row_q[-1]]
print(fb_rating_data)

#Instead of selecting element by element, we can use a syntax shortcut:

row_3 = ['Clash of Clans', 0.0, 'USD', 2130805, 4.5]
cc_pricing_data = row_3[0:3] # Syntax shortcut(the number says we want index number 0-3)
print(cc_pricing_data)

#We can use           a_list[:x] when we want to select the first x elements.
# x stands for number a_list[-x:] when we want to select the last x elements.

#We can store lists in lists
row_1 = ['Facebook', 0.0, 'USD', 2974676, 3.5]
row_2 = ['Instagram', 0.0, 'USD', 2161558, 4.5]
row_3 = ['Clash of Clans', 0.0, 'USD', 2130805, 4.5]
row_4 = ['Fruit Ninja Classic', 1.99, 'USD', 698516, 4.5]
row_5 = ['Minecraft: Pocket Edition', 6.99, 'USD', 522012, 4.5]
data_set = [row_1, row_2, row_3, row_4, row_5]
print(data_set)

#To print something from a list in a list:
print(data_set[1][0])

#[[1, 2, 3], [4, 5, 6]]". Der Befehl "print( b[1][0] )" gäbe hierbei die Zahl 4 aus.

#For loops------------------------------------------------------------------------------------------------------

lane_1 = ['Facebook', 0.0, 'USD', 2974676, 3.5]
lane_2 = ['Instagram', 0.0, 'USD', 2161558, 4.5]
lane_3 = ['Clash of Clans', 0.0, 'USD', 2130805, 4.5]
lane_4 = ['Fruit Ninja Classic', 1.99, 'USD', 698516, 4.5]
lane_5 = ['Minecraft: Pocket Edition', 6.99, 'USD', 522012, 4.5]

print("ratings : ")

ratings = [1,2,3,4,5] # Some list
for element in ratings: #for each element in the ratings list, print 
    print(element)

print(" end ")
 
app_data_set = [lane_1, lane_2, lane_3, lane_4, lane_5]

for row in app_data_set: #for each row in app_data_set extract the last element.
    rating = row[-1] #The last element == -1
    print(rating)

Ratings = 0    

for row in app_data_set: 
    Ratings += row[-1]

avg = Ratings / len(app_data_set)#to calculate the avg. rating
print(avg)

#Some shit------------------------------------------------------------------------------------------------------

# if, and not, else, elif,or
# +, -, *, /
# +=, *=, -=, /=
# <, >, >=, <=

#We can't perform arithmetical operations between str and int but between float and int

#Range
print("range:")
for Aa in range(0,20,2):#from 0 to 20 in 2. steps 2,4,6,8,10 usw.
    print(Aa)

#Tkinter---------------------------------------------------------------------------------------------------------
#messagebox
from tkinter import messagebox as msg
response = msg.askokcancel("Title_of_Window","Text_in_Window")
print("Res:")#if user presses okay response == True
print(response)
#showinfo, showerror, showwarning, askquestion, askokcancel, askyesno is possible

#You need to import the module tkinter with:
import tkinter

#You can use 'as' to short the name tkinter a little bit (you need it later)
import tkinter as tk

#Or use this:
from tkinter import*
#It is the same but tk.Label = Label

#Load a picture in a variable
x_sign = PhotoImage(file = r"C:\Users\px431\Downloads\x_sign.png")

#load image with image = var
but = Button(text="quit",image = x_sign,command=None)

#With name_of_window = tk.Tk() you create a window (Write in name_of_window youre own window name)
name_of_window = tk.Tk()

#def to make a definition
def name_of_definition():
    name_of_window.destroy()

#You can change the title of the window with:
name_of_window.title("name_of_title")

#You can change the size of your window with (its X / Y in pixel):
name_of_window.geometry("800x400")

#With .resizeable you can change if the window should be resizeable or not
name_of_window.resizable(width = False, height = False)

#You can display text in youre window with a label:
label1=tk.Label(name_of_window,text="Text")

#Use font() to use another font(schriftart) and to change the size of the text
lab1=tk.Label(name_of_window,text="text", font=("Arial", 20))

#To display the Label on youre window:
label1.pack()
#You can only use one of them .grid or .pack

#OR use grid to place it better
#but.grid(row= 0 ,column = 0)

#Use .rowspan and .columnspan to make the rows and columns bigger

#Button
Butt1=tk.Button(name_of_window,text="Im a Button",command = None)
Butt1.pack()

#use padyx(),pady() to make some space between things

#.configure() to update something
def configure_first_button():
    Butt1.configure(command = name_of_definition)

Butt2=tk.Button(name_of_window,text="update first button",command= configure_first_button)
Butt2.pack()

#.keys to display what you can do
a = Butt1.keys()
print(a)

#.destroy to close a window
name_of_window.destroy()

#You need to write at the end name_of_window.mainloop
name_of_window.mainloop()

#Turtle---------------------------------------------------------------------------------

#first import turtle
from turtle import*

#pyautogui-------------------------------------------------------------------------------

#you can locate a pixel and the rgb values of it via pyautogui
#first open python
#type : import pyautogui
# and then : pyautogui.displayMousePosition()

#Macro----------------------------------------------------------------------------------

#first iport some Modules
from pyautogui import *
import pyautogui
import time
import keyboard
import win32api, win32con

#To stop the code for a cuple of seconds
time.sleep(1)

#You need to define a click:
def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0) #Mouse click
    time.sleep(0.01) # Hold mouse click
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0) # Release mouse click

#Or use this 
def click(x_y):
    pyautogui.moveTo(x_y)
    pyautogui.click()

#To check if something is on the screen
pyautogui.locateOnScreen('C:\Python\st_image_reg\point.png', confidence = 0.8)
        #Pyautogui would only locate the picture if its 100% the same
        #with confidence we can chane it cofidence 0.8 = 80%, 0.7 = 70% etc.
        #You can use grayscale = True to make it run faster but dont use it with colors

#Then make a while loop to loop the code
while keyboard.is_pressed("q") == True: #you dont need to write keyboard....("q") == False its only to stop the loop with the  letter q

    if pyautogui.pixel(1674, 600)[0] == 59: #The 0 means the Red value, is the R value 59 click on pixel 1674, 600
        click(1674, 600)
    if pyautogui.pixel(1525, 600)[0] == 59: #0 = Red value, 1 = Green value, 2 = Blue value
        click(0,0)

