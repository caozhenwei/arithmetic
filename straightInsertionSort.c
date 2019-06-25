//
//  直接插入排序
//
//  思想：假设第一位为排好的数组，从数组中的第二位开始，
//      找到合适的位置并直接插入之前排好序的数组中
//
//  2019.6.20 czw
//

#include <stdio.h>

//
//  功能：直接插入排序
//  参数：
//      a，待排序的数据
//      n，数组的个数
//
void straightInsertionSort(int a[],int n) {
   // for(int i = 1; i <= n; i++) {
   //     int j = i - 1;
   //     int tmp = 0;
   //     while(j > 0) {
   //         if(a[j] >= a[j-1]) {
   //            break; 
   //         }

   //         if(a[j] < a[j-1] ) {
   //             tmp = a[j];
   //             a[j] = a[j-1];
   //             a[j-1] = tmp;
   //         }
   //         j--;
   //     }
   // }    
  
   int tmp; 
    for(int i = 1; i <= n; i++) {
        for (int j = i-1; j > 0; j--) {
            if(a[j] >= a[j-1]) {
                break;
            }
            if(a[j] < a[j-1]) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] =tmp;
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

    straightInsertionSort(a,n);

    printf("排序后的数据为：\n");
    for(i = 0; i < n; i++) {
        printf("%d,",a[i]);
    }    
    printf("\n");
}
