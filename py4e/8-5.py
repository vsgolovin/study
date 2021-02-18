# Chapter 8, ex. 5
# Printing out email senders from a file

# opening the file
inp = input('Enter a file name: ')
try:
    f = open(inp, 'r')
except:
    print('Could not open file %s'%inp)
    exit()

# reading the file one line at a time
count = 0
for line in f:
    w = line.rstrip().split()
    lw = len(w)
    if lw<1 or w[0]!='From':
        continue
    count += 1
    if lw>1:
        print(w[1])
f.close()
print('There were %d lines in the file with From as the first word'%count)

