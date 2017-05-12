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
    //�������ʴ�  
    //�����������main������ָ���ĸ��ʷֲ�  
    //�����������Ǹ��ʴ�(���۸���)
    //�����ۼƸ��ʣ�������sum_array�����У���mallocд��һ�¡�  
      
    printf("һ����%d����������\n",length);  
  
    float *sum_array = NULL;  
    float *sum_array_tmp = NULL;  
    sum_array = (float *)malloc((length+1)*sizeof(float));//��һ����Ϊ�˱�����ʴ�������Ǹ�0  
    sum_array_tmp = sum_array;  
    int i = 0;  
    float sum = 0.0;  
    sum_array[0] = 0.0;  
    for(i;i<length;i++)  
    {  
        sum = sum + prob_arr[i];  
        printf("sum=%f\n",sum);  
        sum_array++;//��ִ��++��Ŀ���ǰѸ��ʴ�������Ǹ�0������sum_array[0]��  
        *sum_array = sum;  
        //printf("%x-->%f\n", sum_array,*sum_array);          
    }  
    //sum_array = sum_array_tmp;  
    return sum_array_tmp;  
    //free(sum_array);  
}  
  
//�ж������λ�ڸ��ʴ����ĸ�λ��  
int *judge_random_location(float *sum_array, int length)  
{  
      
    int i = 0;  
    int j = 0;  
    float rand_num=0;  
    int *count=NULL;  
    count = (int *)malloc((length-1)*sizeof(int)); //count��������ͳ�� ����ĳ�������ϵ�����  
    for(i=0;i<length-1;i++)  
    {  
        //��ʼ��Ϊ0  
        count[i] = 0;  
    }  
  
    for(i=0;i<length;i++)  
    {  
        printf("sum_array[%d] = %f\n", i, sum_array[i]);  
    }  
  
    for(j=0;j<1000;j++) //����1000�������  
    {  
        rand_num = generate_random();  
        if(rand_num>0 && rand_num<1)  
        {  
            for(i=0;i<length;i++)  
            {  
                if(rand_num>sum_array[i] && rand_num<=sum_array[i+1])  
                {  
                    //��Ӧ�ĸ��ʴ� ��������1  
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
    float prob_arr[] = {0.1, 0.2, 0.3, 0.4}; //���ո���1:2:3:4  
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

