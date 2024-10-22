# JUMMY WAS HERE
# extract table_blupi from speedy blupi 2.2 english ver

import sys
import io

offset = 0x34e60
out = []

with io.open('BLUPI.exe', 'rb') as f:
	data = f.read()
	for i in range(2842):
		out.append (int.from_bytes(data[offset + i * 4 : offset + i * 4 + 4], byteorder='little', signed=True))
with io.open('out.h', 'wb') as f2:
	f2.write(bytearray(', '.join(map(str,out)), 'ascii'))
