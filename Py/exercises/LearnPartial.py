#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'sdasda'

__author__ = 'astzls213'

from functools import partial
def func(a,b):
	print(a,b)


func2=partial(func,10,2)
func2()