#include <stdio.h>

void detectRange (int *samples, int count)
{
	int lengthOfRange = 1;
	int loop = 0;
	int firstVal = *samples;
	
	for (loop = 1; loop <= count; loop++)
	{
		if (((samples[loop] - samples[loop-1]) == 1) || ((samples[loop] - samples[loop-1]) == 0)) 
		{
			lengthOfRange++;
		}
		else
		{
			printf("Range = %d - %d, Number of samples in range = %d", &firstVal, &samples[loop-1], lengthofRange);
			firstVal = *(samples+loop);
			lengthOfRange = 1;
		}
	}
}

void sortSamples (int *samples, int count)
{
	int i, j, temp;

	for (i = 0; i < count-1; i++) 
	{
		for (j = i + 1; j < count; j++)
		{
			if (samples[i] > samples[j]) 
			{
				temp =  samples[i];
				samples[i] = samples[j];
				samples[j] = temp;
			}
		}
	}
}

int main()
{
	int currMeasurements[8] = {1, 1, 7, 5, 9, 3, 6, 10};
	int numberOfSamples = sizeof(currMeasurements)/sizeof(currMeasurements[0]);
	sortSamples(currMeasurements, numberOfSamples);
	detectRange(currMeasurements, numberOfSamples);
	return 0;
}

		
