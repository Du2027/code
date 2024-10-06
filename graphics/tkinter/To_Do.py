import tkinter as tk 

window = tk.Tk()

window.resizable(width=False,height=True)
window.geometry("400x800")
window.title("App by @Du")

lab = tk.Label(window,text="TO DO's",width=25,font=("Arial",20),bg="red",height=2)
lab.grid(row=0,column=0)

but1 = tk.Button(window,text="Add")

def add_enty():
    tk.Entry(window).grid()
    but1.grid(row=1,column=2)

but = tk.Button(window,text=" Add To Do ",font=("Arial",10),command=add_enty)
but.grid(row=1,column=0,pady=5)



window.mainloop()