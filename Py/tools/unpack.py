import shutil
import os

'''
	
'''
sourcePath='/Users/astzls/Downloads'
fileList = os.listdir(sourcePath)

unpackList = [file for file in fileList if file.endswith('.tgz')]

for file in unpackList:
	#for each file create a file to store object when unpacking
	fileName, ext = os.path.splitext(file)
	absPath='/Users/astzls/Desktop/pyCode/examples/'+fileName
	os.mkdir(absPath)
	#unpacking...
	shutil.unpack_archive(sourcePath+'/'+file,extract_dir=absPath)

print('Succeed for unpacking %d files' % len(unpackList))