import sys

import pygame
import os

def resource_path(relative_path): # resource_path() so that pyinstaller works
    base_path = os.path.abspath(".")
    return os.path.join(base_path, relative_path)

def does_mouse_collide(pos_x, pos_y, size_x, size_y):
    mouse_position = pygame.mouse.get_pos()

    if mouse_position[0] >= pos_x and mouse_position[1] >= pos_y:
        if mouse_position[0] >= pos_x + size_x:
            return "no_collide"
        if mouse_position[1] >= pos_y + size_y:
            return "no_collide"
        else:
            return "collide"

pygame.init()

window_sizes = pygame.display.get_desktop_sizes()
icon = pygame.transform.scale(pygame.image.load(resource_path("icon.png")), (32, 32))
logo = pygame.transform.scale(pygame.image.load(resource_path("Pong-Logo.png")), (window_sizes[0][0] / 6, window_sizes[0][1] / 6))
background = pygame.transform.scale(pygame.image.load(resource_path("Background-Menu.png")), (window_sizes[0][0] / 2, window_sizes[0][1] / 2))
window = pygame.display.set_mode((window_sizes[0][0] / 2, window_sizes[0][1] / 2))
clock = pygame.time.Clock()
pygame.display.set_caption("Menu")
pygame.display.set_icon(icon)

Start_button_size = (window_sizes[0][0] / 8, window_sizes[0][1] / 10)
Start_button = pygame.Surface((Start_button_size[0], Start_button_size[1]))
Start_button.fill((255, 0, 0))
Start_button_pos = (window_sizes[0][0] / 4 - Start_button_size[0] / 2, window_sizes[0][1] / 4)

play_sprite = pygame.transform.scale(pygame.image.load(resource_path("Play.png")), (Start_button_size[0], Start_button_size[1]))

amplitude = window_sizes[0][1] / 100

window.blit(background, (0, 0))
window.blit(logo, (window_sizes[0][0] / 4 - (window_sizes[0][0] / 6) / 2, window_sizes[0][1] / 10 - 0.5 *(window_sizes[0][1] / 7)))
window.blit(play_sprite, (Start_button_pos[0], Start_button_pos[1]))

debug_mode = 0

try:
    if sys.argv[1] == "-debug":
        debug_mode = 1
except:
    debug_mode = 0

pygame.mixer.init()
pygame.mixer.music.load("menu-music.mp3")
pygame.mixer.music.play()
pygame.mixer.music.set_volume(0.1)

Quit = False
while Quit != True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            Quit = True
            pygame.mixer.quit()

        pressed_key = pygame.key.get_pressed()
        if pressed_key[pygame.K_ESCAPE]:
            Quit = True
            pygame.mixer.quit()

        if event.type == pygame.MOUSEBUTTONUP:
            mouse_pos = pygame.mouse.get_pos()
            if does_mouse_collide(Start_button_pos[0], Start_button_pos[1], Start_button_size[0], Start_button_size[1]) == "collide":
                import pong
                pong.start_game(17, 140, debug_mode) #somehow if fps > 60 then the game runs slower than with 60 or 30 fps
                Quit = True
                pygame.mixer.quit()


    clock.tick(60)
    pygame.display.flip()