
import numpy as np


def rotate_matrix( matrix:np.array ) -> None :

    last_value = 0
    for i in range(len(matrix)):
        matrix[0][i], last_value = last_value, matrix[0][i]

    for i in range(1, len(matrix)):
        matrix[ i ][ len(matrix)-1 ], last_value = last_value, matrix[i][len(matrix)-1]

    for i in range(1, len(matrix)):
        matrix[ len(matrix)-1 ][ len(matrix)-1-i ], last_value = last_value, matrix[len(matrix)-1][len(matrix)-1-i]

    for i in range(1, len(matrix)):
        matrix[ len(matrix)-i-1 ][0], last_value = last_value, matrix[ len(matrix)-i-1 ][0]

    if( len(matrix) >= 4 ):
        rotate_matrix( matrix[ 1:len(matrix)-1, 1:len(matrix)-1 ] )



if __name__ == '__main__':

    size = int(input())
#    matrix = [ input().rstrip().split() for i in range( size ) ]
    matrix = [ [*input()] for i in range(size) ]
    matrix = np.array( matrix )
    rotate_matrix( matrix )
    print(matrix)

