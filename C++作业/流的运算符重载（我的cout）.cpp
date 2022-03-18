#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class mycout{
	public:
		mycout& operator<<(const char* s)
		{
			if (!strcmp(s, "endl"))
			{
				printf("\n");
			}
			else
			{
				printf("%s这是我的cout", s);
			}
			return *this;
		}
};
const char* myendl = "endl";
int main()
{
	mycout cout1;
	cout1 << "你好！"<<"再来一遍,你好！"<<myendl;
	return 0;
}

