//base
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//directory controler.
#include <dirent.h>

#include <unistd.h>
#include <sys/stat.h> // check file status.

//uid to name && gid to name is their usage.
#include <pwd.h>
#include <grp.h>

//时间转换
#include <time.h>

#define CWD "." //Current working directory.

#define NUMS_OPTION 1 //选项数量
#define l 0 //用于选项数组下标
//以下用于识别文件属性时
#define MK_U 0000700
#define MK_G 0000070
#define MK_O 0000007

char *get_prot(mode_t mode);

int main(int argc,char *argv[]){

	bool option[NUMS_OPTION] = {false}; //
	int offset; //第一个文件参数的位置
	DIR **dir_p = NULL; //文件夹or文件参数
	int num_dirs = 0; //文件夹和文件参数数量
	int count = 0; //计文件夹下的项目个数

	//这里，是找出第一个文件夹或文件参数
	for(offset = 1;offset < argc && argv[offset][0] == '-';offset++){
		; //continue searching..
	}
	//init options
	for(int i = 1;i < offset;i++){
		if (argv[i][1] == 'l')
			option[l] = true;
	}

	//init directories
	if(argc == offset){ //which means no specified files.
		num_dirs = 1;
		dir_p = (DIR **)calloc(num_dirs,sizeof(DIR *));
		dir_p[0] = opendir(CWD); //Current working directory.
	}
	else{
		num_dirs = argc - offset;
		dir_p = (DIR **)calloc(num_dirs,sizeof(DIR *));
		for(int i = offset;i < argc;i++){
			dir_p[i - offset] = opendir(argv[i]);
			if (!dir_p[i - offset])
				printf("Can not open \"%s\"\n",argv[i]);
		}
	}

	for(int i = 0;i < num_dirs;i++){
		struct dirent *info = NULL;
		struct stat status; //file's or directory's status.
		struct tm *ptr = NULL;
		char *protection = NULL; //文件属性
		count = 0; //计数器清零

		//dir_p[i] is NULL, which means no such directory.
		if (!dir_p[i])
			break;
		if (argc == offset){
			//change working directory.
			if(chdir(".") == -1)
			{
				printf("Can not access current working directory!\n");
				break;
			}
			//print directory's name.
			printf("cwd:\n");
		}
		else{
			//change working directory.
			if(chdir(argv[i+offset]) == -1)
			{
				printf("Can not access %s!\n",argv[i+offset]);
				break;
			}
			//print directory's name.
			printf("%s:\n",argv[i+offset]);
		}

		//output to screen for each object.
		while((info = readdir(dir_p[i])) != NULL){
			//不打印以.开始的文件，这一功能暂不开放。
			if (info->d_name[0] == '.')
				continue;
			else if (strcmp(info->d_name,"..") == 0)
				continue;
			else if(option[l] == true)
			{
				stat(info->d_name,&status);
				//preprocessing for print.
				ptr = gmtime(&status.st_ctime);
				protection = get_prot(status.st_mode);
				//output
				printf("%s %2d %5s %5s %5lld %2d %2d %4d %-10s\n",
					protection,
					status.st_nlink,
					getpwuid(status.st_uid)->pw_name,
					getgrgid(status.st_gid)->gr_name,
					status.st_size,
					ptr->tm_mon,
					ptr->tm_mday,
					1900 + ptr->tm_year,
					info->d_name
					);
			}
			else
			{
				printf("%s\n",info->d_name);
			}
			count++;//成功遍历一个文件
		}
		printf("Total %d items\n",count);
	}
	return 0;
}

char *get_prot(mode_t mode){
	char prot[8][4] = {"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};
	char *rtv = (char *)calloc(11,sizeof(char));

	mode_t prot_u = (mode & MK_U) >> 6;
	mode_t prot_g = (mode & MK_G) >> 3;
	mode_t prot_o =  mode & MK_O;
	
	if (S_ISLNK(mode))
		strcat(rtv,"l");
	else if (S_ISREG(mode))
		strcat(rtv,"-");
	else if (S_ISBLK(mode))
		strcat(rtv,"b");
	else if (S_ISCHR(mode))
		strcat(rtv,"c");
	else if (S_ISSOCK(mode))
		strcat(rtv,"s");
	else if (S_ISFIFO(mode))
		strcat(rtv,"p");
	else if (S_ISDIR(mode))
		strcat(rtv,"d");

	strcat(rtv,prot[prot_u]);
	strcat(rtv,prot[prot_g]);
	strcat(rtv,prot[prot_o]);
	return rtv;
}