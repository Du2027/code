from ctypes.wintypes import PINT


print("Welcome to PRIMZAHL")
num = 0
while num == 0:
    number = input("Which number do u wish to try?:")
    if str.isdecimal(number) == True:
        number = int(number)
        num = 1
    else:
        print("you need to type in numbers")

len_number2 = number/2
print(number,len_number2,type(len_number2))

if type(len_number2) == float:
    print("number is odd")
else: print("number isnt odd")
  

