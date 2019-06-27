//
//  希尔排序
//
//  思想：把数据分组后再使用插入排序
//
//  2019.6.20 czw
//

#include <stdio.h>

void shellSort(int a[], int n) {
    int gap,tmp,i,j;
    for(gap = n/2; gap > 0; gap = gap/2) {
        for(i = gap; i < n; i++) {
            tmp = a[i];
            //在直接插入排序里面这里是 j = i - 1
            j = i - gap;
            while(tmp < a[j] && j >= 0) {
                //在直接插入排序里面这里是 a[j+1] = a[j]
                a[j+gap] = a[j];
                j = j - gap; 
            }
            //在直接插入排序里面这里是 a[j+1] = tmp;
            a[j+gap] = tmp;
        }
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

    shellSort(a,n);

    printf("排序后的数据为：\n");
    for(i = 0; i < n; i++) {
        printf("%d,",a[i]);
    }    
    printf("\n");
   
    return 0;
}
