#include<dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void usage();

int main(int argc,char *argv[]){
	if(argc < 2){ //too few arguments
		usage();
		exit(0);
	}
	int buf=0;
	bool flag=false;// judge hexadecimal or not.
	int offset=0;

	if(strcmp(argv[1],"-h") == 0){
		flag = true;
		offset = 2;
	}
	else{
		offset = 1;
	}
	//init files.
	FILE **files=(FILE **)calloc(argc - offset, sizeof(FILE *));
	for(int i = offset;i < argc;i++){
		files[i - offset] = fopen(argv[i],"r");
		if(files[i - offset] == NULL)
		{
			printf("Error while opening file %s",argv[i]);
			exit(1);
		}
	}
	//output to screen.
	for(int i = 0;i < argc - offset;i++){
		printf("%s:\n",argv[i+offset]);
		while(1){
			buf = fgetc(files[i]);
			if(buf == -1)
				break;
			if(flag)
				printf("%x",buf);
			else
				printf("%c",buf);
		}
		putchar('\n');
		putchar('\n');
		fclose(files[i]);
		files[i] = NULL;
	}
	return 0;
}
void usage(){
	puts("Usage:");
	printf(" mycat [-h] [file ...]\n");
	printf("Option:\n");
	printf(" -h		print text in hexadecimal.\n");
}