# Exercise 1: Write a program to read through a file and print the
# contents of the file (line by line) all in upper case.

fname = input('Enter a file name: ')
try:
    file = open(fname, 'r')
except:
    print('Could not open file %s'.format(fname))
    exit()
for line in file:
    line = line.upper()
    print(line.rstrip())

