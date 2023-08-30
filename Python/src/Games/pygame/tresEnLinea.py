from curses import COLOR_GREEN
import pygame
import sys

# Inicialización de Pygame
pygame.init()

# Configuración de la pantalla
WIDTH, HEIGHT = 300, 300
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Tres en Raya")

# Colores
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
LINE_COLOR = (0, 0, 0)

# Tablero
board = [[None, None, None],
         [None, None, None],
         [None, None, None]]

# Dimensiones de las celdas
CELL_SIZE = WIDTH // 3

# Dibuja el tablero
def draw_board():
    for row in range(3):
        for col in range(3):
            pygame.draw.rect(screen, WHITE, (col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE), 2)
            if board[row][col] == 'X':
                pygame.draw.line(screen, COLOR_GREEN, (col * CELL_SIZE, row * CELL_SIZE), (col * CELL_SIZE + CELL_SIZE, row * CELL_SIZE + CELL_SIZE), 2)
                pygame.draw.line(screen, LINE_COLOR, (col * CELL_SIZE + CELL_SIZE, row * CELL_SIZE), (col * CELL_SIZE, row * CELL_SIZE + CELL_SIZE), 2)
            elif board[row][col] == 'O':
                pygame.draw.circle(screen, LINE_COLOR, (col * CELL_SIZE + CELL_SIZE // 2, row * CELL_SIZE + CELL_SIZE // 2), CELL_SIZE // 2, 2)

# Comprueba si alguien ha ganado
def check_winner(player):
    for row in range(3):
        if all([cell == player for cell in board[row]]):
            return True
    for col in range(3):
        if all([board[row][col] == player for row in range(3)]):
            return True
    if all([board[i][i] == player for i in range(3)]) or all([board[i][2 - i] == player for i in range(3)]):
        return True
    return False

# Turnos
player_turn = 'X'

# Bucle principal del juego
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if player_turn == 'X':
                row = event.pos[1] // CELL_SIZE
                col = event.pos[0] // CELL_SIZE
                if board[row][col] is None:
                    board[row][col] = 'X'
                    player_turn = 'O'
                    if check_winner('X'):
                        print("¡Jugador X gana!")
            elif player_turn == 'O':
                row = event.pos[1] // CELL_SIZE
                col = event.pos[0] // CELL_SIZE
                if board[row][col] is None:
                    board[row][col] = 'O'
                    player_turn = 'X'
                    if check_winner('O'):
                        print("¡Jugador O gana!")

    screen.fill(BLACK)
    draw_board()
    pygame.display.flip()