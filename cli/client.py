import socket

class account(object):
	"""docstring for account"""
	def __init__(self, arg):
		super(account, self).__init__()
		self.arg = arg


# the numbers of error more than 3

def numErrMrThTr():
	print 'the count of error more 3!'
	exit()

# sign up a new account to server

def signUp():
	for i in range(3):
		user_id = raw_input('please enter your name: ')
		user_pwd = raw_input('please enter your password: ')
		user_rpwd = raw_input('please confirm your password: ')

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
		print 'patermeter error! try again.'
		continue

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))



while True:
	c = raw_input("Please input message:")
	s.send(c)
	buf = s.recv(1024)
	print buf

s.close()