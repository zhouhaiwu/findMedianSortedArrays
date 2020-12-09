#include <stdio.h>
#include <string.h>
#include <stdlib.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //int numsum[] = {0}; // 两个数组归并后，放到numsum里
    int *numsum=(int *)malloc(sizeof(int)*(nums1Size+nums2Size));
    int i = 0, j = 0; // 数组nums1的下标，数组nums2的下标
    int k = 0; // 归并数组的长度大小

    //两个数组元素按顺序进行对比,归并成一个大的有序的数组
    while(1) {
        if((i < nums1Size) && (j < nums2Size)) { //两个数组元素按顺序进行比对
            if(nums1[i] < nums2[j]) {
                numsum[k] = nums1[i];
                printf("numsum[k]:%d\n", numsum[k]);
                printf("k:%d\n", k);
                k++;
                i++;
            }
            else {
                numsum[k] = nums2[j];
                k++;
                j++;
            }
        }

        if((i < nums1Size) && (j == nums2Size)) { //如果数组nums2已经归并完全，则把nums1剩下的直接写入numsum
            numsum[k] = nums1[i];
            k++;
            i++;
        }

        if((i == nums1Size) && (j < nums2Size)) { //如果数组nums1已经归并完全，则把nums2剩下的直接写入numsum
            numsum[k] = nums2[j];
            printf("numsum[k]:%d\n", numsum[k]);
            printf("j:%d\n", j);
            printf("k:%d\n", k);
            k++;
            j++;
        }

        if((i == nums1Size) && (j == nums2Size)) { //如果两个都归并完，则直接退出while循环
            break;
        }
    }


    //根据归并后数组的长度，三种情况：k=1，k能被2整除，k不能被2整除，分别做处理
    double zznum = 0;
    printf("k:%d\n", k);

    if (k == 1) {
        zznum = numsum[0];
    }
    
    if (k >= 2) {
        if ((k % 2) == 0) {
            zznum = ((double)numsum[k/2] + (double)numsum[k/2 - 1])/2;
            printf("numsum[num/2]:%f\n", zznum);
            printf("numsum[num/2 - 1]:%f\n", zznum); 
            printf("zznum:%f\n", zznum);
        }

        if ((k % 2) == 1) {
            zznum = (numsum[k/2]);
        }
    }

    return zznum;
}

int main() {
    //nums1 = [1,2], nums2 = [3,4]
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    //int nums1[] = {0, 0};
    //int nums2[] = {0, 0};
    //[1,2]
    //[3,4]
    //int nums1[] = {1, 3};
    //int nums2[] = {2};
    double zznum = 0;
    zznum = findMedianSortedArrays(nums1, 2, nums2, 2);
    printf("zznum:%f\n", zznum);
    return 0;
}