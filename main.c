 #include<stdio.h>
 #define MAX 6    //MAX ϵͳҪ���������
 #include<string.h>   //�ַ�������
 int main()
 {
     int i,j,count=5;  //count����˼�ǵ�ǰδ�����乬����������
     int temp;
     int Index;   //������±�
     char emperorName[100];//ʹ���ַ������ʾ�ַ���
     int choice;               //�ʵ۵�ѡ��1~4��
     char tempName[20];   //���������ʱ�ַ������ַ�����
     char names[MAX][50]={ "����","槼�","���Ѿ�","��ʩ","�ݼ�" };
     char levelNames[MAX][20] = {"����","����","����","�ʹ���","�ʺ�"}; //����
     int levels[MAX] = {1,2,0,0,0,-1}; //�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
     int loves [MAX]= {100,100,100,100,100,-1};  //ÿλ���ӳ�ʼ�øж�

    printf("\n*******************************************************\n");
     printf("���Դ��룺�鿴��ǰ������״̬\n");
     printf("����\t����\t�øж�\n");
     for(i=0; i<count; i++)
     {
         printf("%s\t%s\t%d\n",names[i], levelNames[levels[ i ]], loves[i]);
     }
     printf("\n*******************************************************\n");

     printf("�����뵱ǰ�ʵ۵ǻ������ţ�");
     scanf("%s",emperorName);  //�ַ�������Ҫ&
     printf("�ʵۡ�%s�����٣��������࣬�����˳���\n",emperorName);
     printf("1���ʵ���ּѡ��:\t\t�����ӹ��ܣ�\n");
     printf("2�����Ƴ��ң� \t\t\t���޸�״̬���ܣ�\n");
     printf("3�������乬�� \t\t\t��ɾ�����ܣ�\n");
     printf("4�������ټ�����ȥС������������\n");
     printf("����������ѡ��");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:   //�ʵ���ּѡ��:\t\t�����ӹ��ܣ�
                    //1.�����жϿռ��Ƿ���    2���ֱ���������Ԫ�� levelName   levels   loves
                    if(count < MAX)  //�����ǰ��������С��ϵͳҪ������  �Ϳ������
                    {
                        printf("��������������䣺");
                        scanf("%s",names[count]);  //����countԪ�ص�״̬��ʼ��
                        levels[count] = 0;      //�����ʼ��Ϊ��
                        loves[count] = 100;      //�øжȳ�ʼ��Ϊ��
                        count++;               //�����Ϻ󣬼ǵü�������һ
                    }
                    else
                    {
                        printf("����ע�����壬���Ѿ��������� �����ʧ�ܣ�\n");
                    }

         break;
     case 2:    //���Ƴ��ң� \t\t\t���޸�״̬���ܣ�
            // 1���ҵ�Ҫ�������ӵ��±�
            // 2���޸�������ӵĺøж�+1  ��������1  �����߼��Ͳ�����
            // 3���޸��������ӵĺøж�  ������Ľ���ʺޣ��������ӵĺøжȽ�10
            printf("���£������������Ҫ���Ƶ��������䣺");
            scanf("%s",tempName);   //���������ʱ�ַ������ַ�����
            //�ַ����Ĳ��� ��Ҫ���롶strcmp��
            //strcmp(tempName, names[i]) ==0)�ĺ����ǵ�������ʱ�����ַ�����ȣ�1ʱ��ǰһ�����ں�һ��  -1��ǰһ��С�ں�һ��
            for(i=0; i<count; i++)
            {
                 if(strcmp(tempName, names[i]) ==0)  //�������������պõ���ĳ�����������
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
     case 3:    //�����乬�� \t\t\t��ɾ�����ܣ�
         //1������     2����С��     3������һ������ǰ��һ��  4���޸��������ӵ�״̬
            printf("���£� �����乬�����ǣ� \t\t\t��ɾ�����ܣ���\n");
            scanf("%s",tempName);   //���������ʱ�ַ������ַ�����
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
                printf("\n�龪һ�������˱������乬\n");
            }
            else
                for(i=Index; i<count - 1; i++)
            {
                strcpy(names[i],names[i+1]);
                loves[i] = loves[i+1];
                levels[i] = levels[i+1];
            }

         break;
     case 4:   //�����ټ�����ȥС������������
         //1.����   2,�����Ӻøж�
           printf("������Ҫ���ҵ�������");
            scanf("%s", tempName);
            for(i = 0; i < count; i++)
            {
                if(strcmp(tempName, names[i]) == 0)
                {
                    printf("\n%s�ĺøж�+10\n\n", names[i]);
                    loves[i] += 10;
                    break;
                }
            }

         break;
     default :   //���ð������  ����״̬  ����
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
                    strcpy(tempName,names[j]);  //�ַ����Ľ���
                    strcpy(names[j],names[j+1]);
                    strcpy(names[j+1],tempName);
                }
            }
        }
     }
     printf("\n*******************************************************\n");
     printf("���Դ��룺�鿴��ǰ������״̬\n");
     printf("����\t����\t�øж�\n");
     for(i=0; i<count; i++)
     {
         printf("%s\t%s\t%d\n",names[i], levelNames[levels[ i ]], loves[i]);
     }
     printf("\n*******************************************************\n");
     return 0;
 }
