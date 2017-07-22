#!/usr/bin/env python3

import sys,socket

host = socket.gethostname()
port = 9999
fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
fd.connect((host, port))

msg = fd.recv(1024)
fd.close()

print(msg.decode('utf-8'))
