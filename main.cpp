#include <string>
#include <iostream>
#include <stdlib.h> //atoi関数
#include <string.h> //strlen関数
#include <list>
#include <map>
#include <vector>
#include <set>
#define _CRT_SECURE_NO_WARNINGS //sprintf関数、sscanf関数



//import
#include "lesson_package/talk/human.cpp"
#include <math.h>



//デフォルト引数
void menu(std::string entry="beef",std::string drink="beer",std::string dessert="ice");



//クラス
class Human
  {
  protected:
    std::string name;
  public:
    Human(std::string name)
    {
      this->name=name;
    }
    void say_something()
    {
      std::cout<<"I am "<<name<<". Hello."<<std::endl;
    }
    void run()
    {
      printf("run!\n");
    }
    ~Human()
    {
      printf("Good bye.\n");
    }
  };

  class HumanRobot:public Human
  {
  private:
  int number;
  public:
    HumanRobot(std::string name,int number):Human(name)
    {
      this->number=number;
    };
    void run()
    {
      printf("auto run(number is %d)!\n",number);
    };
    ~HumanRobot(){};
  };



//多重継承
class Person
{
public:
  void talk(){
    printf("talk\n");
  }
};
class Car
{
public:
  void run(){
    printf("run\n");
  }
};
class PersonCarRobot:public Person,public Car
{
public:
  void fly(){
    printf("fly\n");
  }
};



//インスタンス同士の演算
class A
{
private:
  int num;
public:
 A(){}/*C++には、引数を取るコンストラクタを独自に定義した場合に、デフォルトコンストラクタの暗黙的な定義が行われなくなるという特性がある。その状態でデフォルトコンストラクタを呼び出した場合には、やはりエラーが発生することとなる。対策としては、コンストラクタの明示的な定義を行う必要がある。*/
 A(int num)
 {
   this->num=num;
 }
 int getnum()
 {
   return num;
 }
 A operator +(const A &a)
 {
   A obj;
   obj.num=num+a.num;
   return obj;
 }
 A operator -(const A &a)
 {
   A obj;
   obj.num=num-a.num;
   return obj;
 }
 A operator *(const A &a)
 {
   A obj;
   obj.num=num*a.num;
   return obj;
 }
 A operator /(const A &a)
 {
   A obj;
   obj.num=num/a.num;
   return obj;
 }
};



//csvファイル
typedef struct 
{
  char title1[10];
  char title2[10];
  char name[32];
  int count;
}CSV_FILE_MEMBER;



int main(){

  // 型変換
    //char→int
    char num1='1';
    int new_num1 = num1-'0';

    //char[]→int
    char num2[]="123";
    int new_num2;
    new_num2=atoi(num2);

    char num3[]="123";
    int new_num3;
    sscanf(num3,"%d",&new_num3);

    //int→char
    int num4=1;
    char new_num4=num4+'0';

    //int→char[]
    int num5=123;
    char new_num5[10];
    sprintf(new_num5,"%d",num5);

    //string→int
    std::string num6="123";
    int new_num6;
    new_num6=atoi(num6.c_str());

    std::string num7="123";
    int new_num7;
    sscanf(num7.c_str(),"%d",&new_num7);



  //累乗
    int ruijo=1;
    for(int i=0;i<10;i++){
      ruijo*=2;
    }
    printf("2の10乗は%d\n",ruijo);



  //文字列の長さ
    char word[]="python";
    printf("pythonは%lu文字\n",strlen(word));

    std::string WORD="PYTHON";
    std::cout<<"PYTHONは"<<WORD.length()<<"文字"<<std::endl;



  //リストの要素数、追加、削除
    std::list<int> L={1,2,3,4,5}; //「g++ main.cpp -std=c++17」でコンパイルしないとエラーになる
    std::size_t size=L.size();
    std::cout<<"リストLの要素数は"<<size<<std::endl;
    L.push_front(0);
    L.push_back(6);
    L.pop_front();
    L.pop_back();
    L.remove(1);

    L.sort(std::greater<int>());
    printf("list→");
    for(int i:L){
      std::cout<<i<<" ";
    }
    printf("\n");



  //配列の要素数、ソート
    int l[]={1,2,3,4,5};
    int l_size=sizeof(l)/sizeof(int);
    printf("配列lの要素数は%d\n",l_size);
    for(int i=0;i<l_size;i++){
      for(int j=i+1;j<l_size;j++){
        if(l[i]<l[j]){
          int tmp=l[i];
          l[i]=l[j];
          l[j]=tmp;
        }
      }
    }
    printf("配列l→");
    for(int i=0;i<l_size;i++){
      printf("%d ",l[i]);
    }
    printf("\n");

  

  //辞書
    std::map<char,int> d={
      {'x',3000},
      {'y',2000}
    };
    std::cout<<"mapのxの値は"<<d['x']<<std::endl;

    std::vector<std::pair<char,int>> D;
    for(const auto &item:d){
      D.emplace_back(item);
    }
    std::sort(D.begin(),D.end(),[](const auto &x,const auto &y){return x.second<y.second;});
    printf("sorted map\n");
    for(const auto &[key,value]:D){
      std::cout<<key<<":"<<value<<std::endl;
    }

    d.erase('x');
    printf("Does 'x' exsist in map?→");
    if(d.find('y')!=d.end()){
      std::cout<<"True"<<std::endl;
    }
    d.clear();



  //集合
    std::set<int> s1={1,2,3,4,5};
    printf("set→");
    for(int i:s1){
      std::cout<<i<<" ";
    }
    s1.insert(6);
    s1.erase(6);
    s1.clear();
    printf("\n");



  //積集合、和集合、差集合
    std::set<int> s2={1,2,3,4,5};
    std::set<int> s3={3,4,5,6,7};
    std::set<int> sekishugo;
    std::set<int> washugo;
    std::set<int> sashugo;

    std::set_intersection(s2.begin(), s2.end(),
    s3.begin(), s3.end(),
    std::inserter(sekishugo, sekishugo.end()));
    printf("積集合→");
    std::for_each(sekishugo.begin(), sekishugo.end(), [](int x) {
    std::cout << x <<" ";
    });
    printf("\n");

    std::set_union(s2.begin(), s2.end(),
    s3.begin(), s3.end(),
    std::inserter(washugo, washugo.end()));
    printf("和集合→");
    std::for_each(washugo.begin(), washugo.end(), [](int x) {
    std::cout << x <<" ";
    });
    printf("\n");

    std::set_difference(s2.begin(), s2.end(),
    s3.begin(), s3.end(),
    std::inserter(sashugo, sashugo.end()));
    printf("差集合→");
    std::for_each(sashugo.begin(), sashugo.end(), [](int x) {
    std::cout << x <<" ";
    });
    printf("\n");



  //かつ、または
  int a=10,b=20;
  if(a>10&&b>10){
    printf("OK!\n");
  }else if(a>10||b>10){
    printf("SOSO\n");
  }
  printf("\n");



  //デフォルト引数
  menu("chiken","wine");
  printf("\n");



  //import
  say_hello();
  sing();
  cry();
  printf("\n");
  
  theta = M_PI;
  double ans = sin(theta)*sin(theta) + cos(theta)*cos(theta);
  printf(“%f”, ans)



  //defaultdict
  char sent[]="aassdfgttrreeeeeeee";

  std::map<char,int> defaultdict;
  for(int i=0;sent[i]!='\0';i++){
    if(defaultdict.find(sent[i])!=defaultdict.end()){
      defaultdict[sent[i]]++;
    }else{
      defaultdict[sent[i]]=1;
    }
  }
  for(const auto &[key,value]:defaultdict){
    std::cout<<key<<":"<<value<<std::endl;
  }



  //クラス
  Human* mike=new Human("Mike");
  mike->say_something();
  mike->run();
  delete mike;

  HumanRobot* dora=new HumanRobot("Doraemon",12345678);
  dora->say_something();
  dora->run();
  delete dora;
  printf("\n");
  


  //多重継承
  PersonCarRobot person_car_robot;
  person_car_robot.talk();
  person_car_robot.run();
  person_car_robot.fly();
  printf("\n");



  //インスタンス同士の演算
  A x(10),y(20);
  A z=x/y;
  std::cout<<z.getnum()<<std::endl;
  printf("\n");



  //ファイル操作
  char s[]="qasdfr\ndfghjn\nuytfdrftg";
  char data1[256],data2[3];
  FILE* f1=fopen("test.txt","w+");
  if(f1==NULL){
    printf("ファイルが開けません。\n");
  }else{
    int result=fprintf(f1,"%s",s);
    if(result==-1){
      printf("ファイルの書き込みに失敗しました。");
    }else{
      if(fseek(f1,0,SEEK_SET)!=0){
        printf("ファイルポジションの移動に失敗しました。\n");
      }else{
        while(fgets(data1,sizeof(data1),f1)!=NULL){
          printf("%s\n",data1);
        }
        fclose(f1);
      }
    }
  }

  FILE* f2=fopen("test.txt","r");
  if(f2==NULL){
    printf("ファイルが開けません。\n");
  }else{
    while(fgets(data2,sizeof(data2),f2)!=NULL){
      printf("%s\n",data2);
    }
  }
  printf("\n");



  //csvファイル
  CSV_FILE_MEMBER csv_file2_member;
  FILE* csv_file1=fopen("sample.csv","w");
  if(csv_file1==NULL){
    printf("ファイルが開けません。\n");
  }else{
    fprintf(csv_file1,"NAME,COUNT\n");
    fprintf(csv_file1,"A,1\n");
    fprintf(csv_file1,"B,2\n");
    fclose(csv_file1);
  }
  FILE* csv_file2 = fopen("sample.csv","r");
  if(csv_file2==NULL){
    printf("ファイルが開けません。\n");
  }else{
    if(fscanf(csv_file2,"%[^,],%s\n",csv_file2_member.title1,csv_file2_member.title2)==EOF){
      printf("ファイルを読み込めません。\n");
    }else{
      printf("%s %s\n",csv_file2_member.title1,csv_file2_member.title2);
      while(fscanf(csv_file2,"%[^,],%d\n",csv_file2_member.name,&(csv_file2_member.count))!=EOF){
        printf("%s %d\n",csv_file2_member.name,csv_file2_member.count);
      }
      fclose(csv_file2);
    }
  }

  return 0;
}

//デフォルト引数
void menu(std::string entry,std::string drink,std::string dessert){
  std::cout<<entry<<std::endl;
  std::cout<<drink<<std::endl;
  std::cout<<dessert<<std::endl;
}



/* int x;
int* p;
p = &x;
&x：xのアドレス
*(&x)：xの値
p：xのアドレス
*p：xの値

char x[];
char* p;
p = x;
&x[n]（0の省略不可）：xのn番目のアドレス（x + nでも可）
*(&x[n])（0の省略不可）：xのn番目の値（ *(x + n) でも可 ）
p + n：xのn番目のアドレス
*(p + n)：xのn番目の値

char型配列以外の配列では、終端を表す値を入れるのではなく、別途長さを受け渡しする形にすることが多いですね。→「リストの要素数」
char型配列とstring型は同じように扱えますね。

ビット演算（c/c++、python共通）
論理積：&
論理和：|
排他的論理和：^

char *argv[];
argv[n]：argvのn番目の文字「列」 */

//git
