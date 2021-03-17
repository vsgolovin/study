# Chapter 12, ex. 4.
# Change `urllinks.py` to extract and count paragraph (p) tags.

import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter - ')
html = urllib.request.urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, 'html.parser')

# Retrieve all of the paragraph tags
tags = soup('p')

# Display number of paragraphs
print("Total paragraphs:", len(tags))

