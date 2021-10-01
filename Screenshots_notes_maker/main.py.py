import os

import pyautogui
import pyperclip as pc
p=[]
temp=1
files=[]
from pynput.keyboard import Key, Listener

f1='2'
f2='4'
def show(key):
    global files, p, temp, f1, f2,del_l,ss_l
    if f1!=ss_l and str(key)=='\''+ss_l+'\'':
        f1=ss_l
    elif f2!=ss_l and str(key)=='\''+ss_l+'\'':
            f2=ss_l

    elif f1 != del_l and str(key) == '\''+del_l+'\'':
        f1 = del_l
    elif f2 != del_l and str(key) == '\''+del_l+'\'':
        f2 = del_l
    else:
        f1 = '2'
        f2='1'
    if str(key) =='\'\\x11\'' or (f1==f2 and f1==ss_l):
        f1='2'
        f2='1'
        clip = list(pc.paste().split())   #it will take the name of ss from clipboard 

        if clip != p:
            p = clip[:]
            temp = 1
        cnow = clip[:]

        if '|' in cnow:
            cnow.remove('|')
        cnow = " ".join(cnow) + '-' + str(temp)
        print(cnow)
        myScreenshot = pyautogui.screenshot()
        try:
            myScreenshot.save(r'D:\Giga\Cisco Networking ss notes\{}.png'.format(cnow))  #path where to save the screen_shots
            files.append(r'D:\Giga\Cisco Networking ss notes\{}.png'.format(cnow))
            print("Done")
        except:
            print("Error in file name")

        temp += 1
    elif str(key) == '\'\\x0c\'' or (f1==f2 and f1==del_l):
        f1='2'
        f2='1'
        try:

            os.remove(files[-1])
            print("{} file deleted".format(files[-1]))
            files.pop()
            temp-=1
        except:
            print("File not found!")

print("Input one letter that you will press two times to take screenshot--",end=" ")
x=input()
if len(x)==1:
    ss_l=x
print("Input one letter that you will press two times to delete last saved screenshot--",end=" ")
x=input()
if len(x)==1:
    del_l=x

with Listener(on_press=show) as listener:
    listener.join()


