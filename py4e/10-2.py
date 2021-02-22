# Chapter 10, ex. 2
# Find the distribution of the hour of the daty for each of the messages.

# prompting for filename and trying to open file
fname = input('Enter the file name: ')
try:
    fh = open(fname, 'r')
except:
    print('File %s cannot be opened.'%fname)
    exit()

# iterating over lines
d = dict()
for line in fh:
    lst = line.rstrip().split()
    if len(lst)>=6 and lst[0]=='From':
        time = lst[5]
        hour = time.split(':')[0]
        d[hour] = d.get(hour, 0) + 1
fh.close()

# creating and sorting a list of (value, key) tuples
lst = list(d.items())
lst.sort()

# displaying results
for hour, count in lst:
    print(hour, count)

