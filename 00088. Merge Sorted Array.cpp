
//Accepted	40 ms	cpp
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for(int i=0;i<n;i++)
        {
            int key = B[i];
            int index = m;
            int j = m-1;
            while(j>-1 && A[j] > key)
            {
                A[index] = A[j];
                index = j;
                j--;
            }
            A[j+1] = key;
            m++;
        }
    }
};
