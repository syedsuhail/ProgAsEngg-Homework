#!/usr/bin/python

import time

bitlist=[]
number=input()
for i in range(2,number):
	bitlist.append([i,0])


for i in bitlist:
	j=2	
	while True :	
		k=(i[0]*j) -2	
		if k >= len(bitlist):
			break		
		bitlist[k][1]=1
		
		j+=1
for i in bitlist:
	if i[1]==0:
		print i[0]
		
print time.clock()
	

