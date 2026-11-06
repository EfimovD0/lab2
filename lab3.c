#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void permutations(int index, int size, int *num, bool *used, int *current_per){
	if (index==size){
		for (int i=0; i<=size; i++){
			printf("%d ", current_per[i]);
		}
		printf("\n");
		return;
	}
	for (int i=0; i<size; i++){
		if (used[i] == false){
			current_per[index]=num[i];
			used[i]=true;
			permutations(index+1, size, num, used, current_per);
			used[i]=false;
		}
	}
}

int main(){
	int N;
	int M;
	
	printf("enter N ");
	if (scanf("%d", &N)<1){
		printf("wrong number");
		return 1;
	}
	printf("inter M");
	if (scanf("%d", &M)<1){
		printf("wrong number");
		return 1;
	}
	if (N>=M){
		printf("N>M");
		return 1;
	}
	int size = M - N + 1;
	int *num = malloc(size * sizeof(num));
	bool *used = malloc(size * sizeof(used));
	int *current_per = malloc(size * sizeof(current_per));

	for (int i=0; i<size; i++){
		num[i] = N+i;
		used[i]=false;
		
	}
	permutations(0, size, num, used, current_per);
	free(num);
	free(used);
	free(current_per);
	return 0;
}
