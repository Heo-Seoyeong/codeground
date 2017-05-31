
#include <stdio.h>

int Answer;

int main(void)
{
    int T, test_case;
    int arr[101] = { 0, };
    int a[20] = {0, };
    int b[20] = {0, };
    
    setbuf(stdout, NULL);
    
    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++){
        Answer = 1;
        
        int n, l;
        scanf("%d",&n);
        scanf("%d",&l);
        
        for (int i = 1; i<=l; i++) {
            scanf("%d %d", &a[i], &b[i]);
            arr[b[i]] = !(arr[a[i]]);
        }
        
        for (int i = 1; i <= l; i++) {
            if (arr[b[i]] == arr[a[i]]) {
                Answer = 0;
                break;
            }
        }
        
        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
    }
    
    return 0;//Your program should return 0 on normal termination.
}
