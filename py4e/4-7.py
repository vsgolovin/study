# Exercise 7: Rewrite the grade program from the previous chapter using a
# function called `computegrade` that takes a score as its parameter and
# returns a grade as a string.

def computegrade(score):
    try:
        score = float(score)
    except:
        pass
    if type(score)!=float or score > 1.0 or score < 0.0:
        grade = 'Bad score'
    elif score >= 0.9:
        grade = 'A'
    elif score >= 0.8:
        grade = 'B'
    elif score >= 0.7:
        grade = 'C'
    elif score >= 0.6:
        grade = 'D'
    else:
        grade = 'F'
    return grade

score = input('Enter score: ')
grade = computegrade(score)
print(grade)

