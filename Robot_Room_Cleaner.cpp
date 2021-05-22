/*
https://linlaw0229.github.io/2019/03/02/489-Robot-Room-Cleaner/
https://shibaili.blogspot.com/2018/09/489-robot-room-cleaner.html
https://wentao-shao.gitbook.io/leetcode/graph-search/489.robot-room-cleaner

Notice how the Robot's initial posintion doesn't matter here. Robot just need to be on an unblocked cell.
Time: 4^n; Not sure about this, it should be just 4n
n = total unblocked cell
Space: n



*/

    void goBack(Robot r) {
        r.turnRight();
        r.turnRight();
        r.move();
        r.turnRight();
        r.turnRight();
    }
    
    int dirs[4][2] = {-1,0, 0,1, 1,0, 0,-1}; // order matters here; up right down left
    
    void dfs(Robot robot, int r, int c, int dir) {
        visited[r][c] = 1;
        robot.clean();
        
        for(int i=0; i<4; ++i) {
            int u = r + dirs[dir][0]; // notice it is dir & not i
            int v = c + dirs[dir][1];
            
            if(!visited[u][v] && robot.move()) {
                dfs(robot, u, v, dir);
                goBack(); // cause move function actually moves to new posn & checks
            }
            
            robot.turnRight(); // actually change dircn
            dir = (dir+1) %4; // 0= up; 1 =right; 2 = down; 3 = left; not cur dirn
        }
    }
    
    void cleanRoom(Robot robot) {
        dfs(robot, 0, 0, 0);
    }
