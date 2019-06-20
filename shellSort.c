//
//  希尔排序
//
//  思想：把数据分组后再使用插入排序
//
//  2019.6.20 czw
//

#include <stdio.h>

void shellSort(int a[], int n) {
    int gap,tmp;
    for(gap = n/2; gap > 0; gap = gap/2) {
        for(int i = gap; i < n; i++) {
            int j = i;
            while(j - gap > 0 && a[j] < a[j-gap]) {
                tmp = a[j];
                a[j] = a[j-gap];
                a[j-gap] = tmp;  
                j = j - gap; 
            }
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
