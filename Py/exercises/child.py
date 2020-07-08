from urllib.request import urlopen
from bs4 import BeautifulSoup
import re

html=urlopen('http://www.pythonscraping.com/pages/page3.html')
bs=BeautifulSoup(html,'html.parser')

url=geturl(html)
print('url')
#for child in bs.find('table',{'id':'giftList'}).tr:
	#print(child)

#print(bs.find('img',{'src':'../img/gifts/img1.jpg'}).parent.previous_sibling.get_text())
#n=bs.find('table',{'id':'giftList'}).next_sibling
#print(n)
#images=bs.find_all('img',{'src':re.compile('\.\.\/img\/gifts\/img.*\.jpg')})
#for image in images:
#	print(image['src'])

#n=bs.find_all(lambda tag:tag.get_text()=='Or maybe he\'s only resting?')
#print(n)