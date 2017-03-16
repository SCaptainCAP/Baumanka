def printTable(Xarr, Yarr):
    print("\nТаблица:")
    print("---------------------")
    print('    x    |     y    ')
    print("---------------------")
    for i in range(len(Xarr)):
        print('{0:<7f} | {1:<7f}'.format(Xarr[i], Yarr[i]))
    print("---------------------")


def find_position(x, n, mas):
    len_arr = len(mas)
    if (x < mas[0]) | (x > mas[len_arr - 1]):
        if x < mas[0]:
            return 0, n
        else:
            return len_arr - n - 1, len_arr - 1
    else:
        i = 0
        len_arr = len(mas)
        while i < len_arr - 1:
            if (mas[i] <= x) & (mas[i + 1] >= x):
                if i + n > len_arr - 1:
                    return len_arr - n - 1, len_arr - 1
                else:
                    return i, i + n
            i += 1


def koef(Xarr, Yarr, delta):
    if len(Yarr) == 1:
        return Yarr[0]
    else:
        temp = []
        i = 0
        while i <= len(Yarr) - 2:
            y_temp = (Yarr[i] - Yarr[i + 1]) / (Xarr[i] - Xarr[i + 1 + delta])
            temp.append(y_temp)
            i += 1
        delta += 1
        return koef(Xarr, temp, delta)


def interpolation(arg, power, Xarr, Yarr):
    if power + 1 > len(Xarr):
        print("\nВычисление полинома \
степени {0} невозможно: степень слишком велика".format(power))
    else:
        left, right = find_position(arg, power, Xarr)
        stepper = left
        sum = Yarr[stepper]
        Xrazn = arg - Xarr[stepper]
        delta = 2
        while stepper != right:
            sum += Xrazn * koef(Xarr[left:left + delta], Yarr[left:left + delta], 0)
            stepper += 1
            Xrazn *= arg - Xarr[stepper]
            delta += 1
        return sum