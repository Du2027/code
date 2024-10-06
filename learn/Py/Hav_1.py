name = input("Whats your name").capitalize().title()

#name = name.strip()#del all spaces out of the first one
#name = name.capitalize()#del all capitalyses
#name = name.title()#capital every word beginn

#name = name.title().capitalize()#works too

print(f"hello, {name}")#f for format string

print(round(2.6))

#round(number[,ndigits]) # ndigits optionally
print(round(2.6,4))

z = 10000000000000

print(f"{z:,}")# . after 3x 0

x = 1
print(f"hello, {x}")


from random import choice

animes = ["naruto","7_deadly_sins"]
print(choice(animes))