from socket import *

serverIp='192.168.0.105'
severPort=12000

clientSocket=socket(AF_INET,SOCK_DGRAM)

msg=input('Upper your text, try:')

clientSocket.sendto(msg.encode(),(serverIp,severPort))

modifiedMessage , addr = clientSocket.recvfrom(2048)

print(modifiedMessage.decode())

clientSocket.close()