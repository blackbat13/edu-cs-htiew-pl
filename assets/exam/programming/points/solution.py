def exercise1():
    tab = [[False] * 101 for _ in range(101)]
    result = 0
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            if not tab[row][col]:
                result += 1
                tab[row][col] = True
    
    print("Zadanie 1:", result)


def exercise2():
    rows = [False] * 101
    cols = [False] * 101
    rowCount = 0
    colCount = 0
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            if not rows[row]:
                rowCount += 1
                rows[row] = True
            if not cols[col]:
                colCount += 1
                cols[col] = True

    print("Zadanie 2:")
    print("Wiersze:", rowCount)
    print("Kolumny:", colCount)


def exercise3():
    tab = [[0] * 101 for _ in range(101)]
    result = 0
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1
            if tab[row][col] == 2:
                result += 1
    
    print("Zadanie 3:", result)

def exercise4():
    tab = [[0] * 101 for _ in range(101)]
    maxVal = 0
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1
            maxVal = max(maxVal, tab[row][col])

    print("Wartość:", maxVal)
    print("Współrzędne:")

    for row in range(1, 101):
        for col in range(1, 101):
            if tab[row][col] == maxVal:
                print(row, col)

def exercise5():
    tab = [[0] * 102 for _ in range(102)]
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1

    result = 0
    for row in range(1, 101):
        for col in range(1, 101):
            if tab[row][col] > 0:
                if tab[row - 1][col] == 0 and tab[row + 1][col] == 0 and tab[row][col - 1] == 0 and tab[row][col + 1] == 0:
                    result += 1

    print("Zadanie 5:", result)

def exercise6():
    tab = [[0] * 101 for _ in range(101)]
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1

    counters = [0] * 4
    for row in range(1, 101):
        for col in range(1, 101):
            counters[tab[row][col]] += 1
    
    for i in range(len(counters)):
        print(f"Wartość {i}: {counters[i]}")

def exercise7():
    tab = [[0] * 101 for _ in range(101)]
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1

    sum1 = 0
    sum2 = 0
    sum3 = 0
    sum4 = 0
    for row in range(1, 101):
        for col in range(1, 101):
            if row == col:
                sum1 += tab[row][col]
            elif col == 101 - row - 1:
                sum2 += tab[row][col]
            
            if row > col:
                sum3 += tab[row][col]
            elif row < col:
                sum4 += tab[row][col]

    print("Główna przekątna:", sum1)
    print("Druga przekątna:", sum2)
    print("Pod główną przekątną:", sum3)
    print("Nad główną przekątną:", sum4)

def exercise8():
    tab = [[0] * 101 for _ in range(101)]
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1

    result = 0

    for row in range(1, 100):
        for col in range(1, 100):
            current_set = set()
            for i in range(2):
                for j in range(2):
                    current_set.add(tab[row + i][col + j])

            if len(current_set) == 4:
                result += 1

    print("Zadanie 8:", result)


for i in range(1, 9):
    exec(f"exercise{i}()")
    print()
