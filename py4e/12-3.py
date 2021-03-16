# Chapter 12, ex. 3.
# Same as 12.2 but with urllib.

from urllib.request import urlopen

# getting url
while True:
    try:
        url = input("Enter URL: ")
        fhand = urlopen(url)
        break
    except:
        print("Invalid URL.")
        continue

# receiving first 3000 characters
received = 0
while received < 3000:
    data = fhand.read(500)
    psize = len(data)
    if psize<1: break  # reached end of document
    received += psize
    print(data.decode().strip())

# receiving the rest of a document
while psize>=1:
    data = fhand.read(512)
    psize = len(data)
    received += psize

print("Total characters:", received)
fhand.close()

