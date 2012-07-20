#include <cstdio>
#include <iostream>
using namespace std;

int prime_table[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271,
277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359,
367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443,
449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619,
631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719,
727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821,
823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013
};



int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k))
    {
        if(n == 0 && k == 0)
        {
            break;
        }

        int larger = max(k, n - k);
        int small = n - larger;
        int sum = 1;

        int factor[200] = {0};

        for(int i = 2; i <= small; ++i)
        {
            int tmp = i;
            for(int j = 0; prime_table[j] <= tmp;++j)
            {
                while(tmp % prime_table[j] == 0)
                {
                    tmp /= prime_table[j];
                    ++factor[j];
                }
            }
        }

        for(int i = n; i > larger; --i)
        {
            int tmp = i;
            for(int j = 0; prime_table[j] <= tmp && j < 200; ++j)
            {
               while(factor[j] && tmp % prime_table[j] == 0)
               {
                   tmp /= prime_table[j];
                   --factor[j];
               }
            }
            sum *= tmp;
        }

        printf("%d\n", sum);
    }
}