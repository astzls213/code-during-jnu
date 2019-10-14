# py day1

### 对list的sort操作：

1.首先对list类调用`sort()`函数。`sort(key, reverse`)有三个可选参数，分别是key，reverse。它们的默认值分别是None，False

2.`sort(key, reverse)`会根据两个参数的值进行特定的sort。

3.`sort()`没有返回值。（`sorted()`有返回值，返回值是排序好的对象）

#### 	key参数：

​		这个参数是告诉sort()函数，以list中的每个元素的特定值进行排序。举个例子好了：

​		现有list对象x = [(1, 2), (2, 1), (3, -1), (-1, 5)], 对它进行x.sort(key=lambda e:e[1])操作。

​		那么结果就是[(3, -1), (2, 1), (1, 2), (-1, 5)]；注意到，x中的**每个tuple元素**的**第二个元素**在x中是按**由小到大**排序的。

​		原因在于key参数的值为一个lambda表达式。这个lambda表达式返回的是e[1], 参数是e；这意味着什么呢？

​		我们了解到，lambda的返回值是一个函数的地址。即key所接受的参数是一个**函数地址**！所以，当sort()函数work时，我先假设它的内部实现是bubble排序（显然不是，sort()实际上是由一种timsort的方法进行排序，即merge+binary insert的hybird），那么对list对元素进行迭代，在Iteration中，先将该元素作为key的参数传入，再根据相应的返回值进行由小到大的排序（key已经是某个函数的地址，故可调用）。

​		因此，我们现在对key参数对认识就很明了了。key要接收的是一个函数地址。而该函数地址所指向的函数，必须有且仅有一个参数，且返回一个有意义的值，以便用于正确理性的排序。

​		即：上面的lambda表达式实际上可以代换成：

```python
def getSecond(x):
	return x[1]

x.sort(key=getSecond) #same as key = lambda e:e[1]
print(x)
```

#### 	reverse参数：

​		该参数所接收的类型为bool值，即true of false。默认值为false，即由小到大排序。若为true，则进行反转，即降序排列。



### 定义方程时的默认参数必须是不可变的：

这个十分重要，若把默认参数设置为可变的，出大问题！！！举个例子：

```python
def nmsl(a,L=[]):
     L.append(a)
     return L
    
#when you execute it like: nmsl(1) nmsl(2)
#it will appear:[1] [1,2]
#your previous call effects subsquent calls.

#you shuold define like that:
def nmsl(a,L=None):
     if L==None:
            L=[]
    	L.append(a)
    	return L
#None is a unmodifiable literal.
#Like above calls, and it turns -> [1] [2]
```

#### 注解：

​		你可能觉得，为什么第二次def后的方程，随后的调用，均不影响其后的调用。

原因是这样的：

​		我们可以将每一次函数调用想象成这样：

![屏幕快照 2019-10-13 下午4.16.12](/Users/astzls/Desktop/屏幕快照 2019-10-13 下午4.16.12.png)

意思是，每一次函数调用，都是一个新的procedure。而且每次都指向该函数的变量表。

如果是第一个def的函数，那么结果将是：

![屏幕快照 2019-10-13 下午4.21.09](/Users/astzls/Desktop/屏幕快照 2019-10-13 下午4.21.09.png)

意思是，第一个`nmsl(1)`调用后，由于`L.append(1)`，函数的变量表中的`L`的值变成`[1]`（因为L是一个list类对象）。这直接导致下一次的`nmsl(2)`调用后，返回了`[1, 2]`。



#### 	