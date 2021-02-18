# Chapter 8, ex. 6
# Same as 5-2.py, but uses a list instead

nums = []
while True:
    inp = input("Enter a number: ")
    if inp == 'done':
        break
    try:
        number = float(inp)
    except:
        print("Invalid input")
        continue
    nums.append(number)

print(sum(nums), len(nums), min(nums), max(nums))

