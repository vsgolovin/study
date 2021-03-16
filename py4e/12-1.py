# Chapter 12, ex. 1.
# Change the socket program to prompt the user for the URL.
# Only works with HTTP.

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

while True:
    data = mysock.recv(512)
    if len(data) < 1:
        break
    print(data.decode(),end='')

mysock.close()
