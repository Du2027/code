import pygame
pygame.init()

window = pygame.display.set_mode((640,480))
pygame.display.set_caption("Pygame")
clock = pygame.time.Clock()

white = (255,255,255)
black = (0,0,0)
speed = 10
pos_rec = [0,0]
size_rec = [100,100]

active = True
while active == True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            active = False

        #elif event.type == pygame.KEYDOWN:
            #if event.key == pygame.K_UP:
                #pos_rec[1] = pos_rec[1] - speed
            #if event.key == pygame.K_DOWN:
                #pos_rec[1] = pos_rec[1] + speed
            #if event.key == pygame.K_LEFT:
                #pos_rec[0] = pos_rec[0] - speed
            #if event.key == pygame.K_RIGHT:
                #pos_rec[0] = pos_rec[0] + speed

    pressed_key = pygame.key.get_pressed()
    if pressed_key[pygame.K_UP]:
        pos_rec[1] = pos_rec[1] - speed
    if pressed_key[pygame.K_DOWN]:
        pos_rec[1] = pos_rec[1] + speed
    if pressed_key[pygame.K_RIGHT]:
        pos_rec[0] = pos_rec[0] + speed
    if pressed_key[pygame.K_LEFT]:
        pos_rec[0] = pos_rec[0] - speed

    window.fill((0,0,0))
    pygame.draw.rect(window, white, [pos_rec[0], pos_rec[1], size_rec[0], size_rec[1]])

    pygame.display.flip()
    pygame.time.Clock().tick(60)