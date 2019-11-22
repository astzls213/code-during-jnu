#include<stdio.h>
#include<stdlib.h>
#define ElementType int
ElementType BinarySearch(ElementType x, ElementType *array, int length){
	int low = 0;
	int high = length - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x == array[mid])
			return mid;
		else if (x > mid)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
ElementType *createArray(void){
	struct list
	{
		ElementType value;
		struct list *next;
	};
	struct list *header = (struct list *)malloc(sizeof(struct list));
	header->next = NULL;
	ElementType tmp;
	struct list *tmPtr=header;
	int count = 0;
	while (scanf("%d", &tmp)){
		tmPtr->next = (struct list *)malloc(sizeof(struct list));
		count++;
		tmPtr->next->value = tmp;
		tmPtr->next->next = NULL;
		tmPtr = tmPtr->next;
	}
	ElementType *rtv_val = (ElementType *)malloc(sizeof(ElementType)*(count+1));
	rtv_val[0] = count;
	tmPtr = header->next;
	for (int j = 1; tmPtr != NULL;j++){
		struct list *fre = tmPtr;
		rtv_val[j] = tmPtr->value;
		tmPtr = tmPtr->next;
		fre->next = NULL;
		free(fre);
	}
	puts("Creating vector succeeded.");
	getchar();
	return rtv_val;
}
ElementType OrderedFind(ElementType find, ElementType *array,int length){
	int i = 0;
	for (; array[i] != find&&i < length; i++)
		continue;
	if (i == length)
		return -1;
	else
		return i;
}
char menu(void){
	puts("<-----------M E N U----------->");
	puts("       a.Ordering Search       ");
	puts("        b.Binary Search        ");
	puts("            c.Exit             ");
	puts("<------------*****------------>");
	char choice;
	while (scanf("%c", &choice) != 1 || choice<'a' || choice>'c')
		puts("Undefined char, again.");
	getchar();
	return choice;
}
int main(void){
	int length;
	ElementType OrderedArray[1000];
	ElementType *array;
	for (int i = 0; i < 1000; i++)
		OrderedArray[i] = i;
	puts("Enter numbers / q to quitted :");
	array = createArray();
	length = array[0];
	for (int i = 1; i <= length; i++)
		array[i - 1] = array[i];
	system("pause");
	system("cls");
	while (1){
		ElementType target;
		int c=menu();
		system("cls");
		if (c == 'a'){
			printf("value:");
			scanf("%d", &target);
			getchar();
			c = OrderedFind(target, array,length);
			if (c == -1)
				puts("Not found!");
			else
				printf("%d located at the %dth of the array.\n", target, c + 1);
		}
		else if(c=='b'){
			printf("value:");
			scanf("%d", &target);
			getchar();
			c = BinarySearch(target, OrderedArray, 1000);
			if (c== -1)
				puts("Not found!");
			else{
				printf("%d located at the %dth of the OrderedArray.\n", target, c + 1);
			}
		}
		else{
			return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}