# Chapter 11, ex. 2
# Find lines of the form:
# `New Revision: 39772`
# and compute the average of the numbers.

from re import findall

# open the file
fname = input('Enter file: ')
try:
    fh = open(fname, 'r')
except:
    print('Could not open', fname)
    exit()

# reading through the file
nums = list()
for line in fh:
    num = findall('^New Revision: ([\d]+)', line)
    if len(num)==1:
        num = int(num[0])
        nums.append(num)

# calculating average
if len(nums)>0:
    avg = sum(nums)/len(nums)
    print('%d'%avg)
