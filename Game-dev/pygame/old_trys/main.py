import pygame
import sys

pygame.init()

hintergund=pygame.image.load("C:\Python\pygame.py\Grafiken/hintergrund.png")
screen = pygame.display.set_mode([1200,595])#große Fensters
clock = pygame.time.Clock()
pygame.display.set_caption("First game")#Fenster name

stehen = pygame.image.load("C:\Python\pygame.py\Grafiken/stand.png")
sprung = pygame.image.load("C:\Python\pygame.py\Grafiken/sprung.png")
rechtsGehen = [pygame.image.load("C:\Python\pygame.py\Grafiken/rechts1.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/rechts2.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/rechts3.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/rechts4.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/rechts5.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/rechts6.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/rechts7.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/rechts8.png")]
linksGehen = [pygame.image.load("C:\Python\pygame.py\Grafiken/links1.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/links2.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/links3.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/links4.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/links5.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/links6.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/links7.png"),pygame.image.load("C:\Python\pygame.py\Grafiken/links8.png")]



def zeichnen(liste):
    global schritteRechts,schritteRechts

    screen.blit(hintergund, (0,0))#hintergrund laden
    richtung=[0,0,0,0]#links,rechts,stand,sprung
    schritteRechts = 0
    schritteLinks = 0
    if schritteRechts == 63:
        schritteRechts = 0
    if schritteLinks == 63:
        schritteLinks = 0
    pygame.display.update()

    if liste[0]:
        screen.blit(linksGehen[schritteLinks//8], (x,y))
    if liste[1]:
        screen.blit(rechtsGehen[schritteRechts//8], (x,y))
    if liste[2]:
        screen.blit(stehen, (x,y))
    if liste[3]:
        screen.blit(sprung, (x,y))



x = 300
y = 439
geschw = 5
breite = 40
hoehe = 80

linkeWand = pygame.draw.rect(screen, (255,255,255) , (0,0,2,600) , 0)
rechteWand = pygame.draw.rect(screen, (0,0,0) , (1198,0,2,600) , 0)

go = True
sprungvar = -16

while go:
    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()

    spielerRechteck=pygame.Rect(x,y,40,80)
    gedrueckt = pygame.key.get_pressed()
    richtung = [0,0,1,0]
    if gedrueckt[pygame.K_UP] and sprungvar == -16:#k_up= pfeiltaste oben
        sprungvar=15
    if gedrueckt[pygame.K_RIGHT] and not spielerRechteck.colliderect(rechteWand):
        x += geschw
        richtung = [0,0,1,0]
        schritteRechts += 1
    if gedrueckt[pygame.K_LEFT] and not spielerRechteck.colliderect(linkeWand):
        x -= geschw
        richtung = [0,1,0,0]
        schritteLinks += 1
    if sprungvar >= -15:
        richtung = [0,0,0,1]
        n = 1
        if sprungvar < 0:
            n = -1
        y -= (sprungvar**2)*0.17*n
        sprungvar -= 1
    if richtung[2] or richtung[3]:
        schritteRechts = 0
        schritteLinks = 0

    zeichnen(richtung)
    clock.tick(60)#fps