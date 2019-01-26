//
// Created by zkay on 2019/1/26.
//
#include "apue.h"
#include <dirent.h>
DIR *dp;
struct dirent *dirp;
void getDir(char *dir){
    err_quit("usage : myls dir_name");
    if((dp = opendir(dir)) == NULL){
        err_quit("usage : myls dir_name");
    }else{
        while ((dirp =readdir(dp)) !=  NULL){
            printf("%s\n",dirp->d_name);
        }

    }
}
int main(int argc, char *argv[]){
    printf("参数数量：%d，参数指针开始位置%p\n",argc,&argv);
    char *buf = NULL;
    switch (argc){
        case 1 :
            buf = getcwd(buf,0);
            getDir(buf);
            free(buf);
            break;
        case 2 :
            getDir(argv[1]);
        default:
            //预留多参数处理
            break;
    }
    return 0;
}

