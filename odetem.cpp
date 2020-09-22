#include<iostream>
using namespace std;
////template <class T>
/*class punto{
    int x;
    int y;
public:
    punto(int xx=0, int yy=0){x=xx; y=yy;}
    int getX ()  { return x;}
    int getY ()  { return y;}
    void setX ( int xx) {x = xx ;}
    void setY (  int yy) {y = yy ;}
};*/

template<class  t, class u>
u desce(t i, t j)
{
    return i<j;
}

template<class  t, class u>
u  asce(t i, t j)
{
    return i>j;
}
 

template<class  t, class u>
void quicksort(t arr[], int izq, int der,u(*ptr)(t,t)) {//tener en cuenta el orden de los parametros

	int i = izq, j = der;
	t temp;
	t p = arr[(izq + der) / 2];
	while (i <= j) {
		while (ptr(p,arr[i]))i++;
		while (ptr(arr[j],p))j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (izq < j)
		quicksort<t, u>(arr, izq, j,ptr);
	if (i < der)
		quicksort<t, u>(arr, i, der,ptr);
}



int main()
{   
	bool (*ptr)(int, int);
    int arr[]={3,5,2,1,5,6,8,6,3,45,44,21,13,1};
    quicksort<int, bool>(arr,0,13,asce);
    
    for(int i=0;i<14;i++){
    cout<<arr[i];
    cout<<endl;
    }
    return 0;
  /*punto p(35,6);
    punto p1(6,6);
    punto p2(7,6);



    punto p3(4,6);
*/
}
