
class Solution {
public:
    bool isMatch(string s, string p) {


        s.insert(0,1,' ');
        p.insert(0,1,' ');
        int m = s.size();
        int n = p.size();
        int mark[n][m];

        for(int i = 0;i< m;i++){
          mark[0][i] = 0;
        }
        mark[0][0] = 1;


        for(int i = 1;i < n;i++){
          for(int j = 0;j < m;j++){
            if(p[i]=='*'){
              if(mark[i-2][j] == 1||(j>0&&mark[i][j-1]==1&&(p[i-1] == s[j]||p[i-1] =='.'))){
                mark[i][j] = 1;
              }
              else mark[i][j] = 0;
            }
            else{
              if(j>0&&mark[i-1][j-1] == 1&&(p[i] == s[j]||p[i] == '.'))
                mark[i][j] = 1;
              else mark[i][j] = 0;
            }

          }

        }
        return mark[n-1][m-1];
    }
};
