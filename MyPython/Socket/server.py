#!/usr/bin/env python3

import sys
import socket

host = socket.gethostname()
port = 9999
serverfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverfd.bind((host, port))
serverfd.listen(5)
while True:
    clientfd, addr = serverfd.accept()
    print("The Client IP is: %s" %str(addr))
    msg = '欢迎访问www.subond.com' + "\r\n"
    clientfd.send(msg.encode('utf-8'))
    clientfd.close()
