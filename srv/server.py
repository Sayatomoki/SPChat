import socket
import threading
import MySQLdb
import time

userList = []

class account(object):
    def __init__(self, sock, userId, userPwd, to = None, msg = None):
        self.sock = sock
        self.userId = userId
        self.userPwd = userPwd
        self.to = to # to username
        self.msg = msg

    def sendMsg(self):
        userList[userList.index(self.to)].sock.send(self.msg)

    def login(self):
	print 'login called'
        db = MySQLdb.connect('localhost', 'spcAdmin', '123456', 'spcDB')
        cursor = db.cursor()
        sql = "SELECT * FROM USERTBL WHERE userId == '%s' AND userPwd == '%s'" % self.userId, userPwd
        try:
            cursor.execute(sql)
            userList.append(self)
            flag = 0
        except:
            flag = -1
        db.close()
        if flag == 0:
            return True
        elif flag == -1:
            return False

    def logout(self):
        if self in userList:
            userList.pop(userList.index(self))
        self.sock.close()

    def signUp(self):
	print 'signUp called'
        localtime = time.asctime(time.localtime(time.time()))
        db = MySQLdb.connect('localhost', 'spcAdmin', '123456', 'spcDB')
        cursor = db.cursor()
        sql = "INSERT INTO USERTBL(userId, userPwd, signTime) VALUES ('%s', '%s', '%s')" % self.userId, self.userPwd, localtime
        try:
            cursor.execute(sql)
            db.commit()
            flag = 0
        except:
            db.rollback()
            flag = -1
        db.close()
        if flag == 0:
            return True
        elif flag == -1:
            return False

class threadSocket(object):
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.sock.bind((self.host, self.port))

    def listen(self):
        self.sock.listen(5)
        print 'service start!'
        while True:
            cli, addr = self.sock.accept()
            print 'conneted by ' + str(addr)
            cli.settimeout(60)
            threading.Thread(target = self.handleClientRequest, args = (cli, addr)).start()

    def handleClientRequest(self, cli, addr):
        while True:
            try:
                h = cli.recv(1024)
		print h
		buf = json.loads(h)
		print buf
                if buf:
                    header = buf['header']
                    del buf['header']
                    user = dict2account(buf)
                    eval('user.%s()' % header)
                else:
                    raise error('Client has disconneted.')
            except:
                cli.close()

if __name__ == '__main__':
    server = threadSocket('127.0.0.1', 9000)
    server.listen()
