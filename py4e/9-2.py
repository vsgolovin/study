# Chapter 9, ex. 2
# Categorize each mail message from the log by which day of the week the
# commit was done.

# prompting for filename and trying to open file
fname = input('Enter the file name: ')
try:
    fh = open(fname, 'r')
except:
    print('File %s cannot be opened.'%fname)
    exit()

# iterating over lines
wc = dict()
for line in fh:
    lst = line.rstrip().split()
    if len(lst)>=3 and lst[0]=='From':
        word = lst[2]
        wc[word] = wc.get(word, 0) + 1

# closing file and displaying results
fh.close()
print(wc)

