import random

# Define the board size.
BOARD_SIZE = 3

# Define the possible moves.
MOVES = [(0, 1), (0, -1), (1, 0), (-1, 0)]

# Define the winning conditions.
WINNING_CONDITIONS = [(0, 0), (0, 1), (0, 2),
                      (1, 0), (1, 1), (1, 2),
                      (2, 0), (2, 1), (2, 2)]

# Initialize the board.
board = [[' '] * BOARD_SIZE for _ in range(BOARD_SIZE)]

# Initialize the current player.
current_player = 'X'

# Start the game loop.
while True:

    # Get the player's move.
    move = input("Enter your move (1-9): ")
    move = int(move) - 1

    # Check if the move is valid.
    if move < 0 or move >= 9:
        print("Invalid move.")
        continue

    # Place the player's piece on the board.
    row = move // BOARD_SIZE
    col = move % BOARD_SIZE
    board[row][col] = current_player

    # Check if the player has won.
    for winning_condition in WINNING_CONDITIONS:
        if board[winning_condition[0]][winning_condition[1]] == board[winning_condition[2]][winning_condition[3]] == board[winning_condition[4]][winning_condition[5]] == current_player:
            print("Player {} has won!".format(current_player))
            break

    # Switch players.
    if current_player == 'X':
        current_player = 'O'
    else:
        current_player = 'X'

    # Check if the game is over.
    if all(board[row][col] != ' ' for row in range(BOARD_SIZE) for col in range(BOARD_SIZE)):
        print("The game is a tie.")
        break