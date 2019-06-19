//选择排序
//
#include <stdio.h>

void selectSort(int s[],int n) {
    int i,j,tmp;
    for(i = 0; i < n-1; i++) {
        int max = 0;
        for(j = 0; j < n-i; j++) {
            if(s[j] > s[max]) {
                max = j;
            }
        }
        tmp = s[max];
        s[max] = s[n-i-1];
        s[n-i-1] = tmp;
    }
}

int main() {
    
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

    selectSort(a,n);

    printf("排序后的数据为：\n");
    for(i = 0; i < n; i++) {
        printf("%d,",a[i]);
    }    
    printf("\n");


    return 0;
}
