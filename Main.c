#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>
#include<windows.h>
#include<stdbool.h>

#define W 109	//Width of the Array
#define H 21	//Height of the Array

//Array for sorting
int numArray[W+1];	//Array of Numbers
char bar[H+1][W+1];	//2D Array Representing the Array Above

//Utility Function
void cls();			//Clear Screen
void Color(int);	//To Give Colors to the Text in the Terminal

//Menu Display
void title();		//Display the Title
void selectMain1();	//Highlighting the "Sorting" Text in Red
void selectMain2();	//Highlighting the "Exit" Text in Red

void selectSort1();	//Highlighting the "Bubble Sort" Text in Red
void selectSort2();	//Highlighting the "Selection Sort" Text in Red
void selectSort3();	//Highlighting the "Insertion Sort" Text in Red
void selectSort4();	//Highlighting the "Next" Text in Red
void selectSort5();	//Highlighting the "Back" Text in Red
void selectSort6();	//Highlighting the "Quick Sort" Text in Red
void selectSort7();	//Highlighting the "Merge Sort" Text in Red
void selectSort8();	//Highlighting the "Heap Sort" Text in Red

void thankYou();	//Display Thank You Message

//Sorting utility function
void swap(int *, int *);	//Swapping Variables
void arraySetup();			//To Randomize the Array
void arrayUpdate();			//To Update the Histogram
void displayHistogram();	//To Display the Histogram
void visualization();		//To Display the Histogram when the Sorting Algorithm is Running (It has a delay to show the process)

//Sorting Algorithm
void quickSort(int [], int, int);
void merge(int [],int ,int ,int ,int );
void mergeSort(int [],int ,int );
void heapify(int [], int , int );
void heapSort(int [], int );
void bubbleSort(int [], int);
void selectionSort(int[], int);
void insertionSort(int [], int);

//Controller
int menuSelect(int , int );	//To Change the View of the Menus
void mainMenu();
void sortingMenu();
	
int main()
{
	mainMenu();
	return 0;
}

void cls()
{
    COORD curr;
    curr.X = 0;
    curr.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curr);
}
void Color(int ColorValue)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorValue);
}

void title()
{
	puts("\n\n");
	
	printf("\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	Color(7);printf("\t\t\t    %c",186);Color(7);
	Color(10);printf("            _____            _   _                        ");Color(10);
	Color(7);printf("%c\n\t\t\t    %c",186,186);Color(7);
	Color(10);printf("           / ____|          | | (_)                       ");Color(10);
	Color(7);printf("%c\n\t\t\t    %c",186,186);Color(7);
	Color(10);printf("          | (___   ___  _ __| |_ _ _ __   __ _            ");Color(10);
	Color(7);printf("%c\n\t\t\t    %c",186,186);Color(7);
	Color(10);printf("           \\___ \\ / _ \\| '__| __| | '_ \\ / _` |           ");Color(10);
	Color(7);printf("%c\n\t\t\t    %c",186,186);Color(7);
	Color(10);printf("           ____) | (_) | |  | |_| | | | | (_| |           ");Color(10);
	Color(7);printf("%c\n\t\t\t    %c",186,186);Color(7);
	Color(10);printf("          |_____/ \\___/|_|   \\__|_|_| |_|\\__, |           ");Color(10);
	Color(7);printf("%c\n\t\t\t    %c",186,186);Color(7);
	Color(10);printf("                                          __/ |           ");Color(10);
	Color(7);printf("%c\n\t\t\t    %c",186,186);Color(7);
	Color(10);printf("                                         |___/            ");Color(10);
	Color(7);printf("%c\n",186);Color(7);
	printf("\t\t\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void selectMain1()
{
	Color(4);
	printf("                                                      Sorting\n\n\n");
	Color(4);
	Color(7);
	printf("						       Exit\n\n\n\n\n\n\n\n\n\n");
	printf("    Arrow key [down | up] to move								Enter to choose");
	Color(7);
}
void selectMain2()
{
	Color(7);
	printf("                                                      Sorting\n\n\n");
	Color(7);
	Color(4);
	printf("						       Exit\n\n\n\n\n\n\n\n\n\n");
	Color(4);
	Color(7);
	printf("    Arrow key [down | up] to move								Enter to choose");
	Color(7);
}

void selectSort1()
{
	Color(4);
	printf("               Bubble Sort ");
	Color(7);
	printf("             Selection Sort ");
	printf("            Insertion Sort ");
	printf("                 Next ");
	printf("\n\n\n     Arrow key [left | right] to move                                             [Esc to exit]  [Enter to choose]");
	Color(7);
}
void selectSort2()
{
	Color(7);
	printf("               Bubble Sort ");
	Color(4);
	printf("             Selection Sort ");
	Color(7);
	printf("            Insertion Sort ");
	printf("                 Next ");
	printf("\n\n\n     Arrow key [left | right] to move                                             [Esc to exit]  [Enter to choose]");
	Color(7);
}
void selectSort3()
{
	Color(7);
	printf("               Bubble Sort ");
	printf("             Selection Sort ");
	Color(4);
	printf("            Insertion Sort ");
	Color(7);
	printf("                 Next ");
	printf("\n\n\n     Arrow key [left | right] to move                                             [Esc to exit]  [Enter to choose]");
	Color(7);
}
void selectSort4()
{
	Color(7);
	printf("               Bubble Sort ");
	printf("             Selection Sort ");
	printf("            Insertion Sort ");
	Color(4);
	printf("                 Next ");
	Color(7);
	printf("\n\n\n     Arrow key [left | right] to move                                             [Esc to exit]  [Enter to choose]");
}
void selectSort5()
{
	Color(4);
	printf("                 Back    ");
	Color(7);
	printf("                 Quick Sort ");
	printf("                 Merge Sort ");
	printf("                 Heap Sort ");
	printf("\n\n\n     Arrow key [left | right] to move                                             [Esc to exit]  [Enter to choose]");
	Color(7);
}
void selectSort6()
{
	Color(7);
	printf("                 Back    ");
	Color(4);
	printf("                 Quick Sort ");
	Color(7);
	printf("                 Merge Sort ");
	printf("                 Heap Sort ");
	printf("\n\n\n     Arrow key [left | right] to move                                             [Esc to exit]  [Enter to choose]");
	Color(7);
}
void selectSort7()
{
	Color(7);
	printf("                 Back    ");
	printf("                 Quick Sort ");
	Color(4);
	printf("                 Merge Sort ");
	Color(7);
	printf("                 Heap Sort ");
	printf("\n\n\n     Arrow key [left | right] to move                                             [Esc to exit]  [Enter to choose]");
	Color(7);
}
void selectSort8()
{
	Color(7);
	printf("                 Back    ");
	printf("                 Quick Sort ");
	printf("                 Merge Sort ");
	Color(4);
	printf("                 Heap Sort ");
	Color(7);
	printf("\n\n\n     Arrow key [left | right] to move                                             [Esc to exit]  [Enter to choose]");
}

void thankYou()
{
	printf("\n\n\n\n\n\n\n\n\n\t\t");
	printf("\"Achieve greatness by excelling in your efforts, persisting through obstacles, acting\n\t\t with integrity, respecting others, innovating with courage, and working collaboratively.\"");
	printf("\n\n\n\n\n\n\n\t\t");
	printf("Press Enter to Exit\n\n\n\n\n\n\n\n\n\n");	
	getchar();
}

void swap(int *a, int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void arraySetup()
{
	int i,j,k;
	for(i=0;i<W;i++) numArray[i] = rand()%H+1;
	
	for(i=0;i<H;i++)
	{
		for(j=0;j<W;j++) bar[i][j]=32;
		bar[i][j]='\0';
	}
	
	for(i=0;i<W;i++)
	{
		for(j=0;j<numArray[i];j++) bar[j][i] = 219;
	}
}
void arrayUpdate()
{
	int i,j,k;
	for(i=0;i<W;i++)
	{
		for(j=0;j<numArray[i];j++) bar[j][i] = 219;
		for(k=j;k<H;k++) bar[k][i] = 32;
	}
}
void displayHistogram()
{
	int i;
	puts("");
	Sleep(25);
	for(i=H;i>=0;i--) printf("     %s\n",bar[i]);
	puts("\n");
}
void visualization()
{
	int i;
	puts("");
	Sleep(25);
	for(i=H;i>=0;i--) printf("     %s\n",bar[i]);
	puts("\n\n");
	printf("                                                        Sorting...");
}

void quickSort(int arr[], int left, int right)
{
	int i,j,k;
	if(left<right)
	{
		j=left;
		k=right+1;
		
		do
		{
			do{ j++; } while(arr[j]<arr[left]);
			do{ k--; } while(arr[k]>arr[left]);
			if(j<k)
			{
				swap(&arr[j],&arr[k]);
				arrayUpdate();
				cls();
				visualization();
				printf("\n                        Time Complexity [Best O(n * log n) | Average O(n * log n) | Worst O(n^2)]");
			}
		}while(j<=k);
		swap(&arr[left],&arr[k]);
		arrayUpdate();
		cls();
		visualization();
		quickSort(arr,left,k-1);
		quickSort(arr,k+1,right);
	}
}
void merge(int arr[],int left,int middle1,int middle2,int right)
{
	int leftIndex=left;
	int rightIndex=middle2;
	int middleIndex=left;
	int tmpArr[W];
	int i;
	
	while(leftIndex<=middle1 && rightIndex<=right)
	{
		if(arr[leftIndex]<=arr[rightIndex])
			tmpArr[middleIndex++]=arr[leftIndex++];
		else
			tmpArr[middleIndex++]=arr[rightIndex++];
	}
	
	if(leftIndex==middle2)
	{
		while(rightIndex<=right)
			tmpArr[middleIndex++]=arr[rightIndex++];
	}
	else
	{
		while(leftIndex<=middle1)
			tmpArr[middleIndex++]=arr[leftIndex++];
	}
	
	for(i=left;i<=right;i++)
	{
		arr[i]=tmpArr[i];
		arrayUpdate();
		cls();
		visualization();
		printf("\n                    Time Complexity [Best O(n *log n) | Average O(n * log n) | Worst O(n * log n)]");
	}
}
void mergeSort(int arr[],int left,int right)
{
	int middle1,middle2;
	
	if((right-left)>=1)
	{
		middle1=(left+right)/2;
		middle2=middle1+1;
		mergeSort(arr,left,middle1);
		mergeSort(arr,middle2,right);
		merge(arr,left,middle1,middle2,right);
	}
}
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (left < n && arr[left] > arr[largest]) largest = left;
	if (right < n && arr[right] > arr[largest]) largest = right;
	
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		arrayUpdate();
		cls();
		visualization();
		printf("\n                    Time Complexity [Best O(n *log n) | Average O(n * log n) | Worst O(n * log n)]");
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	int i;
	for(i=n/2-1;i>=0;i--) heapify(arr, n, i);
	
	for(i=n-1;i>=0;i--)
	{
		swap(&arr[0], &arr[i]);
	    arrayUpdate();
	    cls();
		visualization();
		printf("\n                    Time Complexity [Best O(n *log n) | Average O(n * log n) | Worst O(n * log n)]");
		heapify(arr,i,0);
	}
}
void bubbleSort(int arr[], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				arrayUpdate();
				cls();
				visualization();
				printf("\n                             Time Complexity [Best O(n^2) | Average O(n^2) | Worst O(n^2)]");
			}
		}
	}
}
void selectionSort(int arr[], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		int minIndex = i;
		for(j = i+1; j < n; j++)
		{
			if(arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
			if(i!=0)Sleep(5);
		}
		swap(&arr[i], &arr[minIndex]);
		arrayUpdate();
		cls();
		visualization();
		printf("\n                             Time Complexity [Best O(n^2) | Average O(n^2) | Worst O(n^2)]");
	}
}
void insertionSort(int arr[], int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		int temp = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			arr[j] = temp;
			j--;
			arrayUpdate();
			cls();
			visualization();
			printf("\n                               Time Complexity [Best O(n^2) | Average O(n) | Worst O(n^2)]");
		}
		arr[j+1] = temp;
		arrayUpdate();
		cls();
		visualization();
		printf("\n                               Time Complexity [Best O(n^2) | Average O(n) | Worst O(n^2)]");
	}
}

int menuSelect(int menuSelection, int menuType)
{
	unsigned char control;
	system("CLS");
	while(1)
	{
		cls();
		if(menuType == 1)
		{
			title();
			switch(menuSelection)
			{
				case 1:
					selectMain1();
					break;
				case 2:
					selectMain2();
					break;
			}
			control = getch();
			if(control==0 || control==0xE0)
				control=getch();
			if(control==72)
			{
				if(menuSelection!=1)
					menuSelection--;
			}
			else if(control==80)
			{
				if(menuSelection!=2)
					menuSelection++;
			}
			else if(control==13)
			{
				return menuSelection;
			}
		}
		else if(menuType==2)
		{
			displayHistogram();
			switch(menuSelection)
			{
				case 1:
					selectSort1();
					break;
				case 2:
					selectSort2();
					break;
				case 3:
					selectSort3();
					break;
				case 4:
					selectSort4();
					break;
			}
			control = getch();
			if(control==0 || control==0xE0)
				control=getch();
			if(control==75)
			{
				if(menuSelection!=1)
					menuSelection--;
			}
			else if(control==77)
			{
				if(menuSelection!=4)
					menuSelection++;
			}
			else if(control==13)
			{
				return menuSelection;
			}
			else if(control==27)
			{
				return 0;
			}
		}
		else if(menuType==3)
		{
			displayHistogram();
			switch(menuSelection)
			{
				case 5:
					selectSort5();
					break;
				case 6:
					selectSort6();
					break;
				case 7:
					selectSort7();
					break;
				case 8:
					selectSort8();
					break;
			}
			control = getch();
			if(control==0 || control==0xE0)
				control=getch();
			if(control==75)
			{
				if(menuSelection!=5)
					menuSelection--;
			}
			else if(control==77)
			{
				if(menuSelection!=8)
					menuSelection++;
			}
			else if(control==13)
			{
				return menuSelection;
			}
			else if(control==27)
			{
				return 0;
			}
		}
	}
}
void mainMenu()
{
	srand(time(0));
	int selection=1;
	do
	{
		selection = menuSelect(selection,1);
		system("CLS");
		switch(selection)
		{
			case 1:
				arraySetup();
				sortingMenu();
				break;
			case 2:
				thankYou();
		}
	}while(selection!=2);
}
void sortingMenu()
{
	int selection=1;
	int mode = 2;
	int n = sizeof(numArray)/sizeof(numArray[0]);
	do
	{
		selection = menuSelect(selection,mode);
		int sorted = false;
		cls();
		switch(selection)
		{
			case 1:
				system("CLS");
				bubbleSort(numArray, n-1);
				sorted = true;
				break;
			case 2:
				system("CLS");
				selectionSort(numArray, n-1);
				sorted = true;
				break;
			case 3:
				system("CLS");
				insertionSort(numArray, n-1);
				sorted = true;
				break;
			case 4:
				selection = 5;
				mode = 3;
				break;
			case 5:
				selection = 4;
				mode = 2;
				break;
			case 6:
				system("CLS");
				quickSort(numArray,0,n-1);
				sorted = true;
				break;
			case 7:
				system("CLS");
				mergeSort(numArray,0,n-1);
				sorted = true;
				break;
			case 8:
				system("CLS");
				heapSort(numArray,n);
				sorted = true;
				break;
			default:
				break;
		}
		if(sorted)
		{
			system("CLS");
			displayHistogram();
			printf("\n                                              Sorted! Press Enter to Continue");
			getchar();
			break;
		}
	}while(selection!=0);
}

