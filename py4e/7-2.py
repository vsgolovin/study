# Exercise 2: Write a program to prompt for a file name, and then read
# through the file and look for lines of the form:
# `X-DSPAM-Confidence: 0.8475`
# Compute and print out the average spam confidence.

fname = input('Enter a file name: ')
try:
    file = open(fname, 'r')
except:
    print('Could not open file %s'.format(fname))
    exit()

x_count = 0
x_sum = 0
for line in file:
    if not line.startswith('X-DSPAM-Confidence:'):
        continue
    ind = line.find(':')
    xi = float(line[ind+1:].strip())
    x_count += 1
    x_sum += xi

print('Average spam confidence: %f'%(x_sum/x_count))

