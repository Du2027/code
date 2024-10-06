#from turtle import width
import pygame

x = pygame.init()

white = (255, 255, 255)
black = (0, 0, 0)
red = (255, 0, 0)

game_display = pygame.display.set_mode((800, 600))
pygame.display.set_caption("donk'd")

#pygame.display.update()
#pygame.display.flip() does the same 

gameExit = False

while gameExit == False:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameExit = True
        #print(event)
    game_display.fill(white)
    pygame.draw.rect(game_display, black, [400, 300, 100, 10])  #screen, color,starting x,y, width,height
    pygame.draw.rect(game_display, red, [400, 300, 10, 10])

    game_display.fill(red, rect=[200, 200, 15, 15])

    pygame.display.update()

pygame.quit()
quit()
