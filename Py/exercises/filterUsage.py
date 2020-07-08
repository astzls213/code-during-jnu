def is_palidrome(n):
	tmp=str(n)
	return tmp==tmp[::-1]

output=list(filter(is_palidrome,range(1,1000)))
print(output)