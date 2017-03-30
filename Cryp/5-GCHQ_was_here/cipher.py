#!/usr/bin/python
import sys

def modPow(val, b):
    power = 1
    n = 16765589
    while(b != 0):
        if(b % 2 == 1):
            power = (power * val) % n
        val = (val * val) % n
        b = b // 2
    return power

def encrypt(message):
    toRet = b''
    if (len(message) % 2 == 1):
        message += b'\x00'
    for x in range(0, len(message), 2):
        val = message[x]*256 + message[x+1]
        temp = modPow(val, 65537)
        toRet += bytearray([(temp & 16711680) >> 16])
        toRet += bytearray([(temp & 65280) >> 8])
        toRet += bytearray([(temp & 255)])
    return toRet

def decrypt(message):
    toRet = b''
    for x in range(0, len(message), 3):
        val = message[x]*65536 + message[x+1]*256 + message[x+2]
        temp= modPow(val, 2070593)
        toRet += bytearray([(temp & 65280) >> 8])
        toRet += bytearray([(temp & 255)])
    return toRet

f = open(sys.argv[1], 'rb')
g = open('output.enc', 'wb')

data = f.read()
en_data = encrypt(data)

testimg = open('test.jpg', 'wb')
testimg.write(decrypt(en_data))
testimg.close()

g.write(en_data)
f.close()
g.close()
