/*Troy Ricks: cssc1101
*Sydney Blackburn: cssc1112
*
*Class: CS570, Professor Leonard, Summer 2017
*Due: June 19, 2017
*Project: Assignment #2, Page Replacement
*File: page.c
*/

#include "page.h"

FILE *file;

void main(){
	int frameNum, pages[99], i=0;
	printf("Enter number of frames: ");
	scanf("%d", &frameNum);
	file = fopen("pages.txt", "r");
	while(fscanf(file,"%d",&pages[i]) != EOF) {
		i++;
		if (i == 99) { break; } /* 99 is page limit */
	}
	fclose(file);
	secondChance(frameNum,pages,i);
	clockPRA(frameNum,pages,i);
	optPRA(frameNum,pages,i);
	exit(0);
}

void secondChance (int frame, int a[], int size) {
	int frames[2][frame]; /* 2D array to store the page and bit */
	int pointer=0,h,x=0,col,row,faults=0,found=0,load=0;
	for (row=0; row<2; row++){ /* Set all array elements to 0 */
		for (col=0; col<frame; col++){
			frames[row][col] = 0;
		}
	}
	while (x < size) {
		for (h=0; h<frame; h++) { /* Check if page is in mem */
			if (frames[0][h] == a[x]){
				frames[1][h] = 1; /* set bit to 1 if in mem */
				found = 1;
			}
		}
		if (found == 0) {
			do {
				/* If bit is 0 or null, load in page */
				if (frames[1][pointer] == 0) {
					frames[0][pointer] = a[x]; /* load pages */
					frames[1][pointer] = 0; /* Set bit=0 b*/
					faults++;
					load = 1; /* load successful */
				}
				else { /* If bit is 1, set bit to 0 */
					frames[1][pointer] = 0;
				}
				pointer++; /* move pointer */
				if (pointer == frame) { pointer = 0;} /* Reset */
			} while (load != 1); 
		}
		found = 0; /* reset */
		load = 0; /* reset */
		x++;
	}
	printf("Number of Second Chance faults: %d\n",faults);
}

void clockPRA(int n, int page[], int size) {
	int frames[n], use[n], fault, locat, found, i, j;
	for(i=0; i<n; i++) { /* Initialize all array elements to 0 */
		frames[i]=0;
		use[i]=0;
	}
	fault=0;
	locat=0;
	for(i=0; i<size; i++) {
		found=0; /* Reset */
		for(j=0; j<n; j++) { /* Check if page is in memory */
			if(page[i]==frames[j]) {
				found=1;
				use[j]=1;
			}
		}
		if(found==0) {
			do { /* if bit is 0 or NULL, load in page */
				if(use[locat]==0) {
					frames[locat]=page[i];
					use[locat]=1;
					found=1;
					fault++;
				}
				else { /* reset use bit */
					use[locat]=0;
				}
				locat++; /* Move pointer */
				if(locat==n) { locat=0; } /* Reset */
			} while (found!=1);
		}
	}
	printf("Number of Clock faults: %d\n", fault);
}

void optPRA(int n, int page[], int size) {
	int frames[n],fault=0,found,replace,empty=n,z=0,i,j,x;
	for(i=0; i<n; i++) { /* Set all array elements to 0 */
		frames[i]=0;
	}
	for(i=0; i<size; i++) {
		found=0; /* reset */
		replace=0; /* reset */
		for(j=0; j<n; j++) { /* Check if page is in memory */
			if(page[i]==frames[j]) {
				found=1;
			}
		
		}
		if(found==0) { /* Load in page */
			if (empty != 0) { /* Fill up all frames */
				frames[z] = page[i];
				z++;
				fault++;
				empty--;
			}
			else { /* Find page reference furthest in the future */
				for (j=0; j<n; j++) { /* Frames */
					for (x=i; x<size; x++) {
						if (frames[j] == page[x]) {
							if (x > replace) {
								replace = j; /* Frame to replace */
							}
							break;
						}
						/* If page wasn't referenced again */
						if (x == size-1) { replace = j; }
					}	
				}
				frames[replace] = page[i];
				fault++;
			}
		}
	}
	printf("Number of Optimal faults: %d\n", fault); 
}