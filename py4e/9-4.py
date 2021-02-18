# Chapter 9, ex. 4
# Find the email address with most messages.

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

ad_max = 'no emails found'
ec_max = 0
for email in wc:
    if wc[email]>ec_max:
        ec_max = wc[email]
        ad_max = email

# closing file and displaying results
fh.close()
print(ad_max, ec_max)

