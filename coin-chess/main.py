import re
from random import getrandbits, randint
from typing import Tuple
import itertools

LENGTH = 4
SIZE = LENGTH ** 2
MODE = "single"

SQUARE_MAP = [(i//LENGTH, i%LENGTH) for i in range(SIZE)]

# utils

def print_board(board_state: int):
    board_str = '{1:0{0}b}'.format(SIZE, board_state)
    grid_str = "\n".join(re.findall('.' * LENGTH, board_str))

    boarder = '-' * LENGTH

    print(boarder + "\n" + grid_str + "\n" + boarder)

def get_square_from_board(board_state: int):
    board_str = '{1:0{0}b}'.format(SIZE, board_state)

    square = [0,0]
    for i,m,s in zip(range(SIZE), SQUARE_MAP, board_str):
        square[0] += int(s) * m[0]
        square[1] += int(s) * m[1]

    square[0] %= LENGTH
    square[1] %= LENGTH

    return tuple(square)

def get_potential_flips(key_square, current_square):
    col_diff = key_square[1] - current_square[1]
    row_diff = key_square[0] - current_square[0]

    col_diff = col_diff if col_diff >= 0 else LENGTH + col_diff
    row_diff = row_diff if row_diff >= 0 else LENGTH + row_diff

    col_cands = [0] if col_diff == 0 else [col_diff, LENGTH - col_diff]
    row_cands = [0] if row_diff == 0 else [row_diff, LENGTH - row_diff]

    return list(itertools.product(col_cands, row_cands))

def apply_coin_flip(board_state, flip):
    flip_square = flip[1] * LENGTH + flip[0]
    new_state = board_state ^ (1 << (SIZE - flip_square - 1))
    return new_state

def apply_coin_flip_ind(board_state, flip_square):
    new_state = board_state ^ (1 << (SIZE - flip_square - 1))
    return new_state

# problem generators

def generate_random_problem():
    board_state = getrandbits(SIZE)
    key_square = (randint(0, LENGTH-1), randint(0, LENGTH-1))
    return board_state, key_square

if __name__ == "__main__":

    print("Solving MODE({}) on a {}x{} board".format(MODE, LENGTH, LENGTH))

    if MODE == "random":
        board_state, key_square = generate_random_problem()
        print("Key square : {}".format(key_square))
        print_board(board_state)

        current_board_square = get_square_from_board(board_state)
        print("Board square : {}".format(current_board_square))

        for flip in range(SIZE):
            flipped_board = apply_coin_flip_ind(board_state, flip)
            print("Flipped: {}".format(flip))
            print_board(flipped_board)
            candidate_key_square = get_square_from_board(flipped_board)
            print("New Square: {}".format(candidate_key_square))
            if candidate_key_square == key_square:
                print("Solution found")
                break

    elif MODE == "single":
        board_str = "0000000000000001"
        board_state = int(board_str, 2)
        key_square = (1,1)
        print("Key square : {}".format(key_square))
        print_board(board_state)

        current_board_square = get_square_from_board(board_state)
        print("Stuff:{}".format(current_board_square))
        print("Board square: {}".format(current_board_square))

        for flip in range(SIZE):
            flipped_board = apply_coin_flip_ind(board_state, flip)
            print("Flipped: {}".format(flip))
            print_board(flipped_board)
            candidate_key_square = get_square_from_board(flipped_board)
            print("New Square: {}".format(candidate_key_square))
            if candidate_key_square == key_square:
                print("Solution found")
                break
    elif MODE == "all":
        for board_state in range(2 ** SIZE):
            for key_ind in range(SIZE):
                key_square = SQUARE_MAP[key_ind]
                print("Solving board state {} @ ind {}".format(board_state, key_ind))
                print(key_ind)
                solved = False
                for flip in range(SIZE):
                    flipped_board = apply_coin_flip_ind(board_state, flip)
                    candidate_key_square = get_square_from_board(flipped_board)
                    print("Trying flip {}".format(flip))
                    print_board(flipped_board)
                    print("Yeilds: {}".format(candidate_key_square))
                    if candidate_key_square[0] == key_square[0] and candidate_key_square[1] == key_square[1]:
                        print("Solution found")
                        solved = True
                        break
                if not solved:
                    print("Can't solve set")
                    print("Key square:{}".format(candidate_key_square))
                    print_board(board_state)
                    exit()
    else:
        print("ERROR: invalid MODE")
        exit()
