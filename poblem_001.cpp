#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    vector<float> vols = {0, 0.77, 1.10, 3.4, 7};
    vector<float> blocks = {-1,0,0,0,0};
    vector<int> nums={-1,0,0,0,0}, ans = {-1,0,0,0,0};
    float targ = 15, min_diff = targ, curr_tail = targ;
    bool finish = false;
    int tmp = 1, msize = 5;;
    while(!finish)
    {
        while (tmp < msize) {
            while (vols[tmp] < curr_tail)
            {
                blocks[tmp] += vols[tmp];
                curr_tail -= vols[tmp];
            }
            tmp++;
        }
        if (min_diff > curr_tail) {
            min_diff = curr_tail;
            for (int i = 1; i < msize; ++i)
            {
                ans[i] = nums[i];
            }
        }
        tmp = msize - 1;
        nums[tmp] = 0;
        curr_tail += blocks[tmp];
        blocks[tmp] = 0;
        while (blocks[tmp] = 0) {tmp--;}
        if (tmp = 0) {finish = true;}
        else {
            nums[tmp]--;
            blocks[tmp] -= vols[tmp];
            curr_tail += vols[tmp];
            tmp++;
        }
    }

    cout << "\n Minimal error is " << min_diff << " which is attainable on ";
    for (int i = 1; i < msize; ++i)
    {
        cout << ans[i] << " ";    
    }
    cout << endl; 

    return 0;
}

/**
    stack seq;
    int max = 3, tmp = max, tmp2 = 0;
    bool finish = false;
    while (!finish)
    {
        while (curr_sum + vols[tmp] <= targ)
        {
            curr_sum += vols[tmp];
            seq.push(tmp);
        }
        if (min_diff > targ - curr_sum) min_diff = targ - curr_sum;
        if (min_diff == 0) break;
        if (tmp > 0 && targ - curr_sum > vols[tmp-1]) {tmp--;} 
        else
        {
            tmp = seq.pop();
            curr_sum -= vols[tmp];
            while (tmp2 == seq.pop())
            {

            }
        } 
    }
    //**/