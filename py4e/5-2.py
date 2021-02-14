# Exercise 2: Write another program that prompts for a list of numbers as
# above and at the end prints out both the maximum and minimum of the
# numbers instead of the average.

total = 0
count = 0
num_min = None
num_max = None
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
    if num_min is None or number < num_min:
        num_min = number
    if num_max is None or number > num_max:
        num_max = number

print(total, count, num_min, num_max)

