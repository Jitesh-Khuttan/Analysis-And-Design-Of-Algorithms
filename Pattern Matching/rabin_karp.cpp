#include<iostream>
#include<string>
#include<math.h>
using namespace std;

/*Complexity: Worst Case: O(n*m) {n=length of string,m=length of substring}
			  Best Case: O(1+m) = O(m) 
			  Average Case: O(n+m) 
*/

class RabinKarp
{

	private:
		string text;
		string substring;
		int prime;
	public:
		RabinKarp();
		void setText(string);
		void setSubstring(string);
		int createInitialHash(string,int);
		int createHash(string,int,int,int);
		int isPatternMatch(); 
};

RabinKarp :: RabinKarp()
{
	prime = 101;
}

void RabinKarp :: setText(string inputText)
{
	this->text = inputText;
}

void RabinKarp :: setSubstring(string inputPattern)
{
	this->substring = inputPattern;
}

int RabinKarp :: createInitialHash(string text,int length)
{
	int i,hashValue=0;
	for(i=0;i<length;i++)
	{
		hashValue += text[i]*pow(prime,i);
	}
	return hashValue;
}

int RabinKarp :: createHash(string text,int previousHashValue,int startIndex,int length)
{
	int hashValue=0;
	previousHashValue -= text[startIndex-1];
	previousHashValue /= prime;
	previousHashValue += text[startIndex+length-1]*pow(prime,length-1);
	return(previousHashValue);
}

int RabinKarp :: isPatternMatch()
{
	int hashValue,parentHash,textLength,substrLength;
	int i;
	textLength = text.length();
	substrLength = substring.length();
	parentHash = createInitialHash(substring,substrLength);
	hashValue = createInitialHash(text,substrLength);
	for(i=1;i<=textLength-substrLength+1;i++)
	{
		if(hashValue == parentHash)
		{
			if(substring == string(this->text.begin()+i-1,this->text.begin()+i+substrLength-1))
			{
				return i-1;
			}
		}
		hashValue = createHash(this->text,hashValue,i,substrLength);
	}
	return -1;
}



int main()
{
	RabinKarp Pattern;
	string text,substr;
	int index;
	cout<<"\n\tEnter Text: ";
	cin>>text;
	cout<<"\n\tEnter Pattern To Match: ";
	cin>>substr;
	Pattern.setText(text);
	Pattern.setSubstring(substr);
	index = Pattern.isPatternMatch();
	if(index != -1)
		cout<<"\n\tPattern Found At Index: "<<index<<endl;
	else
		cout<<"\n\tPattern Not Found\n";
}