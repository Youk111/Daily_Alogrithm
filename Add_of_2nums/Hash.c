// 该代码使用哈希表方法进行查找
#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
struct hashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable *hashtable=NULL;

struct hashTable *find(int ikey){
    struct hashTable* tmp;  //定义结构体指针变量，用于存储哈希表结果并返回
    HASH_FIND_INT(hashtable, &ikey, tmp);   //查找哈希表中key值与ikey相同的结果
    return tmp;
}

// 插入目标至哈希表
void insert(int ikey, int ival){
    struct hashTable* it = find(ikey);  //在现有表中查找是否有key值相同的目标
    if (it == NULL){    //如果返回结果为NULL则表示哈希表中没有该目标
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);  //将该目标存放至哈希表中
    } else {    //找到目标，则表示目标为同一个，不需要再存放
        it->val = ival;
    }
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    hashtable = NULL;
    for (i = 0; i < numsSize; i++){
        struct hashTable* it = find(target - nums[i]);  //在哈希表中查找target-x的值
        if(it != NULL){     //结果非空，表明找到结果
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;   //返回x与target-x在数组中序列
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i); //插入当前的值到哈希表中
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int size = 4;
    int nums[4] = {2,7,11,15};
    int target = 9;
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