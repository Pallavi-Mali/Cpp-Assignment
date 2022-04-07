#include<iostream>
using namespace std;

class grade
{
	public:
	float attendance,test_score,total_score,a = 0.70;
	int ctr1,ctr2,ctr3;
	void input()
	{
		cout<<"Enter attendance\n";
		cin>> attendance;
		cout<<"Enter test score\n";
		cin>> test_score;
		cout<<"Enter total score\n";
		cin>> total_score;
	}
	void output()
	{
		if(attendance >=50)
		{
			ctr1 =1;
		}
		if(test_score >a || test_score == a)
		{ cout<<"inside test score\n";
			ctr2 = 1;
		}
		if(total_score >=5600)
		{
			ctr3 = 1;
		}

		if(ctr1 == 1 && ctr2 == 1 && ctr3 == 1)
		{
			cout<<"res:10\n";
		}
		else if(ctr1 == 1 && ctr2 == 1)
		{
			cout<<"res:9\n";
		}
		else if(ctr2 == 1 && ctr3 == 1)
		{
			cout<<"res:8\n";
		}
		else if(ctr1 == 1 && ctr3 == 1 )
		{
			cout<<"res:7\n";
		}
		else if(ctr1 == 1 || ctr2 == 1 || ctr3 == 1)
		{
			cout<<"res:6\n";
		}
		else
		{
			cout<<"res:5\n";
		}
					
	}

};

int main()
{
	grade ob1;
	ob1.input();
	ob1.output();
	return 0;
}
