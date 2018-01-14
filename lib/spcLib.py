import json
import socket

# class jsob

class account(object):
    def __init__(self, sock, userId, userPwd, to = NULL, msg = NULL):
        self.sock = sock
        self.userId = userId
        self.userPwd = userPwd
        self.to = to
        self.msg = msg
        
    def ac2dict(self):
        return self.__dict__

# the numbers of error more than 3

def numErrMrThTr():
	print 'the count of error more 3!'
	exit()

# sign into server

def signIn(HOST, PORT):
	user_id = raw_input('please enter your name: ')
	user_pwd = raw_input('please enter your password: ')
	usr = account(user_id, user_pwd)
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((HOST, PORT))
	s.send(usr.ac2json())
	buf = s.recv(1024)
	s.close()
	if buf == "1":
		print "sign in successed."
		return True
	else:
		print "failed to sign in."
		return False

# sign up a new account to server

def signUp(HOST, PORT):
	user_id = raw_input('please enter your name: ')
	user_pwd = raw_input('please enter your password: ')
	user_rpwd = raw_input('please confirm your password: ')
	nUsr = account(user_id, user_pwd)
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((HOST, PORT))
	s.send('signUp')
	s.send(nUsr.ac2json())
	buf = s.recv(1024)
	s.close()
	if buf == "1":
		print "sign up successed."
		return True
	else:
		print "failed to sign up."
		return False

# dict to account

def dict2Ac(a):
	return account(a['user_id'], a['user_pwd'])

# json to account class

def json2Ac(str1):
	return json.loads(str1, object_hook = dict2Ac)
