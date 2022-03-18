class Employee:
    total_salary=0                         #静态属性(变量)
    def __init__(self,name,income):
        self.name=name
        self.income=income
    def get_payed(self,salary):
        self.income+=salary
        Employee.total_salary+=salary
    @staticmethod                          #静态方法
    def print_total_salary():
        print(Employee.total_salary)


e1=Employee("jack",0)
e2=Employee("Mary",0)
e1.get_payed(150)
e2.get_payed(200)
e1.get_payed(300)
e2.get_payed(200)
e1.print_total_salary()
Employee.print_total_salary()
