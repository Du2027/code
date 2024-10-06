
import tkinter as tk
from tkinter import Button, Label, ttk
from tkinter import font

def page2():
    start.destroy()

    p2=tk.Tk()
    p2.configure(background='black')
    p2.geometry("600x200")
    p2.title("page2")
    
    p2lab1=tk.Label(p2,bg="orange",font=("Arial", 20),text="Console and print()",height="2",width="18")
    p2lab1.pack(fill="x")

    def page3():
        p2.destroy()
    
        p3=tk.Tk()
        p3.configure(background='black')
        p3.geometry("600x250")
        p3.title("page3")

        p3lab1=tk.Label(p3,bg="orange",font=("Arial", 20),text="Variables",height="2",width="18")
        p3lab1.pack(fill="x")

        def page4():
            p3.destroy()

            p4=tk.Tk()
            p4.configure(background='black')
            p4.title("page4")
            p4.geometry("600x200")
            p4.resizable(width=False, height=False)

            def page5():
                p4.destroy()

                p5=tk.Tk()
                p5.configure(background='black')
                p5.title("page5")
                p5.geometry("600x200")
                p5.resizable(width=False, height=False)

                def page6():
                    p5.destroy()

                    p6=tk.Tk()
                    p6.configure(background='black')
                    p6.title("page6")
                    p6.geometry("600x300")
                    p6.resizable(width=False, height=False)

                    p6but1=tk.Button(p6,text="next page",width="8",height="2",bg="orange", font=("Arial", 13))
                    p6but1.pack(side="right",fill="y")

                    p6lab1=tk.Label(p6,font=("Arial",30),text="Costomize ur Tk window",bg="orange",height=2)
                    p6lab1.pack(fill="x")

                p5but1=tk.Button(p5,text="next page",width="8",height="2",bg="orange", font=("Arial", 13),command=page6)
                p5but1.pack(side="right",fill="y")

                p5lab1=tk.Label(p5,font=("Arial",30),text="Tkinter",height="1",bg="orange")
                p5lab1.pack(fill="x")

                p5lab2=tk.Label(p5,font=("Arial",12),text="We use Tkinter for creating GUI's(grapical user interface)")
                p5lab2.pack()

                p5lab3=tk.Label(p5,font=("Arial",12),text="simplifyed we use Tkinter for crating a window")
                p5lab3.pack()

                p5lab4=tk.Label(p5,font=("Arial",12),text="first we start with a variable/ hi")
                p5lab4.pack()

                p5lab5=tk.Label(p5,font=("Arial",12),text="then we create a window with tk.TK()/ hi=tk.TK()")
                p5lab5.pack()

            p4but1=tk.Button(p4,text="next page",width="8",height="2",bg="orange", font=("Arial", 13),command=page5)
            p4but1.pack(side="right",fill="y")

            p4lab1=tk.Label(p4,font=("Arial",30),bg="orange",text="Functions")
            p4lab1.pack(fill="x")

            p4lab2=tk.Label(p4,font=("Arial",12),text="Functoins are used very often.")
            p4lab2.pack()

            p4lab3=tk.Label(p4,font=("Arial",12),text="U can create a Function with def name():")
            p4lab3.pack()

            p4lab4=tk.Label(p4,font=("Arial",12),text="U can use a function when u create a button,")
            p4lab4.pack()

            p4lab5=tk.Label(p4,font=("Arial",12),text="and u want the button to do something")
            p4lab5.pack()


        p3butt1=tk.Button(p3,text="next page",width="8",height="2",bg="orange", font=("Arial", 13),command=page4)
        p3butt1.pack(side="right",fill="y") 
        
        p3lab2=tk.Label(p3,text="Variables are like putting things in a box", font=("Arial", 12))
        p3lab2.pack()

        p3lab3=tk.Label(p3, font=("Arial", 12),text="hi = allo")
        p3lab3.pack()

        p3lab4=tk.Label(p3, font=("Arial", 12),text="we made a variable called hi and stored allo(Value) in it")
        p3lab4.pack()

        p3lab5=tk.Label(p3, font=("Arial", 12),text="when we now use print(hi) then it will be display the value of hi")
        p3lab5.pack()

        p3lab6=tk.Label(p3, font=("Arial", 12),text="print(hi) / Output= alla")
        p3lab6.pack()

    p2butt1=tk.Button(p2,text="next page",width="8",height="2",bg="orange", font=("Arial", 13),command=page3)
    p2butt1.pack(side="right",fill="y")

    p2lab2=tk.Label(p2, font=("Arial", 12),text="In the so called console,")
    p2lab2.pack()

    p2lab3=tk.Label(p2, font=("Arial", 12),text="there will be displayed outputs like when you use print(hi),")
    p2lab3.pack()

    p2lab4=tk.Label(p2, font=("Arial", 12),text="in the console will be displayed hi")
    p2lab4.pack()

    p2lab5=tk.Label(p2, font=("Arial", 12),text="The command print()")
    p2lab5.pack()

    p2lab6=tk.Label(p2, font=("Arial", 12),text="We use the command print() to display something in the Console")
    p2lab6.pack()

start=tk.Tk()
start.configure(background='black')
start.title("HI")

start.geometry("600x200")
start.resizable(width=False, height=False)

lab1=tk.Label(start,text="Welcomme",bg="orange", font=("Arial", 20),height="2",width="18")
lab1.pack(fill="x")

but1=tk.Button(start,text="next page",width="8",height="2",bg="orange", font=("Arial", 13),command=page2)
but1.pack(side="right",fill="y")

lab2=tk.Label(start,text="Hi and welcomme to my little guide to Tkinter", font=("Arial", 12))
lab2.pack()

lab3=tk.Label(start,text="On the left side is a button for previous page", font=("Arial", 12))
lab3.pack()

lab4=tk.Label(start,text="and on the right side is a button for the next page", font=("Arial", 12))
lab4.pack()

lab4=tk.Label(start,text="Made by @Du2072", font=("Arial", 12))
lab4.pack()

start.mainloop()