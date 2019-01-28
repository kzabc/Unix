//
// Created by zkay on 2019/1/26.
//
#include "apue.h"
#include <dirent.h>
DIR *dp;
struct dirent *dirp;
void getDir(char *dir){
    if((dp = opendir(dir)) == NULL){
        err_quit("usage : myls dir_name");
    }else{
        while ((dirp =readdir(dp)) !=  NULL){
            printf("%s\n",dirp->d_name);
        }

    }
    closedir(dp);
}
int main(int argc, char *argv[]){
    printf("参数数量：%d，参数指针开始位置%p\n",argc,&argv);
//    int ch;
//    opterr=0;
//    while((ch=getopt(argc,argv,":a::b::c::"))!=-1) {
//        printf("optind: %d,argc:%d,argv[%d]:%s\n", optind,argc,optind,argv[optind]);
//        switch(ch) {
//            case 'a':
//                printf("option a:%s\n", optarg);
//                break;
//            case 'b':
//                printf("option b:%s\n", optarg);
//                break;
//            case 'c':
//                printf("option c\n");
//                break;
//            case 'd':
//                printf("option d\n");
//                break;
//            case 'e':
//                printf("option e\n");
//                break;
//            case ':': //缺少选项
//                printf("缺少选项参数\r\n");
//                break;
//
//            default:
//                printf("Knowed option:%s\n", optarg);
//                break;
//        }
//        printf("optopt+%c\n",ch);
//
//    }
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

