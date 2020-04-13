#include<iostream>
#include<math.h>
using namespace std;
const double PI=3.141592;
class Circle
{
public:
    void setDate(int aX,int aY,int aR);//�������ݳ�Ա��ֵ
    void displayData();//������ݳ�Ա
    int getR();//�õ�Բ�İ뾶
    int getX();//�õ�Բ��X����
    int getY();//�õ�Բ��Y����
    double culArea();//��Բ�����
private:
    int m_iX;
    int m_iY;
    int m_iR;
};
void Circle::setDate(int aX,int aY,int aR)
{
    m_iX=aX;m_iY=aY;m_iR=aR;
}
void Circle::displayData()
{
    cout<<m_iX<<m_iY<<m_iR<<endl;
}
int Circle::getR()
{
    return m_iR;
}
int Circle::getX()
{
    return m_iX;
}
int Circle::getY()
{
    return m_iY;
}
double Circle::culArea()
{
    double s;
    s=PI*m_iR*m_iR;
    s=s*1.0000;
    return s;
}
bool funJudge(Circle c1,Circle c2)
{
    double k,m,n;
    double i,l;
    k=(c1.getX()-c2.getX())*(c1.getX()-c2.getX()); 
    m=(c1.getY()-c2.getY())*(c1.getY()-c2.getY());
    n=k+m;
    i=sqrt(n);
    if(c1.getR()>=c2.getR())
        l=(c1.getR()>=c2.getR())?(c1.getR()-c2.getR()):(c2.getR()-c1.getR());
    
    if((i<(c1.getR()+c2.getR()))&&(i>l))
    {
        return true;
    }
    else
    {
        return false;
        
    }
}
int main(void)
{
    Circle A;
    cout<<"�������һ��Բc1������X��Y�Ͱ뾶R��Ϣ��"<<endl;
    int a,b,c;
    cin>>a>>b>>c;
    A.setDate(a,b,c);
    cout<<"Position:"<<"("<<a<<","<<b<<")"<<"R="<<c<<" "<<"Area="<<A.culArea()<<endl;
    Circle B;
    cout<<"������ڶ���Բc2������X��Y�Ͱ뾶R��Ϣ��"<<endl;
    int d,e,f;
    cin>>d>>e>>f;
    B.setDate(d,e,f);
    cout<<"Position:"<<"("<<d<<","<<e<<")"<<"R="<<f<<" "<<"Area="<<B.culArea()<<endl;
    
    if(funJudge(A,B))
    {
        cout<<"����Բ�ཻ!"<<endl;
    }
    else
    {
        cout<<"����Բ���ཻ!"<<endl;
    }

    return 0;
}
