#导入tkinter
from tkinter import *
#定义的方法 监听键盘事件
def printkey(event):
    print('你按下了: ' + event.char)
#实例化tk
if __name__=='__main__':
	root = Tk()
	#实例化一个输入框
	entry = Entry(root)
	#给输入框绑定按键监听事件<Key>为监听任何按键 <Key-x>监听其它键盘，如大写的A<Key-A>、回车<Key-Return>
	entry.bind('<Key>', printkey)
	#显示窗体
	entry.pack()
	root.mainloop()