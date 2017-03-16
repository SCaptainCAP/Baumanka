from functions import *
from math import *

#debug = True
debug = False


def f1y(x, y):
    x3 = x ** 3
    return exp(x3 - y) - x3 * (x3 - 2 * y - 2) - y * y - 2 * y - 2


def f2y(x, y):
    return x * x * exp(-y) + y * exp(-y) - exp(x * x) * log(x * x + y)


if debug:
    left = 0
    right = 4
    step = 0.1
else:
    left = float(input('Введите начальное значение (X1): '))
    right = float(input('Введите конечное значение (X2): '))
    step = float(input('Введите шаг: '))

Xarr = []
Yarr = []
while left <= right:
    Xarr.append(left)
    Yarr.append(f(left))
    left += step

printTable(Xarr, Yarr)


arg = float(input('Введите значение аргумента: \n'))
power = int(input('Введите степень полинома: \n'))
answer = interpolation(arg, power, Yarr, Xarr)

if answer != None:
    print("\nТочное значение:                             ", f(arg))
    print("Значение, полученное с помощью интерполяции: ", answer)
    print("Погрешность:                                 ", abs(((answer - f(arg)) / f(arg)) * 100), "%")
