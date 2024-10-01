#!/usr/bin/python3
""""Function to rotate 2D Matric"""


def rotate_2d_matrix(matrix):
    """ "rotation 2D Matrix"""
    matrix[:] = list(map(list, zip(*matrix[::-1])))
