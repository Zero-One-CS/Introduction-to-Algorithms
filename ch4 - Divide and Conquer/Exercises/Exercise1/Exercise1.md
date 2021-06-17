# Exercise 1

Modify Strassen’s algorithm to multiply n*n matrices in which n is not an exact power of 2 (Odd Number) Show that the resulting algorithm runs in time Big-Theta `n**log(7)`.

### EX-1:

Giving `MartixA = [{1, 2, 3}, {4, 5, 6}, {7, 8, 9}]` and `MatriXB = [{1, 2, 1}, {2, 4, 6}, {7, 2, 5}]`

Answer should be: `[{26, 16, 28}, {50, 40, 64}, {86, 64, 100}]`

### EX-2:

Giving `MartixA = [{1, 2, 3, 5}, {4, 5, 6, 6}, {7, 8, 9, 7}, {1, 2, 3, 4}]` and `MatriXB = [{1, 2, 1, 2}, {2, 4, 6, 6}, {7, 2, 5, 1}, {4, 3, 2, 1}]`

Answer should be: `[{46, 31, 38, 22}, {80, 58, 76, 50}, {114, 85, 114, 78}, {42, 28, 36, 21}]`
