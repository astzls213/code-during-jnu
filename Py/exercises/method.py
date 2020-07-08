class a:
	age=18

	def __init__(self,age):
		self.age=age

	def nm(self):
		print('Normal method')

	@classmethod
	def cm(self):
		print('classmethod',self.age)

	@staticmethod
	def sm():
		print('Staicmethod')

if __name__ == '__main__':
	#test=a(18)

	#test.nm()
	#test.cm()
	#test.sm()
	print(a.nm)
	a.cm()
