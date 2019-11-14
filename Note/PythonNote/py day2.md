# py day2

### Java vs Python: 多态区别

对于Java来说，一个函数如果需要传入`Animal`类型，则传入的对象必须是`Animal`类型或者它的子类，否则，将无法调用`run()`方法。

即：一定是`Animal`及其子类的`run()`方法才认可，其他类的`run()`方法不认可。

对于Python来说，则不一定需要传入`Animal`类型。我们只需要保证**传入的对象有一个`run()`方法**就可以了。

### 动态添加域for instance

这就是python，这就是动态语言的灵活与强大之处。

无需在类里声明变量，可以直接

```python
class Human(object):
  pass

h1=Human() #instance created.
h1.name='zhen luosheng' #domain of name added.
setattr(h1,'age',19) #domain of age added as 19.
```

### os, filecmp, shutil三大IO模块



### `__slots__`/`@property`简化程序

每个声明的类都可以使用`__slot__`限制类的属性。

例如：

```python
class Dog(Animal):
	__slots__=('name','age')
  #>>>myDog=Dog()
  #>>>myDog.dick=15  <- It's just attribute error.
```

现在，Dog类的实例只能绑定`name`,`age`这两个属性。若绑定其他属性则报错。



