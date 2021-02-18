# Chapter 9, ex. 3
# Same as 9-2 but for email addresses.

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
    if len(lst)>=2 and lst[0]=='From':
        email = lst[1]
        wc[email] = wc.get(email, 0) + 1

# closing file and displaying results
fh.close()
print(wc)

