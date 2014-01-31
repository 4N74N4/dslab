#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int b_search(int n,int elt,int *A)
{
        int beg=0,last=n-1,mid;
        while(beg<=last)
        {
                mid=(beg+last)/2;
                if(A[mid] == elt)
                        return mid;
                else if(A[mid]<elt)
                        beg=mid+1;
                else
                        last=mid-1;
        }
        return -1;
}
int main()
{
        clock_t startTime = clock();
        int size,num,index,i;
        fstream f;
        f.open("binary.txt",ios::in);
        f>>size;
        int *A = new int[size];
        for(i=0;i<size;i++)
                f>>A[i];
        f>>num;
        f.close();
        index=b_search(size,num,A);
        cout<<index<<endl;
        delete [] A;
        cout << "Running Time : "<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0;
}

