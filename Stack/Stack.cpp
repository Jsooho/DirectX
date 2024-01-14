#include <iostream>
#define Max_Size 10


using namespace std;

int g_arr[Max_Size];
int g_iTop;

void Create();
void Destroy();
void Push(int idata);
int Pop();
void Top();
bool Empty();
bool Full();

int main()
{
    Create();
    while (true)
    {
        int iSelect = 0;

        cout << "0.push, 1.top 2.pop 3. exit\n";
        cout << "select:";
        cin >> iSelect;

        switch (iSelect)
        {
        case 0:
        {
            int iData;
            std::cin >> iData;
            Push(iData);
        }break;
        case 1:
        {
            Top();
        }break;
        case 2:
        {
            int iData = Pop();
            if (iData >= 0)
            {
                std::cout << iData << "End!\n";
            }
            else
            {
                std::cout << "Empty\n";
            }
        }break;
        default:
            break;
        }


    }
    Destroy();


}

void Create()
{
    g_iTop = 0;
}
void Destroy()
{

}
void Push(int idata)
{
    if (Full()==false)
    {
        g_arr[g_iTop] = idata;
        g_iTop++;
    }

    
}
int Pop()
{
    
    if (Empty() == false)
    {   
        g_iTop--;
        return g_arr[g_iTop];
    }
    return -1;
}
void Top()
{    
        cout << g_arr[g_iTop-1] <<  endl;     
}
bool Empty()
{
    if (g_iTop == 0)
    {
        return true;
    }
    return false;
}
bool Full()
{
    if (g_iTop == Max_Size)
    {
        return true;
    }
    return false;
}