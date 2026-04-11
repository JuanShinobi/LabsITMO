import time

def calc(x):
    return x*x - x*x + x*4 - x*5 + x + x

while True:
    try:
        n = int(input("Enter iterations: "))
    except:
        print("Invalid input")
        break

    start = time.time()

    for i in range(n):
        calc(i)

    end = time.time()

    print("Time:", (end - start)*1000, "ms")

    repeat = input("Repeat? (1/0): ")

    if repeat == "0":
        break
