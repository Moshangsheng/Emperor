 #include<stdio.h>
 #define MAX 6    //MAX 系统要求最大数量
 #include<string.h>   //字符串操作
 int main()
 {
     int i,j,count=5;  //count的意思是当前未打入冷宫的嫔妃个数
     int temp;
     int Index;   //数组的下标
     char emperorName[100];//使用字符数组表示字符串
     int choice;               //皇帝的选择1~4号
     char tempName[20];   //用来存放临时字符串的字符数组
     char names[MAX][50]={ "貂蝉","妲己","王昭君","西施","虞姬" };
     char levelNames[MAX][20] = {"贵人","嫔妃","贵妃","皇贵妃","皇后"}; //级别
     int levels[MAX] = {1,2,0,0,0,-1}; //用来存放每位妃子的级别，每个数组元素对应每个妃子的当前级别
     int loves [MAX]= {100,100,100,100,100,-1};  //每位妃子初始好感度

    printf("\n*******************************************************\n");
     printf("测试代码：查看当前嫔妃的状态\n");
     printf("姓名\t级别\t好感度\n");
     for(i=0; i<count; i++)
     {
         printf("%s\t%s\t%d\n",names[i], levelNames[levels[ i ]], loves[i]);
     }
     printf("\n*******************************************************\n");

     printf("请输入当前皇帝登基的名号：");
     scanf("%s",emperorName);  //字符串不需要&
     printf("皇帝《%s》驾临，有事上奏，无事退朝！\n",emperorName);
     printf("1、皇帝下旨选妃:\t\t（增加功能）\n");
     printf("2、翻牌宠幸！ \t\t\t（修改状态功能）\n");
     printf("3、打入冷宫！ \t\t\t（删除功能）\n");
     printf("4、单独召见爱妃去小树林做纯洁事\n");
     printf("陛下请做出选择：");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:   //皇帝下旨选妃:\t\t（增加功能）
                    //1.首先判断空间是否满    2、分别增加数组元素 levelName   levels   loves
                    if(count < MAX)  //如果当前妃子数量小于系统要求数量  就可以添加
                    {
                        printf("请输入娘娘的名讳：");
                        scanf("%s",names[count]);  //将第count元素的状态初始化
                        levels[count] = 0;      //级别初始度为零
                        loves[count] = 100;      //好感度初始度为零
                        count++;               //添加完毕后，记得计数器加一
                    }
                    else
                    {
                        printf("陛下注意龙体，后宫已经人满啦！ （添加失败）\n");
                    }

         break;
     case 2:    //翻牌宠幸！ \t\t\t（修改状态功能）
            // 1、找到要宠幸妃子的下标
            // 2、修改这个妃子的好感度+1  级别升级1  如果最高级就不升级
            // 3、修改其她妃子的好感度  由于羡慕嫉妒恨，其她妃子的好感度降10
            printf("陛下，请输入今天需要翻牌的娘娘名讳：");
            scanf("%s",tempName);   //用来存放临时字符串的字符数组
            //字符串的查找 需要引入《strcmp》
            //strcmp(tempName, names[i]) ==0)的含义是当等于零时两个字符串相等，1时是前一个大于后一个  -1是前一个小于后一个
            for(i=0; i<count; i++)
            {
                 if(strcmp(tempName, names[i]) ==0)  //如果输入的姓名刚好等于某个娘娘的名讳
                 {
                    loves[i] +=  10;
                    levels[i] = levels[i] >= 4 ? levels[i] = 4 : levels[i] + 1;
                 }
                 else
                 {
                    loves[i] -= 10;
                 }
            }
          break;
     case 3:    //打入冷宫！ \t\t\t（删除功能）
         //1、查找     2、找小标     3、后面一个赋给前面一个  4、修改其她妃子的状态
            printf("陛下， 打入冷宫娘娘是： \t\t\t（删除功能）：\n");
            scanf("%s",tempName);   //用来存放临时字符串的字符数组
            for( i=0; i<count; i++)
            {
                if(strcmp(tempName,names[i]) == 0)
                {
                    Index = i;
                    break;
                }
            }
            if(-1 == Index)
            {
                printf("\n虚惊一场，无人被打入冷宫\n");
            }
            else
                for(i=Index; i<count - 1; i++)
            {
                strcpy(names[i],names[i+1]);
                loves[i] = loves[i+1];
                levels[i] = levels[i+1];
            }

         break;
     case 4:   //单独召见爱妃去小树林做纯洁事
         //1.查找   2,、增加好感度
           printf("请输入要查找的姓名：");
            scanf("%s", tempName);
            for(i = 0; i < count; i++)
            {
                if(strcmp(tempName, names[i]) == 0)
                {
                    printf("\n%s的好感度+10\n\n", names[i]);
                    loves[i] += 10;
                    break;
                }
            }

         break;
     default :   //最后冒号排序  妃子状态  级别
        for(i=0; i<count-1; i++)
        {
            for(i=0; j<count-1-i; j++)
            {
                if(levels[j] < levels[j+1])
                {
                    temp = levels[j];
                    levels[j] = levels[j+1];
                    levels[j+1] = temp;
                    temp = loves[j];
                    loves[j] = loves[j+1];
                    loves[j+1] = temp;
                    strcpy(tempName,names[j]);  //字符串的交换
                    strcpy(names[j],names[j+1]);
                    strcpy(names[j+1],tempName);
                }
            }
        }
     }
     printf("\n*******************************************************\n");
     printf("测试代码：查看当前嫔妃的状态\n");
     printf("姓名\t级别\t好感度\n");
     for(i=0; i<count; i++)
     {
         printf("%s\t%s\t%d\n",names[i], levelNames[levels[ i ]], loves[i]);
     }
     printf("\n*******************************************************\n");
     return 0;
 }
