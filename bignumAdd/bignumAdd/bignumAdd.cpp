/*26-05-10 12:37
�����������������ĺ�,��100��1+100��2
˼·��������ʵ��
 1 ���ݵ����룺��cin���۱������ݣ����￼���û�ȡһ���ַ�����getchar(),ֻ�в����س�������������������
 2 ���ݵı��棺ÿ����һ���ַ��ͽ��б��棬��ס����Ŀ����ַ��ͣ�զ�죬���ַ���ASCII��ϵ���н����
 �ַ�'0'��ASCIIΪ������48,�����ȡһ���ַ�1,'1'=49,'1'-'0'=1,�����Ͱ���ת��Ϊ�������ˣ�Ȼ�󱣴�����
 ���У���0��ʼ��һλһλ�����ƣ�������λ����ǰ����λ�ں��ˣ������ñ�֤��λ��ʮλ�ֱ��������� 
  
 3 �߼��ӣ�������������ӿ��ܻ��н�λ����ν��������ӵ���������10(�ӷ��н�λֻ�����10)������һ��
 ���У��ڶ���ӵ���ȡģ�����λ����󣬰Ѹ�λ�ͽ�λ��ӣ����о���������֤��λ�͸�λ�ӣ�ʮλ��ʮλ��
 �����Ҫ���������±���м����� 
 4 �����ı��棺��󱣴����һ�����⣬���鳤�ȹ����������������û����ȫռ���꣬����Щ�������ô����
 ���Ҫ�������ĳ��� 
*/
#include<iostream>

using namespace std;
int main()
{
    int a[200] ={0} ;  //������� 
    int b[200] = {0};  //���汻���� 
    //i=1��j=1,? ��Ϊ���һλ��λҪһ���ֽڿռ䣬�����������ĵ�һ���ռ䲻��������ͱ���� 
    int i=1,j=1,k=0;   
    
    int result = 0;    //�����λ���ֵ 
    int g;              //��־����a[0],b[0]�Ƿ�Ϊ�ǿ� 
    
    cout<<"������ʾ������������������ĸ���򽫻���ֹ�˳���   "<<endl;
    cout<<"�����������"; 
    
	
    while ( (a[i]=getchar()) != 10 )    
    {
          if ( (a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z') )
          {
              exit(0);
          }
          else
          {
              a[i] = a[i]-'0';    //������õ�ASCII ��ļ��ɣ����ַ��ܺõ�ת����������ֵȻ�󱣴�����
                                  //���� 
              i++;
          }
    }
    
    cout<<"�����뱻������"; 
    while ( (b[j]=getchar()) !=10 )
    {
          if ( (b[j]>='a' && b[j]<='z') || (b[j]>='A' && b[j]<='Z') ) 
          {
               exit(1);
          }
          else
          {
              b[j] = b[j]-'0';
              j++;
          }
    }
 /*
   �����õ���һ�����ɣ�û�ж��屣������͵����飬����ֱ�������˱�������ͱ�����������
   ��Ȼ���������������ǵĳ��ȿ��ܲ�ͬ,���ﵱȻ�����ݳ�����һ��������Ϊ��׼�� 
   ���������λ�����ڱ���������Ѻ�ֵ�����ڼ����������У������෴�� 
 */  
    
    if (i>=j)     //����a�ĳ��ȴ��ڻ��������b�ĳ��� 
    {
        k = i;
        for (; j>0; )
        {
         /*a�������12��b��2 �����14
         1. result = 14/10=1 ��a[k-1](i��ĩ����һλ)=4  ��a��b�����±궼�Լ�1 ��ʱ��������� a[k-1]
         �Ͳ���ͬһֵ�ˣ���result��a[k-1]�Ӳ��԰�����Ҫ֪������10����λ�þ������λ��һλ��Ŷ 
          
         */ 
                result  = (a[k-1]+b[j-1])/10; 
                a[k-1]  = (a[k-1]+b[j-1])%10;
                k--;
                j--;
                a[k-1]  = a[k-1]+ result; 
        }
          
          if (a[0]==0)
          {
              g=1;
          }
          else
          {
              g=0;
          }
        cout<<"������ӽ��Ϊ��";
        
        /*  �͵ı���ͼ�����������һ���ģ���λ����ı����������λ��������һ�㣬����a[0]�ǿյģ�
        ��ʱ�����������Ӻ����һλû��λ������ͬ�������һ��0,���������g��Ϊ��׼�� 
        */ 
        for ( int h=g; h<i; h++ )
        {
            cout<<a[h]; 
        }
        cout<<endl;
    }
    
     
    else  //����a�ĳ��ȴ�С������b�ĳ��� ����ʱ��b������Ϊ��Ӻ�͵ı������� 
    {
        k=j;
        for (; i>0; )
        {
            result  = (a[i-1]+b[k-1])/10;
            b[k-1]  = (a[i-1]+b[k-1])%10;
            k--;
            i--;
            b[k-1]  = b[k-1]+ result; 
        }
        if (b[0]==0)
          {
              g=1;
          }
          else
          {
              g=0;
          }
         
        cout<<"������ӽ��Ϊ��";
        for ( int h=g; h<j; h++ )
        {
            cout<<b[h]; 
        }
        cout<<endl;
    }
        
    system("pause");
    return 0;
}