# TCP Server Code
 
host="0.0.0.0"                # Set the server address to variable host
port=4446                   # Sets the variable port to 4446
from socket import *                # Imports socket module
 
 
                # Binds the socket. Note that the input to
                                            # the bind function is a tuple
s=socket(AF_INET, SOCK_STREAM)
s.bind((host,port)) 
s.listen(1)                         # Sets socket to listening state with a  queue
while True:
	print "Listening for connections.. "
	q,addr=s.accept()               # Accepts incoming request from client and returns
	                                            # socket and address to variables q and addr

	def get_bytes_from_file(filename):  
	    return open(filename, "rb").read()  

	data = get_bytes_from_file('/home/groot.wav')

	#data=raw_input("Enter data to be send:  ")  # Data to be send is stored in variable data from
	                                            # user
	 
	q.send(data)                        # Sends data to client
	q.close() 
s.close()
 
# End of code
