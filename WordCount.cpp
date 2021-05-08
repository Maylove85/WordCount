#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main (int argc,char *argv[])
{
	char str; 
    int count=0;
    FILE *s;
    if (argc != 3){
        printf("格式错误");
        exit(1);    
    } 
    if ((s = fopen(argv[2],"r")) == EOF){  
        printf("文件打开失败");
        exit(1);
    }
    if (strcmp(argv[1], "-c") == 0) {
        while((str = getc(s)) != EOF) { 
            count++;
        }
        printf("字符数：%d个\n", count);
    } else if(strcmp(argv[1], "-w") == 0) {
        while((str = getc(s)) != EOF) {
            if ((str == ' ') || (str == ',')) 
			count++;
        }
        printf("单词数：%d个\n", count);
    }else{
    	printf("请使用-s或者-w统计文件字数");
	}
    fclose(s);
    return 0;
}

