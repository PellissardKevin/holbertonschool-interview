#!/usr/bin/python3

import sys


def is_safe(board, row, col, n):
    for i in range(row):
        if board[i] == col:
            return False

    for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
        if board[i] == j:
            return False

    for i, j in zip(range(row - 1, -1, -1), range(col + 1, n)):
        if board[i] == j:
            return False

    return True


def solve_nqueens(n):
    def solve(row):
        if row == n:
            result.append(board[:])
            return
        for col in range(n):
            if is_safe(board, row, col, n):
                board[row] = col
                solve(row + 1)
                board[row] = -1

    result = []
    board = [-1] * n
    solve(0)
    return result


def print_solutions(solutions):
    for solution in solutions:
        formatted_solution = [[i, col] for i, col in enumerate(solution)]
        print(formatted_solution)


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = solve_nqueens(N)
    print_solutions(solutions)


if __name__ == "__main__":
    main()
