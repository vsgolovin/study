# Exercise 2: Rewrite your pay program using `try` and `except` so that
# your program handles non-numeric input gracefully by printing a message
# and exiting the program.

err_prompt = "Error, please enter numeric input"
err = False

# prompting for hours worked
hours = input("Enter Hours: ")
try:
    hours = float(hours)
except:
    print(err_prompt)
    err = True

# prompting for hourly rate
if not err:
    rate = input("Enter Rate: ")
    try:
        rate = float(rate)
    except:
        print(err_prompt)
        err = True

# calculating pay
if not err:
    if hours<=40:
        pay = hours*rate
    else:
        pay = 40*rate + (hours-40)*rate*1.5
    print("Pay: "+str(pay))

