#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Utils.cpp"
 
	
int main(void){
	//declare variables
	double sum=0.0, mean, stndDev;
	int median;
	
	// declare a string to hold the name of the file
	// that will be read into your statsArray
	char statsFile[10];							/* file to be read in */
	printf("Enter the file to process: ");
	scanf("%s",statsFile);
	printf("%s\n",statsFile);
	int arraySize = getFileSize(statsFile);		/* determine size of file */
  
	//dynamically declare statsArray based on size of file
	int *statsArray = (int*)malloc(sizeof(int)*arraySize);
	
	//declare histogram array
	int histarr[10];
	
	// initialize arrays with zero values
	/*
		Use the initializeArray function in Utils.cpp. Say you had an array 
		named myArray.  And it's size was stored in a variable of type
		int named mySize.  Then you could call the function
		as follows:
		
		initializeArray(myArray, mySize);
		
		After this line executed, myArray would be filled with zeroes. 
	*/
	initializeArray(statsArray, arraySize);
	initializeArray(histarr, 10);
	
	//load array from file
	/*
		Use the loadArray function in Utils.cpp to load you array with the 
		data from a file.
		Say you had an array named myArray with it's size value stored in
		an int variable named mySize.  Finally, assume you wanted to load the
		data from a file named myFile.txt.  Further, assume you declared a character
		array variable (named myFileNameVariable) to hold the name of the file as follows:
		
		char myFileNameVariable[] = "myFile.txt";
		
		Then you would call the function as follows:
		
		loadArray(myArray, mySize, myFileNameVariable);
		
		After this line executed, myArray would be filled with the data from
		the file myFile.txt
	*/
	loadArray(statsArray, arraySize, statsFile);
	
	// sum stats array
	
	for(int i=0; i<arraySize; i++){
		sum+=statsArray[i];
	}
	
	//calculate the mean
	mean = sum/arraySize;
	
	//calculate standard deviation
	int temp[arraySize];
	for(int i=0; i<arraySize; i++){
		temp[i]=(statsArray[i]-mean)*(statsArray[i]-mean);
	}
	double tsum=0.0;
	for(int i=0; i<arraySize; i++){
		tsum+=temp[i];
	}
	stndDev=sqrt(tsum/arraySize);
	
	//calculate the median
	for(int i=0; i<arraySize-1; i++){
		for(int k=0; k<arraySize-1; k++){
			if(statsArray[i]>statsArray[i+1]){
				tsum=statsArray[i+1];
				statsArray[i+1]=statsArray[i];
				statsArray[i]=tsum;
			}
		}
	}
	median = statsArray[arraySize/2];
	//fill histogram array with proper counts of batting averages
	for(int i=0; i<arraySize; i++){
		if(statsArray[i]>=1 && statsArray[i]<=100){
			histarr[0]++;
		}
		else if(statsArray[i]>=101 && statsArray[i]<=200){
			histarr[1]++;
		}
		else if(statsArray[i]>=201 && statsArray[i]<=300){
			histarr[2]++;
		}
		else if(statsArray[i]>=301 && statsArray[i]<=400){
			histarr[3]++;
		}
		else if(statsArray[i]>=401 && statsArray[i]<=500){
			histarr[4]++;
		}
		else if(statsArray[i]>=501 && statsArray[i]<=600){
			histarr[5]++;
		}
		else if(statsArray[i]>=601 && statsArray[i]<=700){
			histarr[6]++;
		}
		else if(statsArray[i]>=701 && statsArray[i]<=800){
			histarr[7]++;
		}
		else if(statsArray[i]>=801 && statsArray[i]<=900){
			histarr[8]++;
		}
		else if(statsArray[i]>=901 && statsArray[i]<=1000){
			histarr[9]++;
		}
		//else{
		//	printf("The termites got loose in the mainframe again. \n");
		//}
	}
	
	//print histogram
	printf("Array size:             %i\n", arraySize);
	printf("Mean:                   %.02lf\n", mean);
	printf("Standard deviation:     %.02lf\n", stndDev);
	printf("Median:                 %i\n", median);
	printf("  averages      qty\n");
	printf(" ----------     ---\n");
	printf("[001 -  100]");
	int i=0;
	if(histarr[i]<10 && histarr[i]>=0){
		printf("      %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("    %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	i++;
	printf("\n[101 -  200]");
	if(histarr[i]<10 && histarr[i]>=0){
		printf("      %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("    %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	i++;
	printf("\n[201 -  300]");
	if(histarr[i]<10 && histarr[i]>=0){
		printf("      %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("    %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	i++;
	printf("\n[301 -  400]");
	if(histarr[i]<10 && histarr[i]>=0){
		printf("      %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("    %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	i++;
	printf("\n[401 -  500]");
	if(histarr[i]<10 && histarr[i]>=0){
		printf("      %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("    %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	i++;
	printf("\n[501 -  600]");
	if(histarr[i]<10 && histarr[i]>=0){
		printf("      %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("    %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	i++;
	printf("\n[601 -  700]");
	if(histarr[i]<10 && histarr[i]>=0){
		printf("      %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("    %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	i++;
	printf("\n[701 -  800]");
	if(histarr[i]<10 && histarr[i]>=0){
		printf("      %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("    %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	i++;
	printf("\n[801 -  900]");
	if(histarr[i]<10 && histarr[i]>=0){
		printf("      %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("    %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	i++;
	printf("\n[901 -  1000]");
	if(histarr[i]<10 && histarr[i]>=0){
		printf("     %i: ", histarr[i]);
	}
	else if(histarr[i]<100 && histarr[i]>=10){
		printf("    %i: ", histarr[i]);
	}
	else if(histarr[i]<1000 && histarr[i]>=100){
		printf("   %i: ", histarr[i]);
	}
	for(int k=0; k<histarr[i]/10; k++){
		printf("*");
	}
	
	//release memory -
	/*
		Ensure that the following line of code remains just before the
		return statement. It's purpose is to return memory back to the
		computer.  Without this statement, you would have a memory leak.
	*/
	free(statsArray);
	
	return 0;
}

