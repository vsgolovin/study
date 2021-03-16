# Chapter 12, ex. 2.
# Change your socket program so that it counts the number of characters it
# received and stops displaying any text after it has shown 3000
# characters. The program shold retrieve teh entire document and count the
# total number of characters and display it at the end of the document.

import socket

while True:
    try:
        url = input("Enter URL: ")
        hostname = url.split('/')[2]
        mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        mysock.connect((hostname, 80))
        break
    except: 
        print("Invalid URL.")
        continue

cmd = ('GET '+url+' HTTP/1.0\r\n\r\n').encode()
mysock.send(cmd)

# first 3000 characters
received = 0
to_receive = 3000
while received < to_receive:
    packet_size = min([512, to_receive-received])
    data = mysock.recv(packet_size)
    if len(data) < 1:  # less than 3000 characters total
        break
    received += len(data)
    print(data.decode(),end='')

# rest of document
while len(data) >= 1:
    data = mysock.recv(512)
    if len(data) < 1:
        break

print("Total characters:", received)
mysock.close()
