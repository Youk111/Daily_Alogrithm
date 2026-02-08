#include <stdio.h>
#include <stdlib.h>
// 用于提交的功能函数
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    int size = 2;
    int *pos = malloc(size * sizeof(int));
    for(i=0; i<numsSize; i++)
    {
        for(j=i+1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                pos[0] = i, pos[1] = j;
                *returnSize = 2;
                return pos;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

// 专门用于测试的主函数
int main()
{
    int size = 4;
    int nums[4] = {2,4,5,10};
    int target = 10;
    int resultsize = 0;
    int *result = NULL; 
    result = twoSum(nums, size, target, &resultsize);
    printf("resultSize = %d\n",resultsize);
    if(resultsize > 0)
    {
        printf("result = [%d,%d]\n",result[0],result[1]);
    }
    else
    {
        printf("NOT FOUND\n");
    }
    free(result);

}