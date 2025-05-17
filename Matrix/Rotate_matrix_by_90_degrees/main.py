# import sys

# def flip_matrix(matrix):
#     for i in range(len(matrix)):
#         left,right = 0,len(matrix[i])-1
#         while(left <= right):
#             if(matrix[i][left] == matrix[i][right]):
#                 matrix[i][left] = 1-matrix[i][left]
#                 matrix[i][right] = matrix[i][left]
#             left += 1
#             right -= 1
#     return matrix

# def rotate90Clockwise(A):
#     N = len(A[0])
#     for i in range(N // 2):
#         for j in range(i, N - i - 1):
#             temp = A[i][j]
#             A[i][j] = A[N - 1 - j][i]
#             A[N - 1 - j][i] = A[N - 1 - i][N - 1 - j]
#             A[N - 1 - i][N - 1 - j] = A[j][N - 1 - i]
#             A[j][N - 1 - i] = temp
#     return A

# def rotate90ClockwiseUtil(A, n):
#     for i in range(n):
#         A = rotate90Clockwise(A)
#     return A

# def getFinalImage(image, rotation, vertical, horizontal):
#     rotate = {90: 1, 180: 2, 270: 3}
#     image = rotate90ClockwiseUtil(image, rotate[rotation])
#     if vertical:
#         image = rotate90ClockwiseUtil(image, 2)
#     if horizontal:
#         image = flip_matrix(image)
#     for i in range(len(image[0])):
#         print(image[i])

# if __name__ == '__main__':
#     image = [[1, 0, 0], [0, 1, 1], [0, 0, 1]]
#     rotation = 270
#     vertical = 0
#     horizontal = 1
#     sys.exit(getFinalImage(image, rotation, vertical, horizontal))

