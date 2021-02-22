# Chapter 10, ex. 1
# Find the email address with most messages by using
# a list of dictionary items.

# prompting for filename and trying to open file
fname = input('Enter the file name: ')
try:
    fh = open(fname, 'r')
except:
    print('File %s cannot be opened.'%fname)
    exit()

# iterating over lines
cc = dict()
for line in fh:
    lst = line.rstrip().split()
    if len(lst)>=2 and lst[0]=='From':
        email = lst[1]
        cc[email] = cc.get(email, 0) + 1
fh.close()

# creating and sorting a list of (value, key) tuples
lst = list()
for email, msgs in cc.items():
    lst.append((msgs, email))
lst.sort(reverse=True)

# displaying results
if len(lst)>0:
    print(lst[0][1], lst[0][0])  # email, messages

