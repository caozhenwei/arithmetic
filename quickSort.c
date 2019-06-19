//快速排序
//

#include <stdio.h>

void quickSort(int s[],int start,int end) {
    int i,j,standard;

    //左边游标
    i = start;
    //右边游标
    j = end;

    //选择基准
    standard = s[start];
    
    while(i < j) {
        //从右往左找比基准小的数，交换到s[i]上，同时左边游标右移
        while(i < j && standard < s[j]) {
            j--;
        }
        if(i < j) {
            s[i] = s[j];
            i++;
        }
        
        //从左往右找比基准小的数，交换到s[j移动
        while(i < j && standard >= s[i]) {
            i++;
        }  
        if(i < j) {
            s[j] = s[i];
            j--;
        }   
    }  

    //把基准放到s[i]
    s[i] = standard;
    //此时基准左边都是比基准小的数，基准右边都是比基准大的数
    //用递归调用分别在排基准两边的数组
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
