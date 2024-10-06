from tkinter import *
from PIL import Image,ImageTk
from tkinter import messagebox as msg

# if problem with dataways
#try \ to \\ or r before string or \ to / or jpg to png
#padx and pady to add a little space in a grid between stuff
#x_sign = PhotoImage(file = r"C:\Users\px431\Downloads\x_sign.png")
 
#lab = Label(text="                                                                                                                                                    ").grid(row=0,column=0)
#but = Button(text="quit",image = x_sign,command=window.destroy).grid(row=0,column=1)

#compound = LEFT -> image will be at left side of the button
#compound = RIGHT -> image will be at right side of button
#compound = TOP -> image will be at top of button
#compound = BOTTOM -> image will be at bottom of button

window = Tk()
 
window.geometry("505x500")
window.resizable(width=False ,height=False)
window.iconbitmap('C:\Python\Fenster\grid\Calculator.ico')
window.title("My Calculator") 

num = ""
Lab1 = Label(window,text=num,borderwidth=1, relief="solid",width=45,height=3,font=("Arial", 15))


def clear():
	global num
	num = ""
	Lab1.config(text=num)


def click_zero():
	global num
	num += "0"
	Lab1.config(text=num)
	
 
def click_one():
	global num
	num += "1"
	Lab1.config(text=num)
 
def click_two():
	global num
	num += "2"
	Lab1.config(text=num)

def click_three():
	global num
	num += "3"
	Lab1.config(text=num)

def click_four():
	global num
	num += "4"
	Lab1.config(text=num)

def click_five():
	global num
	num += "5"
	Lab1.config(text=num)

def click_six():
	global num
	num += "6"
	Lab1.config(text=num)

def click_seven():
	global num
	num += "7"
	Lab1.config(text=num)

def click_eight():
	global num
	num += "8"
	Lab1.config(text=num)

def click_nine():
	global num
	num += "9"
	Lab1.config(text=num)

def click_durch():
	global num
	num += "/"
	Lab1.config(text=num)

def click_times():
	global num
	num += "*"
	Lab1.config(text=num)

def click_plus():
	global num
	num += "+"
	Lab1.config(text=num)

def click_minus():
	global num
	num += "-"
	Lab1.config(text=num)

def equal():
	msg.showinfo("Youre Result",str(eval(num)))
	
But_durch = Button(window,text = "/",command=click_durch,width=16,height=6).grid(row=3,column=3,padx=2,pady=2)
But_times = Button(window,text = "*",command=click_times,width=16,height=6).grid(row=4,column=3,padx=2,pady=2)
But_plus = Button(window,text = "+",command=click_plus,width=16,height=6).grid(row=1,column=3,padx=2,pady=2)
But_minus = Button(window,text = "-",command=click_minus,width=16,height=6).grid(row=2,column=3,padx=2,pady=2)


But0 = Button(window,text = "0",command =click_zero,width=16,height=6).grid(row=1,column=0,padx=2,pady=2)
But1 = Button(window,text = "1",command =click_one,width=16,height=6).grid(row=1,column=1,padx=2,pady=2)
But2 = Button(window,text = "2",command =click_two,width=16,height=6).grid(row=1,column=2,padx=2,pady=2)
But3 = Button(window,text = "3",command =click_three,width=16,height=6).grid(row=2,column=0,padx=2,pady=2)
But4 = Button(window,text = "4",command =click_four,width=16,height=6).grid(row=2,column=1,padx=2,pady=2)
But5 = Button(window,text = "5",command =click_five,width=16,height=6).grid(row=2,column=2,padx=2,pady=2)
But6 = Button(window,text = "6",command =click_six,width=16,height=6).grid(row=3,column=0,padx=2,pady=2)
But7 = Button(window,text = "7",command =click_seven,width=16,height=6).grid(row=3,column=1,padx=2,pady=2)
But8 = Button(window,text = "8",command =click_eight,width=16,height=6).grid(row=3,column=2,padx=2,pady=2)
But9 = Button(window,text = "9",command =click_nine,width=16,height=6).grid(row=4,column=0,padx=2,pady=2)


But10= Button(window,text = "clear",command =clear,width=16,height=6).grid(row=4,column=2,padx=2,pady=2)
But10= Button(window,text = "=",command =equal,width=16,height=6).grid(row=4,column=1,padx=2,pady=2)

Lab1.grid(columnspan=5, row=0,column=0,padx=2,pady=2)

window.mainloop()