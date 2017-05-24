/*
 You should use the statndard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <stdio.h>
#define max(a, b) (a > b ? a : b);
#define min(a, b) (a > b ? b : a);


int Answer;
int cost[100][100][1195];
int save[100][100][1195];

int main(void){
    
    int T, test_case;
    
    int N;
    int num, res;
    int room[100][100][2];
    int temp;
    int two, three;
    int i, j, l, k;
    /*
     The freopen function below opens input.txt file in read only mode, and afterward,
     the program will read from input.txt file instead of standard(keyboard) input.
     To test your program, you may save input data in input.txt file,
     and use freopen function to read from the file when using scanf function.
     You may remove the comment symbols(//) in the below statement and use it.
     But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */
    // freopen("input.txt", "r", stdin);
    
    /*
     If you remove the statement below, your program's output may not be rocorded
     when your program is terminated after the time limit.
     For safety, please use setbuf(stdout, NULL); statement.
     */
    setbuf(stdout, NULL);
    
    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++){
        scanf("%d", &N);
        
        for (i=0; i<N; i++) {
            for (j=0; j<N; j++) {
                scanf("%d", &num);
                two = three = 0;
                while (num % 2 == 0) {
                    two++;
                    num /= 2;
                }
                while (num % 3 == 0) {
                    three++;
                    num /= 3;
                }
                room[i][j][0] = two;
                room[i][j][1] = three;
            }
        }
        
        temp = room[0][0][1];
        cost[0][0][temp] = room[0][0][0];
        save[0][0][temp] = 1;
        for (j = 1; j < N; j++){ //0행 값 입력
            cost[0][j][temp + room[0][j][1]] = cost[0][j - 1][temp] + room[0][j][0];
            save[0][j][temp + room[0][j][1]] = 1;
            temp = temp + room[0][j][1];
        }
        
        temp = room[0][0][1];
        for (i = 1; i < N; i++){ //0열 값 입력
            cost[i][0][temp + room[i][0][1]] = cost[i - 1][0][temp] + room[i][0][0];
            save[i][0][temp + room[i][0][1]] = 1;
            temp = temp + room[i][0][1];
        }
        
        
        for (k = 2; k < 2 * (N - 1); k++){ //0행 값 입력
            for (i = 0; i < k; i++){
                j = k - i;
                if (i < N && j < N){
                    for(l = 0; l < 6 * k; l++) {
                        if (save[i-1][j][l] == 1){
                            cost[i][j][l + room[i][j][1]] = max(cost[i - 1][j][l] + room[i][j][0], cost[i][j][l + room[i][j][1]]);
                            save[i][j][l + room[i][j][1]] = 1;
                        }
                        if (save[i][j-1][l] == 1){
                            cost[i][j][l + room[i][j][1]] = max(cost[i][j - 1][l] + room[i][j][0], cost[i][j][l + room[i][j][1]]);
                            save[i][j][l + room[i][j][1]] = 1;
                        }
                    }
                }
                
            }
        }
        
        Answer = 0;
        res = 0;
        
        
        for (i = 0; i < 1195; i++) {
            if (save[N - 1][N - 1][i]){
                res = min(cost[N - 1][N - 1][i],i);
                Answer  = max(res, Answer);
            }
        }
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
         Implement your algorithm here.
         The answer to the case will be stored in variable Answer.
         */
        /////////////////////////////////////////////////////////////////////////////////////////////
        
        // Print the answer to standard output(screen).
        
        
        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                for (l = 0; l < 1195; l++){
                    cost[i][j][l] = 0;
                    save[i][j][l] = 0;
                }
            }
        }
    }
    
    return 0;//Your program should return 0 on normal termination.
}
