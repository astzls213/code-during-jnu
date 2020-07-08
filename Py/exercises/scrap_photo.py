from urllib.request import urlopen,urlretrieve
from bs4 import BeautifulSoup

html=urlopen('https://astzls213.github.io/')
bs=BeautifulSoup(html,'html.parser')


imageLocation=bs.find_all('img')['src']
#urlretrieve(imageLocation,'logo.jpg')