from functools import reduce

def normalize(name):
	return name[0].upper()+name[1:].lower()

L1=['adam','LISA','Zls']
L2=list(map(normalize,L1))
print(L2)

def prod(L):
	ans=reduce(lambda x,y:x*y,L)
	return ans

print(prod([x for x in range(10) if x%2==1]))

def str2float(s):
	L=s.split('.')
	if len(L)!=2:
		print('Not a decimal!')
		return None
	else:
		return reduce(lambda x,y:x*10+y,list(map(int,L[0])))+(reduce(
			lambda x,y:x*10+y,list(map(int,L[1])))/10**len(L[1]))

print(str2float('123.456'))
if abs(str2float('123.456') - 123.456)<0.001:
	print('Accept!')