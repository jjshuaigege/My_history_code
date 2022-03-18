package castle;

import java.util.HashMap;

public class Room {
	
    private String description;
    
    private HashMap<String, Room> roomexits=new HashMap<String, Room>();
//    private Room northExit;
//    private Room southExit;
//    private Room eastExit;
//    private Room westExit;

    public Room(String description) 
    {
        this.description = description;
    }
    public Room Go_Other_Room(String direction)
    {
    	return roomexits.get(direction);
//    	if(direction.equals("north")) {
//            ret=northExit;
//        }
//        if(direction.equals("east")) {
//            ret=eastExit;
//        }
//        if(direction.equals("south")) {
//            ret=southExit;
//        }
//        if(direction.equals("west")) {
//            ret=westExit;
//        }
    }

    public String Room_Exit_Desc()
    {
    	StringBuffer sb=new StringBuffer();
    	for(String i:roomexits.keySet())
    	{
    		sb.append(i);
    		sb.append(" ");
    	}
    	return sb.toString();
//    	if(northExit != null)
//            sb.append("north ");
//        if(southExit != null)
//        	sb.append("south ");
//        if(eastExit != null)
//        	sb.append("east ");
//        if(westExit != null)
//        	sb.append("west ");
    }
    public void setExits(String direction,Room adroom) 
    {
    	roomexits.put(direction, adroom);
//        if(north != null)
//            northExit = north;
//        if(east != null)
//            eastExit = east;
//        if(south != null)
//            southExit = south;
//        if(west != null)
//            westExit = west;
    }

    @Override
    public String toString()
    {
        return description;
    }
}
