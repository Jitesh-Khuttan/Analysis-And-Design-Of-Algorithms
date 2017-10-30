#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;

void LCS(char *sequence1,char *sequence2,int length1,int length2)
{
	int lcsarray[length1+1][length2+1],temp,lcslength=0;
	char trackLCS[length1+1][length2+1];
	char *sequence3;
	int counter,offset,tempc,tempo;
	for(counter=0,tempc=-1;counter<length1+1;counter++,tempc++)
	{
		for(offset=0,tempo=-1;offset<length2+1;offset++,tempo++)
		{
			if(counter == 0 || offset == 0)
			{
				lcsarray[counter][offset] = 0;
				trackLCS[counter][offset] = 'n';
			}
			else if(sequence1[tempc] == sequence2[tempo])
			{
				lcsarray[counter][offset] = 1 + lcsarray[counter-1][offset-1];
				trackLCS[counter][offset] = 'd';
			}
			else
			{
				if(lcsarray[counter-1][offset] > lcsarray[counter][offset-1])
				{
					lcsarray[counter][offset] = lcsarray[counter-1][offset];
					trackLCS[counter][offset] = 'u';
				}
				else
				{
					lcsarray[counter][offset] = lcsarray[counter][offset-1];
					trackLCS[counter][offset] = 'l';
				}
			}
		}
	}
	sequence3 = (char*)calloc(lcsarray[length1][length2],sizeof(char));
	lcslength = lcsarray[length1][length2];
	counter=length1; offset = length2; temp = lcslength-1;
	while(lcsarray[counter][offset] != 0)
	{
		//cout<<"\n\ttrackLCS["<<counter<<"]["<<offset<<"] : "<<trackLCS[counter][offset];
		if(trackLCS[counter][offset] == 'd')
		{
			// if(length1 > length2)
			// {
			// 	cout<<"\n\t"<<sequence2<<"["<<counter<<"]: "<<sequence2[counter-1];
			// 	sequence3[temp++] = sequence2[counter-1];
			// }
			// else
			{
				//cout<<"\n\t"<<sequence2<<"["<<offset<<"]: "<<sequence2[offset-1];
				sequence3[temp--] = sequence2[offset-1];
			}
			counter-=1; offset-=1;
		}
		else if(trackLCS[counter][offset] == 'l')
			offset-=1;
		else if(trackLCS[counter][offset] == 'u')
			counter-=1;
	}
	// cout<<"\n\tThe LCS Array:\n\t";
	// for(counter=0;counter<length1+1;counter++)
	// {
	// 	for(offset=0;offset<length2+1;offset++)
	// 	{
	// 		cout<<lcsarray[counter][offset];
	// 	}
	// 	cout<<"\n\t";
	// }
	// cout<<"\n\tThe Track Array:\n\t";
	// for(counter=0;counter<length1+1;counter++)
	// {
	// 	for(offset=0;offset<length2+1;offset++)
	// 	{
	// 		cout<<trackLCS[counter][offset];
	// 	}
	// 	cout<<"\n\t";
	// }
	cout<<"\n\tLength Of subsequence: "<<lcslength;
	cout<<"\n\tLCS is: "<<sequence3;
	// for(counter = lcslength-1 ; counter >= 0;counter--)
	// 	cout<<sequence3[counter];
	cout<<"\n\t";
}

int main()
{
	char X[]="GTCGTTCGGAATGCCGTTGCTCTGTAAA";
	char Y[]="ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
	LCS(X,Y,strlen(X),strlen(Y));
}