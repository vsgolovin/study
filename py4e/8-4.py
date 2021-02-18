# Exercise 4: Write a program to open the file *romeo.txt* and read it
# line by line. For each line, split the line into a list of words using
# the `split` function. For each word, check to see if the word is already
# in a list. If the word is not in a list, add it to the list.

f = open('romeo.txt', 'r')
words = []
for line in f:
    line = line.rstrip()
    line_list = line.split()
    for word in line_list:
        if word not in words:
            words.append(word)
f.close()

words.sort()
print(words)

