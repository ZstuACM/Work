#include <math.h>  
#include <stdio.h>  
#include <stdlib.h>  
float generate_random()  
{  
    //randomly generate number between [0,1]  
    float rand_num = 0.0;  
    rand_num = (float)rand()/RAND_MAX;  
    //printf("%f\n", rand_num);  
    return rand_num;  
}  
 
float *generate_probability_band(float *prob_arr, int length)  
{  
    //产生概率带  
    //传入参数是在main函数中指定的概率分布  
    //传出参数就是概率带(积累概率)
    //计算累计概率，保存在sum_array数组中，用malloc写了一下。  
      
    printf("一共有%d个概率数据\n",length);  
  
    float *sum_array = NULL;  
    float *sum_array_tmp = NULL;  
    sum_array = (float *)malloc((length+1)*sizeof(float));//多一个是为了保存概率带最左边那个0  
    sum_array_tmp = sum_array;  
    int i = 0;  
    float sum = 0.0;  
    sum_array[0] = 0.0;  
    for(i;i<length;i++)  
    {  
        sum = sum + prob_arr[i];  
        printf("sum=%f\n",sum);  
        sum_array++;//先执行++，目的是把概率带最左边那个0保存在sum_array[0]上  
        *sum_array = sum;  
        //printf("%x-->%f\n", sum_array,*sum_array);          
    }  
    //sum_array = sum_array_tmp;  
    return sum_array_tmp;  
    //free(sum_array);  
}  
  
//判断随机数位于概率带的哪个位置  
int *judge_random_location(float *sum_array, int length)  
{  
      
    int i = 0;  
    int j = 0;  
    float rand_num=0;  
    int *count=NULL;  
    count = (int *)malloc((length-1)*sizeof(int)); //count数组用来统计 落在某个概率上的数量  
    for(i=0;i<length-1;i++)  
    {  
        //初始化为0  
        count[i] = 0;  
    }  
  
    for(i=0;i<length;i++)  
    {  
        printf("sum_array[%d] = %f\n", i, sum_array[i]);  
    }  
  
    for(j=0;j<1000;j++) //产生1000个随机数  
    {  
        rand_num = generate_random();  
        if(rand_num>0 && rand_num<1)  
        {  
            for(i=0;i<length;i++)  
            {  
                if(rand_num>sum_array[i] && rand_num<=sum_array[i+1])  
                {  
                    //对应的概率带 计数器加1  
                    count[i] = count[i]+1;  
                }  
  
            }  
        }  
    }  
      
    return count;  
}  
int main()  
{  
    int i=0;  
  
    //probability array  
    float prob_arr[] = {0.1, 0.2, 0.3, 0.4}; //按照概率1:2:3:4  
    int length = sizeof(prob_arr)/sizeof(prob_arr[0]);  
    float *sum_array = NULL;  
    int *count=NULL;  
  
    sum_array = generate_probability_band(prob_arr, length);  
    count = judge_random_location(sum_array, length+1);  
  
    for(i=0;i<length;i++)  
    {  
        printf("%d:", count[i]);  
        if(i == (length-1))  
            printf("\b");  
    }  
    printf("\n");  
    system("pause");  
}

