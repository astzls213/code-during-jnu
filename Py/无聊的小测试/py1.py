def tri(max):
	p=1
	n=0
	while n<max:
		yield p
		p=p*2
		n+=1


g=tri(10)
x=[]
while True:
	try:
		x=x+[next(g)]
		print(x)
	except StopIteration as e:
		print(e.value)
		break