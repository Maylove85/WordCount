#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main (int argc,char *argv[])
{
	char str; 
    int count=0;
    FILE *s;
    if (argc != 3){
        printf("��ʽ����");
        exit(1);    
    } 
    if ((s = fopen(argv[2],"r")) == EOF){  
        printf("�ļ���ʧ��");
        exit(1);
    }
    if (strcmp(argv[1], "-c") == 0) {
        while((str = getc(s)) != EOF) { 
            count++;
        }
        printf("�ַ�����%d��\n", count);
    } else if(strcmp(argv[1], "-w") == 0) {
        while((str = getc(s)) != EOF) {
            if ((str == ' ') || (str == ',')) 
			count++;
        }
        printf("��������%d��\n", count);
    }else{
    	printf("��ʹ��-s����-wͳ���ļ�����");
	}
    fclose(s);
    return 0;
}

