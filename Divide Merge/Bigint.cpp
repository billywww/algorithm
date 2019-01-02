/*head file*/

#include<iostream>
#include<vector>
using namespace std;

class Bigint{
  friend ostream& operator <<(ostream & os,const Bigint &bi){
    for(int i = bi.vec.size()-1;i >= 0;i--){
      os << bi.vec[i];
    }
    return os;
  }
public:
  Bigint() = default;
  Bigint(int x){
    if(x>0)
    while(x>0){
      vec.push_back(x%10);
      x = x/10;
    }
    else
      vec.push_back(x);
  }
  Bigint(int * arr,int n){
    for(int i = n-1;i>=0;i--){
      vec.push_back(arr[i]);
    }
  }
  /*        operator ==     */
  bool operator ==(Bigint r) const{
    if(vec.size()!=r.vec.size()){
      return false;
    }
    else{
      int k = 0;
      while(k<vec.size()){
        if(vec[k]!=r.vec[k])
          return false;
        k++;
      }
      return true;
    }
  }

 bool operator <(Bigint r) const{
   if(vec.size()<r.vec.size()) {
     return true;
   }
   else if(vec.size()>r.vec.size()){
     return false;
   }
   else{
     int k = vec.size();
     while(k>=0){
       if(vec[k]<r.vec[k])
        return true;
        k--;
     }
     return false;
   }
 }

  Bigint operator +(Bigint r) const{     //add two bigint
    int cf = 0;
    Bigint temp;
    int num1 = vec.size();
    int num2 = r.vec.size();
    int max = num1 > num2 ? num1 : num2;
    for(int i = 0;i < max;i++){
      int m = (i>=num1?0:vec[i]);
      int n = (i>=num2?0:r.vec[i]);
      temp.vec.push_back((m+n+cf)%10);
      cf = (m+n+cf)/10;
    }
    if (cf>0) temp.vec.push_back(1);
    return temp;
  }

  Bigint operator -(Bigint r) const{
    int num1 = vec.size();
    int num2 = r.vec.size();
    int max = num1>num2?num1:num2;
    if(num2>num1)
      return(Bigint(-1));

    int cf = 0;
    Bigint temp;
    for(int i = 0;i < max;i++){
      int m = (i>=num1?0:vec[i]);
      int n = (i>=num2?0:r.vec[i]);
      int cur;
      if(m-n-cf>=0){
        cur = m-n-cf;
        cf = 0;
      }
      else{
        cur = 10+m-n-cf;
        cf = 1;
      }
      temp.vec.push_back(cur);
    }
    if (cf>0) return(Bigint(-1));

    while(temp.vec.back() == 0 && temp.vec.size()>0)
      temp.vec.pop_back();
    return temp;

  }

  Bigint operator *(Bigint r) const{     //multiple two bigint
    int n1 = vec.size();
    int n2 = r.vec.size();
    int n3 = n1 + n2;
    int cf = 0;
    Bigint temp;
    temp.vec.resize(n1+n2);
    for(int i = 0;i<n1;i++){
      for(int j = 0;j<n2;j++){
        int m = vec[i]*r.vec[j]+cf;
        cf =( m + temp.vec[i+j])/10;
        temp.vec[i+j] = (m + temp.vec[i+j]) % 10;
      }
      if(cf > 0) temp.vec[i+n2] = cf;
      cf =0;
    }
    while(temp.vec.back() == 0 && temp.vec.size()>0)
      temp.vec.pop_back();
    return temp;
  }

  Bigint operator /(Bigint r) const{
    int n1 = vec.size();
    int n2 = r.vec.size();
    if(n1<n2) return(Bigint(0));
    Bigint count = 0;
    Bigint temp = *this-r;
    while(temp.vec[0]!=-1){
      count = count + Bigint(1);;
      temp = temp-r;
    }
    return count;
  }

private:
  vector<int> vec;
};
