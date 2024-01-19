

#include <stdio.h>
int main() {

int arr[] = {1, 2, 3, 4};
	int* ptr1 = arr;
	int* ptr2 = arr;
	
	ptr2 += 1;
	printf("%p\n", ptr1);
	printf("%p\n", ptr2);
	printf("%d\n", (ptr2 - ptr1));
}

