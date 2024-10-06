import tkinter as tk

input("hi")

dk = tk.Tk()

dk.resizable(height = False,width = False)
dk.geometry("1000x1000")
dk.title("Try to learn")

entry_1=tk.Entry(dk,width=400)
entry_1.pack(fill="x")

def create_entry():
    tk.Entry(dk).pack(fill="x")

Button = tk.Button(dk,command=create_entry)
Button.pack(fill="x")

def Fenster():
    aa=tk.Tk()
    aa.resizable(width=False,height=False)
    aa.geometry("800x800")

    lab1 = tk.Label(aa,text=entry_1.get())
    lab1.pack()

    aa.mainloop()

But1 = tk.Button(dk,command=Fenster,text="Continue")
But1.pack()

#tk.Label(Fenster, text=entry1.get()).pack()

dk.mainloop()