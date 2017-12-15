import socket

HOST = 'mmpnet.club'
PORT = 10010

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

while True:
	c = raw_input("Please input message:")
	s.send(c)
	buf = s.recv(1024)
	print buf

s.close()