#include<stdio.h>

void sort( int arr[],int n){
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int nums[100];
    int i=0;
    int num;
    FILE* f1;
    f1 = fopen("f1.txt","r");
    
    while(fscanf(f1,"%d",&num)!=EOF){
        nums[i]=num;
        i++;
    }
    fclose(f1);

    FILE* f2;
    f2 = fopen("f2.txt","r");
    
    while(fscanf(f2,"%d",&num)!=EOF){
        nums[i]=num;
        i++;
    }
    fclose(f2);

    FILE* f3;
    f3 = fopen("f3.txt","r");
    
    while(fscanf(f3,"%d",&num)!=EOF){
        nums[i]=num;
        i++;
    }
    fclose(f3);

    FILE* f4;
    f4 = fopen("f4.txt","r");
    
    while(fscanf(f4,"%d",&num)!=EOF){
        nums[i]=num;
        i++;
    }
    fclose(f4);

    sort(nums,i);

    FILE *fout;
    fout = fopen("output.txt","w");
    for(int k=0; k<i; k++){
        fprintf(fout,"%d ",nums[k]);
    }
    printf("Result saved in output.txt");
    return 0;
}
