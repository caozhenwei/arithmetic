//冒泡排序
#include <stdio.h>

int main(){
    int n;
    printf("请输入想要排序的个数:\n");
    scanf("%d",&n);
    printf("请依次输入%d个数\n",n);

    int a[n],i;
    for(i = 0; i < n ; i++) {
        scanf("%d",&a[i]);
    }
    
    printf("排序前的数据为：\n");
    for(i = 0; i < n; i++) {
        printf("%d,",a[i]);
    }    
    printf("\n");

    //冒泡排序
    int j,tmp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 -i; j++ ) {
             if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
             }
        }
    }

    printf("排序后的数据为：\n");
    for(i = 0; i < n; i++) {
        printf("%d,",a[i]);
    }
    printf("\n");
    return 0;
}
