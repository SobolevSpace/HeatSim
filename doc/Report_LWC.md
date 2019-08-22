# HeatSim分报告
李万成 3170104184

## 分工任务的解决方案
在本次项目的合作过程中，我主要承担common层和app层。由于我是组长，并且app层代码量较少，我还负责了项目了自动化部署构建，以及环境配置及测试。  
common层可以分成两个部分。一个是MVVM模型所需要的参数类型的定义和实现，另一部分则实现的是workboard（工作台）的各种方法。具体的实现细节将在下两章讲述。
自动化部署是通过GitHub上应用商店的AppVeyor实现的，自动测试也基于此。

## 设计思路
参数部分的设计比较简单，事先想好可能会用到的各种需要传递的参数，然后每一个参数都写一个类就好了。具体实现的参数有timeParameter, pointParameter, alphaParameter, 和padTimeParameter. 每个类都实现了基本的方法，包括构造函数、析构函数、赋值重载以及set和get方法，这四个类的结构都大同小异。timeParameter类的作用是供其他两个部分传递时间信息的，而其他三个参数也起到类似的效果，只不过传递的信息不同。  
workboard部分实现了3个类，分别是point, workboard, workboardPass 以及 1个枚举 CType。  
CType枚举类型表示材料。  
point表示一个物理意义上的点，有温度，材料两种属性。该类提供了一些普通的set、get方法，以及常用的运算符重载。  
workboard表示一个平板，由一个point类的阵列组成。提供了一些普通的set、get方法，并且实现了其与二维double矩阵的互相类型转换。  
workboardPass是由多个workboard构成的vector，表达的含义是workboard每一帧的状态。实现该类的目的是为了能够在model层只计算一次，就可以在前端快速的查询数据。  
app层实现view层和viewmodel层的绑定，绑定的数据包括共用一个heatViewModel。以及向viewmodel发送Property（包括点的材料，温度等）改变的通知，并绑定操作的调用。  

## 图表说明
timeParameters:
成员|属性|功能
-|-| -
int flameNo | private | 该参数表示当前是第几帧
timeParameters() | public | 构造函数
timeParameters(const timeParameters& ) | public | 构造函数
timeParameters(timeParameters&& ) | public | 构造函数
~timeParameters() | public | 析构函数
timeParameters& operator=(const timeParameters&) | public | 赋值重载
timeParameters& operator=(timeParameters&&) | public | 赋值重载
int get() | public | 暴露参数值
void set(int) | public | 修改参数值

由于其他Parameter的结构是类似的，在此不做过多介绍，pointParameter, alphaParameter和padTimeparameter class都提供了功能一致的方法。

point:
该数据结构表示物理意义上的一块区域（一个点），具有材料和温度两种属性。
成员| 属性 | 功能
-|-|-
double temperature| private | 表征该点的温度
CType propertyID | private | 表征该点的材料（决定其热传导的性质）
point()|public|构造函数
point(double temp)|public|构造函数，材料为默认值
point(double temp,CType c)|public|构造函数
~point()|public|析构函数
double getTemperature()|public|获得温度
CType getProperty()|public|获得材料
void setTemperature(double t)|public|设置温度
void setProperty(CType t)|public|设置材料

workboard:
该数据结构表示物理意义上的一块平板，在计算机中由一个point class的二维矩阵实现。
成员 | 属性 | 功能
-|-|-
int size|private|表示平板的大小
vector<vector<point>>|private|point class的二维矩阵
workboard()|public|构造函数
~workboard()|public|析构函数
int getSize()|public|返回size
workboard& operator=(const workboard& ) |public|赋值重载
void getPointMat(vector<vector<point>>&) |public|返回point class的二维矩阵

workboardPass:
该数据结构储存了workboard随时间变化的具体信息,供viewModel和View间传递用。
成员 | 属性 | 功能
-|-|-
workboard wb|private|工作台
CType changeType|private|改变的属性
double changeValue|private|改变的值
workboardPass()|public|构造函数
~workboardPass()|public|析构函数
CType getChangeType()|public|返回changeType的值
double getChangeValue()|public|返回changeValue的值
workboard getWorkboard()|public|返回workboard
void setChangeType(CType c)|public|设置changeType
void setChangeValue(double v) |public|设置changeValue
void setWorkboard(workboard& w)|public|设置workboard

## 运行效果图
自动部署流程：
![picture display wrong](https://github.com/SobolevSpace/HeatSim/blob/master/doc/Images/effect4-lwc.jpg?raw=true)
热场模拟：
![picture display wrong](https://github.com/SobolevSpace/HeatSim/blob/master/doc/Images/effect1-lwc.jpg?raw=true)
![picture display wrong](https://github.com/SobolevSpace/HeatSim/blob/master/doc/Images/effect2-lwc.jpg?raw=true)
均温曲线生成：
![picture display wrong](https://github.com/SobolevSpace/HeatSim/blob/master/doc/Images/effect3-lwc.jpg?raw=true)

## 心得体会
在本次小学期项目的开发中，我学习了软件开发中的几种框架。以前写程序考虑的问题是，用什么样的算法和数据结构，如何优化性能等等，对团队开发方面却没怎么想过。而该小学期给我最大的收获就是了解了框架这一开发模式。在此前的开发过程中，由于没有了解过框架相关的知识，团队开发经常是随意分工，没有效率（甚至不是MVC框架，耦合度非常高）。
在本次具体实践中，我们采用了MVVM框架进行开发，亲身感受了解耦合的必要性以及方法。虽然该课名为C++，但是在其中学到的MVVM框架模型，却可以在各种语言的团队合作开发中使用。这是超出C++的收获。
除此之外，我还更加深入的学习了C++，以前我所学习的C++就是C加上一个面向对象。但是在开发过程中，接触到了智能指针、右值引用等更多有意思的特性，让我觉得我的C++学习之路才刚刚入门。
在工具的使用上，我学习了GitHub应用商店中的appVeyor以进行自动化部署。虽然感觉这类工具的学习成本比较高（需要进行很多环境配置，如果要自动化测试的话还要写学习新的代码），但是把东西都配置好之后就能理解到自动化部署带来的好处————一有bug，及时发现。这省去了很多整合以及调试的时间。

## 改进意见
希望老师能够在讲课时将MVVM框架的例子程序讲得详细一些，因为这个对于后面合作开发还是很重要的，而且计院此前也没有讲过关于开发框架的课。当时听课的时候没有跟上，课后还是花了不少时间讨论、查阅资料与模仿才终于搞懂了那个bus的例程是怎么运行的。
关于工具的使用，如自动部署工具和版本控制工具，老师可以限定一个范围让同学们自由选择，这样的话班里使用同样工具的人就会多一些，遇到问题也好互相帮助。（因为有些环境配置的问题往往要花费不少时间，还容易无从下手）否则的话大家选择面太多，一方面不知道怎么选择，另一方面别人能给的帮助也比较有限。
