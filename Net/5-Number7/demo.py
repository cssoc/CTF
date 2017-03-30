#!/usr/bin/python3

import socket
import os


fd = open('secret.enc', 'rb')

size = os.path.getsize('secret.enc')

blocks = size // 16
blocks -= 1
realBlocks = blocks - 1

origBuffer = [None] * blocks
blockBuffer = [None] * blocks
guessBuffer = [None] * blocks

for i in range(blocks):
    origBuffer[i] = fd.read(16)
    blockBuffer[i] = origBuffer[i][:]
    guessBuffer[i] = origBuffer[i][:]

def checkCorrect(cBuffer):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    data = bytearray().join(cBuffer)
    sock.connect(('127.0.0.1', 6666))
    sock.send(data)
    sock.shutdown(socket.SHUT_WR)
    a = sock.recv(2)
    if(a  == b'\x00\x00'):
        sock.close()
        return True
    else:
        sock.close()
        return False

decrypted = [None] * (blocks -1)
while(blocks > 1):
    rightGuess = bytearray([0]*16)
    currentGuess = bytearray([0]*16)
    paddingNumber = 1
    for byteToGuess in range(16):
        currentGuess[:- paddingNumber] = blockBuffer[blocks - 2][:- paddingNumber]
        for solvedByte in range(byteToGuess):
            currentGuess[-solvedByte - 1] = paddingNumber ^ blockBuffer[blocks - 2][-solvedByte - 1] ^ rightGuess[-solvedByte - 1]
        for guess in range(256):
            currentGuess[-paddingNumber] = paddingNumber ^ blockBuffer[blocks - 2][-paddingNumber] ^ guess 
            guessBuffer[blocks - 2] = currentGuess
            if(checkCorrect(guessBuffer)):
                print("success")
                rightGuess[-paddingNumber] = guess
                paddingNumber += 1
                break
    print(realBlocks)
    decrypted[realBlocks - 1] = rightGuess
    print(rightGuess)
    realBlocks -= 1
    blocks -= 1
#    fd = open('secret.enc', 'rb')
#    for i in range(blocks):
#        blockBuffer[i] = fd.read(16)
#
#    fd.close()

    origBuffer = origBuffer[:-1]

    blockBuffer = origBuffer[:]
    guessBuffer = origBuffer[:]

f = open("decrypted.txt", 'wb')
f.write(bytearray().join(decrypted))
