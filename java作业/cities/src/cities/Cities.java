package cities;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Cities {
	ArrayList<String> citynames=new ArrayList<String>();
	HashMap<String,City> citylist=new HashMap<String,City>();
	
	void add_city(String cityname)
	{
		citynames.add(cityname);
		citylist.put(cityname,new City());
	}
//	void add_all_city_distance(Scanner in)
//	{
//		int num;
//		for(int i=0;i<citylist.size();i++)
//		{
//			for(int j=0;j<citylist.size();i++)
//			{
//				num=in.nextInt();
//				citylist.get(citynames.get(i)).add_citydistance(citynames.get(j), num);
//			}
//		}
//	}
	void add_distance(int i,int j,int num)
	{
		citylist.get(citynames.get(i)).add_citydistance(citynames.get(j), num);
	}
	void show_twocities_distance(String name1,String name2)
	{
		System.out.println(citylist.get(name1).show_distance(name2));
	}
	int show_listsize()
	{
		return citylist.size();
	}
	public static void main(String[] args) {
		Cities cl=new Cities();
		Scanner in=new Scanner(System.in);
		String cn=in.next();
		while(!cn.equals("###"))
		{
			cl.add_city(cn);
			cn=in.next();
		}
		int num;
		for(int i=0;i<cl.show_listsize();i++)
		{
			for(int j=0;j<cl.show_listsize();j++)
			{
				num=in.nextInt();
				cl.add_distance(i,j,num);
				
			}
		}
		String name1=in.next();
		String name2=in.next();
		cl.show_twocities_distance(name1,name2);

	}

}
