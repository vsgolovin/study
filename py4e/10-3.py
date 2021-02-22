# Chapter 10, ex. 3
# Count all letters in the text file.

# prompting for filename and trying to open file
fname = input('Enter the file name: ')
try:
    fh = open(fname, 'r')
except:
    print('File %s cannot be opened.'%fname)
    exit()

# couting letters
d = dict()
for line in fh:
    for c in line:
        if c.isalpha():
            c = c.lower()
            d[c] = d.get(c, 0) + 1
fh.close()

# dict -> list of tuples
lst = list()
for letter, count in d.items():
    lst.append((count, letter))

# sorting and displaying results
lst.sort(reverse=True)
for count, letter in lst:
    print(letter, count)

