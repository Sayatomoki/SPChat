
import socket
import json
import sys
sys.path.append('../lib/')
import spcLib

# link to the point out server

for i in range(3):
	try:
		HOST = raw_input('please enter domain name or IP address: ')
		PORT = int(raw_input('please enter port: '))
		if (isinstance(HOST, str) and isinstance(PORT, int)):
			break;
	except ValueError:
		if i == 2:
			numErrMrThTr()
		else:
			print 'format error! try again.'
			continue
	else:
		print 'format error! try again.'
		continue

# sign in or sign up an account

for i in range(3):
	try:
		flag = int(raw_input('if you have an account, please input 1 to sign in, or input 0 to sign up: '))
	except ValueError:
		if i == 2:
			numErrMrThTr()
		else:
			print 'patermeter error! try again.'
			continue
	else:
		if flag == 1:
			if spcLib.signIn():
				break
			else:
				continue
		else:
			if spcLib.signUp():
				break
			else:
				continue

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

for i in range(3):



while True:
	c = raw_input("Please input message:")
	s.send(c)
	buf = s.recv(1024)
	print buf

s.close()