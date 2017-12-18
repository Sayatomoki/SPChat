import socket
import sys
sys.path.append('../lib/')
import spcLib
import MySQLdb

# define host and port

HOST = 'localhost'
PORT = 10010

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(5)

print 'Server start at: %s:%s' % (HOST, PORT)
print 'wait for connection...'

# jud signIn or signUp
while True:
	conn, addr = s.accept()
	sType = conn.recv(1024)
	if sType == 'signIn':
		


# while True:
# 	conn, addr = s.accept()
# 	print 'Connected by ', addr

# 	while True:
# 		buf = conn.recv(1024)
# 		print buf

# 		conn.send("Server received you message.")

s.close()