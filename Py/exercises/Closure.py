def counter():
	i=0
	def add():
		nonlocal i
		i=i+1
		return i
	return add

countA=counter()
print(countA(),countA(),countA(),countA(),countA())
conutB=counter()
print([conutB(),conutB(),conutB(),conutB()])