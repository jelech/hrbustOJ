#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	float f;
	while(~scanf("%f", &f))
	{
		int x = f*100;
		double y = x/100;
		// printf("x=%d\n", x);
		if (x%100 == 0)
		{
			printf("%.f", y);
		}else{
			printf("%.f", y+1);
		}
		printf(" %.f", y);
		printf(" %.f\n", f);

	}
	return 0;
}