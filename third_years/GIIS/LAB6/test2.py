import pygame
import random
import sys
import string

pygame.init()

screen_width = 1920
screen_height = 1080
num_columns = 100  # Количество столбцов
column_width = screen_width // num_columns  # Ширина каждого столбца
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Матрица")

font_size = 23
font = pygame.font.Font(None, font_size)

allowed_characters = ''.join([char for char in string.printable if char not in ".!,/~`:^*)(-_" ])
def random_char():
    return random.choice(allowed_characters)

class MatrixStream:
    def __init__(self, num_column):
        self.x = num_column * column_width  
        self.speed = random.randint(2, 8)
        self.chars = [random_char() for _ in range(random.randint(5, 35))]
        self.position = random.randint(0,num_columns)  
        self.char_y = [-600 + font_size * i + self.position for i in range(len(self.chars))]
        self.last_char_update = pygame.time.get_ticks()
        self.bottom_border = random.choice((350, 400, 450, 500, 550, 600))  # Случайная нижняя граница экрана
        self.temp = []
    def update(self):
        
        for i in range(len(self.char_y)):
            self.char_y[i] += self.speed

            if self.char_y[i] > self.bottom_border:
                self.temp.append((-screen_height - font_size) + font_size * i)
                self.char_y[i] = -font_size  # Перемещаем символ выше экрана

    def update_chars(self):
        current_time = pygame.time.get_ticks()
        update_interval = 50
        if current_time - self.last_char_update >= update_interval:
            self.chars[random.randint(0, len(self.chars) - 1)] = random_char()
            self.last_char_update = current_time

    def draw(self):
        char_spacing = font_size * 0.01  # Задаем расстояние между символами (можете настроить под свой вкус)
        for i, char in enumerate(self.chars):
            brightness = i / len(self.chars)
            start_color = (0, 204, 0) 
            end_color = (104, 236, 152) 
            text_color = (
                int(start_color[0] + brightness * (end_color[0] - start_color[0])),
                int(start_color[1] + brightness * (end_color[1] - start_color[1])),
                int(start_color[2] + brightness * (end_color[2] - start_color[2]))
            )
            text = font.render(char, False, text_color)
            char_x = self.x  # Начальная позиция X символа
            char_y = self.char_y[i] + i * char_spacing  # Позиция Y символа с учетом расстояния между символами
            screen.blit(text, (char_x, char_y))

# Создание списка объектов MatrixStream
streams = [MatrixStream(i) for i in range(num_columns)]

frames = []
from PIL import Image
while True:
    screen.fill((0, 0, 0))
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # Обновление и отрисовка каждой падающей строки
    for stream in streams:
        stream.update()
        stream.update_chars()
        stream.draw()

    pygame.display.flip()
    pygame.time.delay(40)  # Задержка для управления скоростью анимации
    '''frame_surface = pygame.display.get_surface().copy()
    frame = pygame.surfarray.pixels3d(frame_surface)
    frame = frame.swapaxes(0, 1)
    frames.append(frame)

    # Если прошло достаточно кадров (пятая секунда, с учетом задержки 50 мс)
    if len(frames) >= 140:
        break

# Создайте GIF из списка кадров
image_frames = [Image.fromarray(frame) for frame in frames]
image_frames[0].save('matrix_animation.gif', save_all=True, append_images=image_frames[1:], loop=0, duration=50)'''