from func import *
from math import *

debug = True


def f(x):
    return sin(pi / 6 * x)


if debug:
    left = 0
    right = 4
    step = 0.1
else:
    left = float(input('Введите начальное значение: '))
    right = float(input('Введите конечное значение: '))
    step = float(input('Введите шаг: '))

Xarr = []
Yarr = []
while left <= right:
    Xarr.append(left)
    Yarr.append(f(left))
    left += step

print_table(Xarr, Yarr)

arg = float(input('Введите значение аргумента: '))
power = int(input('Введите степень полинома: '))
answer = interpolation(arg, power, Xarr, Yarr)

print("\nТочное значение:                             ", f(arg))
print("Значение, полученное с помощью интерполяции: ", answer)
print("Погрешность:                                 ", abs(((answer - f(arg)) / f(arg)) * 100), "%")
