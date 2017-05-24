
#include <stdio.h>

int Answer;

int main(void)
{
    int T, test_case;
    int arr[101] = { 0, };
    int a, b;
    
    setbuf(stdout, NULL);
    
    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++){
        Answer = 1;
        
        int n, l;
        scanf("%d",&n);
        scanf("%d",&l);
        
        for (int i = 0; i<l; i++) {
            scanf("%d %d", &a, &b);
            arr[a] = !arr[b];
            if (arr[a] == arr[b]) {
                Answer = 0;
            }
        }
        
        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
    }
    
    return 0;//Your program should return 0 on normal termination.
}
