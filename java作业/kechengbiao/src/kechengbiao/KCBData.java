package kechengbiao;

import javax.swing.event.TableModelListener;
import javax.swing.table.TableModel;

public class KCBData implements TableModel {
	private String[] title= {"周一","周二","周三","周四","周五","周六","周日"};
	private String[][] data=new String[12][7];
	public KCBData()
	{
		for(int i=0;i<12;i++)
			for(int j=0;j<7;j++)
			{
				data[i][j]="";
			}
	}
	@Override
	public int getRowCount() {
		return 12;
	}

	@Override
	public int getColumnCount() {
		return 7;
	}

	@Override
	public String getColumnName(int columnIndex) {
		return title[columnIndex];
	}

	@Override
	public Class<?> getColumnClass(int columnIndex) {
		// TODO Auto-generated method stub
		return String.class;
	}

	@Override
	public boolean isCellEditable(int rowIndex, int columnIndex) {
		// TODO Auto-generated method stub
		return true;
	}

	@Override
	public Object getValueAt(int rowIndex, int columnIndex) {
		return data[rowIndex][columnIndex];
	}

	@Override
	public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
	data[rowIndex][columnIndex]=(String)aValue;

	}

	@Override
	public void addTableModelListener(TableModelListener l) {
		System.out.println("收到消息！");

	}

	@Override
	public void removeTableModelListener(TableModelListener l) {
		// TODO Auto-generated method stub

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
