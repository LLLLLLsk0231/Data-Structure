int compressLeft(int arr[], int len) {
    int score = 0;
    
    // TODO: 第一步 - 将所有非零元素移到左边（去掉中间的0）
    int tmp=0;
    for(int i=0;i<4;i++){
        if(arr[i]!=0){
         arr[tmp]=arr[i];
         if (i!=tmp) arr[i]=0;
         tmp++;
        }
    }
    // TODO: 第二步 - 合并相邻的相同元素
    int j=0;
    for (int j=0;j<tmp-1;j++){
        if(arr[j]==arr[j+1]){
            arr[j]=arr[j]+arr[j+1];
            arr[j+1]=0;
        }
    }
    
    // TODO: 第三步 - 再次将非零元素移到左边
    int p=0;
    for(int i=0;i<tmp;i++){
        if(arr[i]!=0) {
        arr[p]=arr[i];
        if (p!=i) arr[i]=0;
        p++;
        }

    }
    for (int i=0;i<4;i++) {score+=arr[i];}
    return score;
}

// 向左移动
int moveLeft(int board[4][4]) {
    int score = 0;
    for (int i = 0; i < 4; i++) {
        score += compressLeft(board[i], 4);
    }
    return score;
}

// 向右移动
int moveRight(int board[4][4]) {
    int score = 0;
    // TODO: 提示 - 可以先把每行翻转，调用 compressLeft，再翻转回来;
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
          int tmp;
          tmp=board[i][j];
          board[i][j]=board[i][3-j];
          board[i][3-j]=tmp;
        }
        score+=compressLeft(board[i],4);
        for(int j=0;j<2;j++){
            int tmp;
            tmp=board[i][j];
            board[i][j]=board[i][3-j];
            board[i][3-j]=tmp;
        }
    }

    return score;
}

// 向上移动
int moveUp(int board[4][4]) {
    int score = 0;
    // TODO: 提示 - 可以提取每一列作为临时数组，调用 compressLeft，再放回去
    for(int col=0;col<4;col++){
        int column[4];
        for(int row=0;row<4;row++){
            column[row]=board[row][col];
        }
        score+=compressLeft(column,4);
        for(int row=0;row<4;row++){
            board[row][col]=column[row];
        }
    }
    
    return score;
}

// 向下移动
int moveDown(int board[4][4]) {
    int score = 0;
    // TODO: 提示 - 类似向上，但需要先翻转列
    for(int col=0;col<4;col++){
        int column[4];
        for(int row=0;row<4;row++){
            column[row]=board[row][col];
        }
        for(int j=0;j<2;j++){
            int tmp=column[j];
            column[j]=column[3-j];
            column[3-j]=tmp;
        }
        score+=compressLeft(column,4);
        for(int j=0;j<2;j++){
            int tmp=column[j];
            column[j]=column[3-j];
            column[3-j]=tmp;
        }
        for(int row=0;row<4;row++){
            board[row][col]=column[row];
        }
    }
    
    return score;
}
