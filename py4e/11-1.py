# Chapter 11, ex. 1
# Simple program for simulating `grep`.

import re

expr = input('Enter a regular expression: ')
fh = open('mbox.txt', 'r')
i = 0
for line in fh:
    if re.search(expr, line):
        i += 1
fh.close()
print('mbox.txt had %d lines that matched %s'%(i, expr))

