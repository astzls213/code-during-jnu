import functools, time

def log(text):
	def decorator(func):
		@functools.wraps(func)
		def wrapper(*args,**kw):
			print('%s %s():' % (text, func.__name__))
			return func(*args,**kw)
		return wrapper
	return decorator

@log('execute')
def now():
	print('2019-10-31')

log('nmsl')(now)()
print('%s'%now.__name__)

def metric(fn):
	@functools.wraps(fn)
	def nmsl(*args,**kw):
		print('%s executed in %s ms' % (fn.__name__,10.24))
		return fn(*args, **kw)
	return nmsl

@metric
def fast(x,y):
	time.sleep(0.0012)
	return x + y

@metric
def slow(x,y,z):
	time.sleep(0.1234)
	return x*y*z

f=fast(11,22)
s=slow(11,22,33)
if f != 33:
	print('gg')
elif s != 7986:
	print('fuck')