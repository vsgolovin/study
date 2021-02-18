# Chapter 9, ex. 5
# Same as 9-3 but store domain names instead of emails.

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
    if len(lst)>=2 and lst[0]=='From':
        email = lst[1]
        if '@' in email:
            _, domain = email.split('@')
            d[domain] = d.get(domain, 0) + 1

# closing file and displaying results
fh.close()
print(d)

