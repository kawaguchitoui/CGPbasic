def main():

  """型変換"""
  """char→int"""
  num1='1'
  new_num1=int(num1)

  """char[](string)→int"""
  num2='123'
  new_num2=int(num2)

  """int→char"""
  num3=1
  new_num3=str(num3)

  """int→char[](string)"""
  num4=123
  new_num4=str(num4)



  """累乗"""
  print("2の10乗は",2**10)



  """文字列の長さ"""
  word='python'
  print("pythonは",len(word),"文字")



  # s='yES'
  # print(s.capitalize())
  # """Yesと出力される"""



  """リストの要素数、追加、削除、ソート"""
  l=[1,2,3,4,5]
  print("リストlの要素数は",len(l))
  l.insert(0,0) """インデックス番号、　追加したい要素"""
  l.append(6)
  l.pop(0) """インデックス番号"""
  l.pop() """インデックス番号を指定しなければ、一番後ろが消える"""
  l.remove(1) """消したい要素"""

  l.sort(reverse=True) """l=l.sort()は不可"""
  print("sorted list→",l)
  l.sort(reverse=False)
  print("sorted list→",sorted(l, reverse=True)) """l=sorted(l)は可"""


  """辞書"""
  d={
    'x':3000,
    'y':2000,
  }
  print("mapのxの値は",d['x'])

  print("unsorted map\n",d)
  print("sorted map\n",sorted(d,key=d.get,reverse=False)) """d.sort()は不可、d.get('x')だとxが存在する場合は対応する値3000が返り、xが存在しない場合はNoneが返る。None以外の値を返したい場合は、第二引数にxが存在しない場合に返すデフォルト値を指定する。"""

  d.pop('x')
  """またはdel d['x']"""
  print("Does 'x' exsist in map?→",'y' in d)
  d.clear()



  """集合"""
  s1={1,2,3,4,5}
  print("set→",s1)
  s1.add(6)
  s1.remove(6)
  s1.clear()



  """積集合、和集合、差集合"""
  s2={1,2,3,4,5}
  s3={3,4,5,6,7}
  print("積集合→",s2&s3)
  print("和集合→",s2|s3)
  print("差集合→",s2-s3)



  """かつ、または"""
  a=10
  b=20
  if a>10 and b>10:
    print("OK!")
  elif a>10 or b>10:
    print("SOSO")
    print("")



  """デフォルト引数"""
  def menu(entry="beef",drink="beer",dessert="ice"):
    print(entry)
    print(drink)
    print(dessert)

  menu("chiken",drink="wine")
  print("")



  """引数がいくつになるかわからない時"""
  def say_something(*args):
    for arg in args:
      print(arg)
  say_something("GoodMorning","GoodAfternoon","GoodNight")
  print("")



  """キーワード引数の辞書化"""
  def food_menu(**kwargs):
    print(kwargs)
  food_menu_dict={
    "entry":"salada",
    "drink":"beer",
    "dessert":"ice",
  }
  food_menu(**food_menu_dict)

  def new_food_menu(food,*args,**kwargs):
    print(food)
    print(args)
    print(kwargs)
  new_food_menu("sashimi","chiken","tenpura",drink="beer",dessert="ice")
  print("")



  """import"""
  from lesson_package.talk import human
  human.utils.say_hello()
  human.sing()
  human.cry()
  print("")
  
  import math
  theta = math.pi / 2
  ans = math.sin(theta)**2 + math.cos(theta)**2
  print(ans)



  """defaultdict"""
  sent="aassdfgttrreeeeeeee"

  d={}
  for alpha in sent:
    if alpha not in d:
      d[alpha]=0
    d[alpha]+=1
  print(d)

  d={}
  for alpha in sent:
    d.setdefault(alpha,0)
    d[alpha]+=1
  print(d)

  d={}
  for alpha in sent:
    d[alpha]=d.get(alpha,0)+1
  print(d)

  from collections import defaultdict
  d=defaultdict(int)
  for alpha in sent:
    d[alpha]+=1
  print(d)
  print("")



  """term color"""
  from termcolor import colored
  print(colored("Hello,World!","magenta","on_green",["concealed"]))



  """クラス"""
  class Human(object):
    def __init__(self,name):
        self.name=name
    def run(self):
      print("run!")
    def say_something(self):
      print(f"I am {self.name}. Hello.")
    def __del__(self):
      print("Good bye.")

  mike=Human("Mike")
  mike.say_something()
  mike.run()
  del mike

  class HumanRobot(Human):
    def __init__(self, name, number):
        super().__init__(name)
        self.__number=number
    def run(self):
      print(f"auto run(number is {self.__number})!")

  dora=HumanRobot("Doraemon",12345678)
  dora.say_something()
  dora.run()
  del dora
  print("")



  """多重継承"""
  class Person(object):
    def talk(self):
      print("talk")
  class Car(object):
    def run(self):
      print("run")
  class PersonCarRobot(Person,Car):
    def fly(self):
      print("fly")

  person_car_robot=PersonCarRobot()
  person_car_robot.talk()
  person_car_robot.run()
  person_car_robot.fly()
  print("")



  """インスタンスを文字列として扱う"""
  class PersonA(object):
    def __init__(self,name,age):
        self.name=name
        self.age=age
  class PersonB(PersonA):
    def __str__(self):
        return "私は%d歳の%sです"%(self.age,self.name)

  a=PersonA("花子",20)
  b=PersonB("太郎",20)
  print(a)
  print(b)
  print("")



  """インスタンス同士の演算"""
  class A(object):
    def __init__(self,num):
        self.num=num
    def __add__(self,obj):
      return self.num+obj.num
    def __sub__(self,obj):
      return self.num-obj.num
    def __mul__(self,obj):
      return self.num*obj.num
    def __truediv__(self,obj):
      return self.num/obj.num
  x=A(10)
  y=A(20)
  z=A(x/y)
  print(z.num)
  print("")



  """ファイル操作"""
  s="qasdfr\ndfghjn\nuytfdrftg"
  with open("test.txt","w+") as f:
    f.write(s)
    f.seek(0)
    while True:
      line=f.readline()
      print(line,end="")
      if not line:
        break
  print("")

  with open("test.txt","r") as f:
    while True:
      chunk=2
      line=f.read(chunk)
      print(line)
      if not line:
        break
  


  """テンプレート"""
  import string
  with open('design/email.txt','r') as f:
    t=string.Template(f.read())
  content=t.substitute(name='Mike',contents='How are you?')
  print(content)



  """CSVファイル"""
  import csv
  with open('sample.csv','w') as csv_file:
    fieldnames=['NAME','COUNT']
    writer=csv.DictWriter(csv_file,fieldnames=fieldnames)
    writer.writeheader()
    writer.writerow({'NAME':'A','COUNT':1})
    writer.writerow({'NAME':'B','COUNT':2})
  with open('sample.csv','r') as csv_file:
    reader=csv.DictReader(csv_file)
    for row in reader:
      print(row['NAME'],row['COUNT'])
  
  
  
  """日付や時刻"""
  import datetime

  now=datetime.datetime.now()
  print(now.strftime("%H:%M"))

  today=datetime.date.today()
  print(today.strftime("%y/%m/%d"))

  d=datetime.timedelta(days=365)
  print((today-d).strftime("%y/%m/%d"))

  t=datetime.time(hour=1,minute=2,second=3)
  print(t.strftime("%H_%M_%S"))

  import time
  time.sleep(1)
  print(time.time()) #エポックタイム

      
      
if __name__=='__main__':
  main()
  
  
  
"""testpy-testpy2 -test.py
         -text    -hello.txt"""
import os

current_file_path=os.path.abspath(__file__)        #test.py
super_dir=os.path.dirname(current_file_path)       #testpy2
superior_dir=os.path.dirname(super_dir)            #testpy
text_dir=os.path.join(superior_dir,'text')         #text
hello_file_path=os.path.join(text_dir,'hello.txt') #hello.txt



"""独自例外"""
class OriginalError(Exception):
  pass

raise OriginalError('メッセージ')



"""pytest"""
"""基本"""
def add_num(num1, num2):
  return num1+num2

def test_add_num():
  result = add_num(1,2)
  assert result == 3
  
"""クラスを使う"""
#class TestFunc(object):
#  def setup_method(self):
#    テストを行う前に行いたい処理（インスタンス生成など）があれば、ここに書く
    
#   @pytest.mark.skip(reason='') テストをスキップしたい場合
#   def test_func(self)
#　   処理

#   def test_find_document_raise():
#     with pytest.raises(console.NoDocumentError):
#       処理



"""
sample.pyの__name__は、sample
hello.pyの__name__は、hello

ただし、python sample(hello).pyで実行した場合、__name__は、main
"""

"""git"""
