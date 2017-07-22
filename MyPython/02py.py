#!/usr/bin/env python3
from urllib.request import urlopen
for line in urlopen('http://www.subond.com'):
    line = line.decode('utf-8')  # Decoding the binary data to text.
    print(line)
