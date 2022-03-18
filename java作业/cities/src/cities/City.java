package cities;
import java.util.HashMap;
public class City {
	String ownname;
	HashMap<String,Integer> distancelist=new HashMap<String,Integer>();
	
	void add_citydistance(String newcity,Integer distance)
	{
		distancelist.put(newcity, distance);
	}
	
	Integer show_distance(String city)
	{
		return distancelist.get(city);
	}
	
	String show_name(Integer i)
	{
		return "";
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String a="###";
		System.out.println(a.equals("###"));
	}

}
