#include <iostream>
#include <map>
// ‰»Î∏Ò Ω
//1.Add Mary 12 80
//2.Query 81  
using namespace std;
class CStudent
{
	public:
	class Info
	{
		public:
			int id;
			string name;
			Info(int id, string name) :id(id), name(name)
			{

			}
	};
	public:
		Info cinfo;
		int score;
		CStudent(string name, int id, int score) :cinfo(id,name), score(score)
		{

		}
		CStudent() :cinfo(-1, "anonymous"), score(-1)
		{

		}
};
int main()
{
	multimap<int, CStudent::Info> database;
	CStudent cs;
	string cmd;
	int tempscore;
	while (cin >> cmd)
	{
		if (cmd == "Add")
		{
			cin >> cs.cinfo.name;
			cin >> cs.cinfo.id;
			cin >> cs.score;
			database.insert(pair<int, CStudent::Info>(cs.score, cs.cinfo));
		}
		else if (cmd == "Query")
		{
			cin >> tempscore;
			multimap<int, CStudent::Info>::iterator p = database.lower_bound(tempscore);
				if (p != database.begin())
				{
					--p;
					int maxscore = p->first;
					string maxname = p->second.name;
					int maxid = p->second.id;
					multimap<int, CStudent::Info>::iterator maxp = p;
					while(p!=database.begin())
					{
						--p;
						if (p->first == maxp->first)
						{
							if (p->second.id > maxp->second.id)
							{
								maxp = p;
								maxid = p->second.id;
								maxname = p->second.name;
							}
						}
						else
						{
							break;
						}
					}
					cout << maxname << " " << maxid << " " << maxscore<<endl;
				}
				else
				{
					cout << "Nobody" << endl;
				}
		}
	}
	return 0;
}

