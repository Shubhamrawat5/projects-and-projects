
import pygame
import os
import random
from os import path

pygame.init()
pygame.font.init()
pygame.mixer.init()

WIDTH = 480
HEIGHT = 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
font_name = pygame.font.match_font('arial')

###AUDIO
# Background Music
pygame.mixer.music.load(path.join('Assets', 'tgfcoder-FrozenJam-SeamlessLoop.ogg'))
pygame.mixer.music.set_volume(0.01)
pygame.mixer.music.play(loops=-1)
# Sound FX
catch_sound = pygame.mixer.Sound(path.join('Assets', 'fruit-sound.wav'))

test_list = [250, 500, 750, 1000]  # Potential intervals to drop mangos (in milliseconds)
WIDTH, HEIGHT = 900, 900
WIN = pygame.display.set_mode((WIDTH, HEIGHT))  # Draw window for game
pygame.display.set_caption("Tuffy Catches Mangoes")  # Title of window

# RGB COLOR CODES----
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
PINK = (255, 174, 201)
Tuffy = (255, 255, 0)

LIFE_FONT = pygame.font.SysFont('comicsans', 40)
LOSER_FONT = pygame.font.SysFont('comicsans', 100)

FPS = 60
VEL = 2.8
BULLET_VEL = 3
tuffy_Width, tuffy_Height = 192, 192
MANGO_WIDTH, MANGO_HEIGHT = 80, 80
catch = pygame.USEREVENT + 1
miss = pygame.USEREVENT + 2
spawn = pygame.USEREVENT + 3

right = True

TUFFY_ART = pygame.image.load(  # Load elephant image
    os.path.join('Assets', 'Tuffy01.png'))
TUFFY = pygame.transform.scale(  # Change elephant  size
    TUFFY_ART, (tuffy_Width, tuffy_Height))
MANGO_IMAGE = pygame.image.load(  # Load the mango
    os.path.join('Assets', 'mango01.png'))
MANGO = pygame.transform.scale(  # Take the loaded mango and scale it
    MANGO_IMAGE, (MANGO_WIDTH, MANGO_HEIGHT))
SPACE = pygame.transform.scale(pygame.image.load(
    os.path.join('Assets', 'Hills.jpg')), (WIDTH, HEIGHT))
# SPACE = convert_Alpha(pygame.transform.scale(pygame.image.load( #Background
#     os.path.join('Assets', 'Hills.png')), (WIDTH, HEIGHT)))
TUFFY_FLIPPED = pygame.transform.scale(pygame.transform.flip(TUFFY_ART, True, False), (tuffy_Width, tuffy_Height))


# *********DISPLAY*********#
def draw_window(Tuffy, falling_mangos, score, life, right, streak):
    # MESSAGES
    WIN.blit(SPACE, (0, 0))
    score_text = LIFE_FONT.render("SCORE: " + str(score), 1, BLACK)
    life_text = LIFE_FONT.render("LIFE: " + str(life), 1, RED)
    streak_text = LIFE_FONT.render("STREAK: " + str(streak), 1, PINK)

    WIN.blit(score_text, (10, 10))
    WIN.blit(life_text, (10, 45))
    WIN.blit(streak_text, (10, 80))
    if (right == True):
        WIN.blit(TUFFY, (Tuffy.x, Tuffy.y))
    elif (right == False):
        WIN.blit(TUFFY_FLIPPED, (Tuffy.x, Tuffy.y))

    for bullet in falling_mangos:
        WIN.blit(MANGO, (bullet.x, bullet.y))
    pygame.display.update()


# **********MOVEMENT**********#
def handle_tuffy_movement(keys_pressed, Tuffy, right):
    if keys_pressed[pygame.K_LSHIFT] and keys_pressed[pygame.K_LEFT] and Tuffy.x - VEL > -15:  # LEFT DASH
        Tuffy.x -= 1.4 * VEL
        right = False
    elif keys_pressed[pygame.K_LSHIFT] and keys_pressed[
        pygame.K_RIGHT] and Tuffy.x + VEL + Tuffy.width < 900:  # RIGHT DASH
        Tuffy.x += 1.4 * VEL
        right = True
    elif keys_pressed[pygame.K_LEFT] and Tuffy.x - VEL > -15:  # LEFT
        Tuffy.x -= VEL
        right = False
    elif keys_pressed[pygame.K_RIGHT] and Tuffy.x + VEL < 708:  # RIGHT
        Tuffy.x += VEL
        right = True

    return right


# *********FRUIT*********#
def handle_mangos(falling_mangos, Tuffy):
    for bullet in falling_mangos:
        bullet.y += BULLET_VEL
        if Tuffy.colliderect(bullet):  # WE CATCH IT
            pygame.mixer.Sound.play(catch_sound)
            pygame.event.post(pygame.event.Event(catch))
            falling_mangos.remove(bullet)
        elif bullet.y > 750:  # WE DONT CATCH
            pygame.event.post(pygame.event.Event(miss))
            falling_mangos.remove(bullet)


def draw_loser(text):
    draw_text = LOSER_FONT.render(text, 1, RED)
    WIN.blit(draw_text, (WIDTH / 2 - draw_text.get_width() /
                         2, HEIGHT / 2 - draw_text.get_height() / 2))
    pygame.display.update()
    pygame.time.delay(2000)


def draw_text(surf, text, size, x, y):
    font = pygame.font.Font(font_name, size)
    text_surface = font.render(text, True, WHITE)
    text_rect = text_surface.get_rect()
    text_rect.midtop = (x, y)
    surf.blit(text_surface, text_rect)


def show_go_screen():
    draw_text(screen, "TuffyHacks", 64, WIDTH / 2, HEIGHT / 4)
    draw_text(screen, "Arrow keys move, Shift to dash", 22,
              WIDTH / 2, HEIGHT / 2)
    draw_text(screen, "Press a key to begin", 18, WIDTH / 2, HEIGHT * 3 / 4)
    pygame.display.flip()
    waiting = True
    while waiting:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            if event.type == pygame.KEYUP:
                waiting = False

show_go_screen()
def main():
    Tuffy = pygame.Rect(354, 708, tuffy_Width, tuffy_Height + 300)
    falling_mangos = []
    score = 0
    life = 13
    right = True
    streak = 0
    pygame.time.set_timer(spawn, random.choice(test_list))

    while True:

        for event in pygame.event.get():
            if event.type == spawn:
                mango = pygame.Rect(random.randint(0, 820), -100, 80, 40)
                falling_mangos.append(mango)
                pygame.time.set_timer(spawn, random.choice(test_list))
            if event.type == pygame.QUIT:
                run = False
                pygame.quit()

            if event.type == catch:
                score += 1
                streak += 1

            if event.type == miss:
                life -= 1
                streak = 0
                if life == 0:
                    draw_loser("You let the mangoes down.")
                    life = 13
                    score = 0

        keys_pressed = pygame.key.get_pressed()
        right = handle_tuffy_movement(keys_pressed, Tuffy, right)

        handle_mangos(falling_mangos, Tuffy)

        draw_window(Tuffy, falling_mangos,
                    score, life, right, streak)

    main()


if __name__ == "__main__":
    main()
