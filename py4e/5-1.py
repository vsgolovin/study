# Exercise 1: Write a program which repeatedly reads numbers until the
# user enters "done". Once "done" is entered, print out the total, count,
# and average of the numbers. If the user enters anything other than a
# number, detect their mistake using `try` and `except` and print an error
# message and skip to the next number.

total = 0
count = 0
while True:
    inp = input("Enter a number: ")
    if inp == 'done':
        break
    try:
        number = float(inp)
    except:
        print("Invalid input")
        continue
    total += number
    count += 1

print(total, count, total/count)

