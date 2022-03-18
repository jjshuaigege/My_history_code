students=[
    ('John','A',15),
    ("Mike","B",12),
    ("Mike","C",18),
    ("Bom","D",10)]
print(sorted(students,key=lambda x:x[1]))
print(sorted(students,key=lambda x:x[0]))
print(sorted(students,key=lambda x:x[2]))