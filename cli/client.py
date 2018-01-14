class account(object):
    def __init__(self, sock, userId, userPwd, to = NULL, msg = NULL):
        self.sock = sock
        self.userId = userId
        self.userPwd = userPwd
        self.to = to
        self.msg = msg
        
    def ac2dict(self):
        return self.__dict__