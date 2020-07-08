import filecmp as fc
import os
import shutil as ut
def auto_backup(src,goal):
	for obj in os.listdir(src):
		srcObj = os.path.join(src,obj)
		goalObj = srcObj.replace(src,goal,1)
		if os.path.isdir(srcObj):
			if not os.path.exists(goalObj):
				os.mkdir(goalObj)
			auto_backup(srcObj,goalObj)
		elif os.path.isfile(srcObj):
			if (not os.path.exists(goalObj)) or (not fc.cmp(srcObj,goalObj,
				shallow=False)):
				ut.copyfile(srcObj,goalObj)

src=r'/Users/astzls/Desktop/pyCode'
goal=r'/Users/astzls/Desktop/dst'
auto_backup(src,goal)