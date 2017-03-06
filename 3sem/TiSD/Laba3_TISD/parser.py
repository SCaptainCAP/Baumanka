import random
import sys

len1=int(sys.argv[1])
print(len1)
books=[]

ls=["IT","WEB","MATH","FIZ","CS"]
for i in range(1,len1+1):
	book=[]
	book.append('Aвтор'+str(random.randint(1,9)))
	book.append('Название'+ str(i))
	book.append('Издательство'+str(random.randint(1,5)))
	book.append(random.randint(1,1000))
	t=random.randint(0,1)
	book.append(t)
	if t==0:
		otr=random.randint(0,4)
		book.append(ls[otr])
		book.append(random.randint(0,1))
		book.append(random.randint(0,2017))
	else:
		book.append(random.randint(0,2))
	books.append(book)
	for i in range(len(book)-1):
		print(book[i],sep='',end=' ')
	print(book[len(book)-1],sep='',end='')
	print()

