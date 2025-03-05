#include <stdlib.h>
#include <stdio.h>

int count_range_len(int start, int end){
    int len = 0;
    if(start <= end){
        while(start <= end){
            len++;
            start++;
        }
    }
    return len;
}

int *ft_range(int start, int end){
    int *nums;
    int len;

    if(start > end)
        return 0;

    len = count_range_len(start, end);
    nums = (int *)malloc(len * sizeof(int));
    if(!nums) return 0;

    int i = 0;
    while(i < len){
        nums[i] = start;
        start++;
        i++;
    }

    return nums;
}

int main(){
    int *arrayInt = ft_range(1, 4);
    int i = 0;
    while (i < count_range_len(1, 0))
    {
        printf("%d ", arrayInt[i]);
        i++;
    }
}