import datetime
class student:
    def __init__(self,id,name,gender,birth_year):
        self.id=id
        self.name=name
        self.gender=gender
        self.birth_year=birth_year
    def count_age(self):
        return datetime.datetime.now().year-self.birth_year
    def print_info(self):
        print(self.id,self.name,self.gender,self.birth_year)
class undergraduate_student(student):
    def __init__(self,id,name,gender,birth_year,department):
        student.__init__(self,id,name,gender,birth_year)
        self.department=department
    def print_introd(self):
        print("{:} is from {:}".format(self.name,self.department))
    def print_info(self):
        student.print_info(self)
        print(self.department)
p1=undergraduate_student(5835,"sgz","male",1998,"CS")
print(p1.gender)
print(p1.count_age())
p1.print_introd()
p1.print_info()