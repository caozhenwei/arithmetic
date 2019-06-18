//快速排序
//

#include <stdio.h>

void quickSort(int s[],int start,int end) {
    int i,j,standard;
    i = start;
    j = end;
    standard = s[start];
    while(i < j) {
        while(i < j && standard < s[j]) {
            j--;
        }
        if(i < j) {
            s[i] = s[j];
            i++;
        }
        
        while(i < j && standard >= s[i]) {
            i++;
        }  
        if(i < j) {
            s[j] = s[i];
            j--;
        }   
    }  

    s[i] = standard;
    if(start < i) {
        quickSort(s,start,j-1);
    }
    if(i < end) {
        quickSort(s,j+1,end);
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

    quickSort(a,0,n-1);

    printf("排序后的数据为：\n");
    for(i = 0; i < n; i++) {
        printf("%d,",a[i]);
    }    
    printf("\n");

    return 0;
}
