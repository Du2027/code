
def start_game(barrier_speed, fps, debug_mode):
    import pygame
    import os
    from random import randrange

    pygame.mixer.init()
    pygame.mixer.music.load("ingame-music.mp3")
    pygame.mixer.music.play()
    pygame.mixer.music.set_volume(0.1)
    def resource_path(relative_path):
        base_path = os.path.abspath(".")
        return os.path.join(base_path, relative_path)

    pygame.init()

    barrier_speed = barrier_speed / (fps / 60)
    ball_speed = 5

    window_sizes = pygame.display.get_desktop_sizes()
    window_count = len(window_sizes)

    window = pygame.display.set_mode((window_sizes[0][0] / 2, window_sizes[0][1] / 2))
    pygame.display.set_caption("Pong")
    pygame.display.set_icon(pygame.transform.scale(pygame.image.load(resource_path("icon.png")), (32, 32)))
    clock = pygame.time.Clock()

    barrier_offset = 10
    current_frame_count = 0
    start_pos = randrange(1, 5)
    velocity = [0,0]

    if start_pos == 1:
        velocity[0] = ball_speed
        velocity[1] = -ball_speed

    if start_pos == 2:
        velocity[0] = ball_speed
        velocity[1] = ball_speed

    if start_pos == 3:
        velocity[0] = -ball_speed
        velocity[1] = -ball_speed

    if start_pos == 4:
        velocity[0] = -ball_speed
        velocity[1] = ball_speed


    background_image = pygame.image.load(resource_path("Background.png"))
    background_image = pygame.transform.scale(background_image, (window_sizes[0][0] / 2, window_sizes[0][1] / 2))

    size_barriers = [window_sizes[0][0] / 110, window_sizes[0][1] / 10]
    pos_barrier1 = [0 + barrier_offset, 0]
    pos_barrier2 = [window_sizes[0][0] / 2 - window_sizes[0][0] / 100 - barrier_offset, 0]

    wall_sprite = pygame.transform.scale(pygame.image.load(resource_path("Wall.png")), (size_barriers[0], size_barriers[1]))
    ball_sprite = pygame.transform.scale(pygame.image.load(resource_path("Ball.png")), (50, 50))
    ball_pos = [window_sizes[0][0] / 4, window_sizes[0][1] / 4]

    active = True
    while active == True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                active = False
                pygame.mixer.quit()

        if current_frame_count != 60:
            current_frame_count += 1
        else:
            current_frame_count = 0

        if debug_mode == 1:
            print("Windows:", window_count, "   Main window size:", window_sizes[0], "   Ball velocity:", velocity)
        pressed_key = pygame.key.get_pressed()

        if pressed_key[pygame.K_UP] and pos_barrier1[1] > 0 + barrier_offset*1.5:
            pos_barrier1[1] -= barrier_speed
            pos_barrier2[1] -= barrier_speed

        if pressed_key[pygame.K_DOWN] and pos_barrier1[1] < window_sizes[0][1] / 2 - size_barriers[1] - barrier_offset:
            pos_barrier1[1] += barrier_speed
            pos_barrier2[1] += barrier_speed

        if pressed_key[pygame.K_ESCAPE]:
            active = False
            pygame.mixer.quit()
            import Menu

        if ball_pos[1] >= window_sizes[0][1] / 2 or ball_pos[1] <= 0:
            velocity[1] = -velocity[1]

        if ball_pos[0] >= pos_barrier2[0] and ball_pos[1] >= pos_barrier2[1] and ball_pos[1] <= pos_barrier2[1] + size_barriers[1]:
            velocity[0] = -velocity[0]

        if ball_pos[0] <= pos_barrier1[0] and ball_pos[1] >= pos_barrier1[1] and ball_pos[1] <= pos_barrier1[1] + size_barriers[1]:
            velocity[0] = -velocity[0]

        if ball_pos[0] <= 0 or ball_pos[0] >= window_sizes[0][0] / 2:
            pygame.mixer.music.load("death.mp3")
            pygame.mixer.music.play()
            active = False
            import Menu

        window.blit(background_image, (0, 0))
        window.blit(wall_sprite, (pos_barrier1[0], pos_barrier1[1]))
        window.blit(wall_sprite, (pos_barrier2[0], pos_barrier2[1]))
        window.blit(ball_sprite, (ball_pos[0], ball_pos[1]))
        ball_pos[0] = ball_pos[0] + velocity[0]
        ball_pos[1] = ball_pos[1] + velocity[1]

        #if ball_pos[0] <= pos_barrier1[0] + size_barriers[0]

        clock.tick(fps)
        pygame.display.update()