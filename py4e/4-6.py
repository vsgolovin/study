# Exercise 6: Rewrite your pay computation with time-and-a-half for
# overtime and create a function called `computepay` which takes two
# parameters (hours and rate)

def computepay(hours, rate):
    if hours <= 40:
        pay = hours*rate
    else:
        pay = rate*40 + 1.5*rate*(hours-40)
    return pay

err_msg = "Error, please enter numeric input"
err = False

# prompting for hours worked
hours = input("Enter Hours: ")
try:
    hours = float(hours)
except:
    print(err_msg)
    err = True

# prompting for hourly rate
if not err:
    rate = input("Enter Rate: ")
    try:
        rate = float(rate)
    except:
        print(err_msg)
        err = True

# calculating and displaying pay
if not err:
    pay = computepay(hours, rate)
    print("Pay: "+str(pay))

