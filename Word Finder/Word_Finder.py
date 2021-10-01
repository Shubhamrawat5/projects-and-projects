from tkinter import *
import tkinter
from tkinter import messagebox
def reset():
    E1.delete(0,END)
    E2.delete(0,END)
    E3.delete(1.0,END)
def process():
   try:
      l=list(st.get())
      n=nu.get()
      from itertools import permutations as pr
      tot = pr(l, n)
      with open('outw.txt', 'w+') as f, open("dict-a_to_z.txt", 'r') as dic:
          f.truncate()
          dici = dic.read().strip().split()
          for i in tot:
              s = ""
              for j in (i):
                  s = s + j
              if str(s) in dici:
                  f.write(str(s) + "\n")
          f.seek(0)
          te = f.read()
          f.close()
      E3.insert(tkinter.END,te)

   except:
       messagebox.showwarning("Type correct details!!!")

top = tkinter.Tk()
L1 = Label(top, text="Word Finder",).grid(row=0,column=1)
L2 = Label(top, text="Random word",).grid(row=1,column=0)
L3 = Label(top, text="Number of letters",).grid(row=2,column=0)
L4 = Label(top, text="Answer",).grid(row=3,column=0)

st = tkinter.StringVar()
E1 = Entry(top,textvariable = st,width=100, bd =5)
E1.grid(row=1,column=1)
nu=tkinter.IntVar()
E2 = Entry(top,textvariable = nu,width=100,bd =5)
E2.grid(row=2,column=1)
E2.delete(0, END)
E3 = tkinter.Text(top, height=20,width=100,bd =5)
E3.grid(row=3,column=1)

B=Button(top, text ="FIND",command = process).grid(row=6,column=0,)
C=Button(top, text ="RESET",command = reset).grid(row=6,column=1,)
top.mainloop()