#!/usr/bin/python3
import socket

fd = open('ebin.enc', 'rb')
data = fd.read()

TCP_IP = '127.0.0.1'
TCP_PORT = 6666
BUFFER = 126

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
s.send(data)
s.shutdown(socket.SHUT_WR)
reply = s.recv(BUFFER)
s.close()

print(str(reply))
