class Solution {
public:
      vector<int> NSE(vector<int> v){
        vector<int> nse(v.size());
        stack<int> st;
        int n = v.size() ;
        for(int i=0;i<v.size();i++){
            while(!st.empty() && v[i]<v[st.top()]){
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nse[st.top()] = n ; 
            st.pop();
        }        
       
        return nse;
    }

    vector<int> PSE(vector<int> v){
        vector<int> pse(v.size());
        stack<int> st;
        int n = v.size() ;
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && v[i]<v[st.top()]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            pse[st.top()] = -1 ; 
            st.pop();
        }        
        return pse;
    }



    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = NSE(heights) ;
        vector<int> pse = PSE(heights) ;


        int sum = -1 ;
    

        for( int i=0; i < heights.size() ; ++i){
           

            int temp = (nse[i] - pse[i] - 1 ) * heights[i] ;
            if( temp > sum){
                sum = temp ;
            }
        }
        return sum;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<int> sum (matrix[0].size()) ; 
        int maxi= -1 ;

        for( int i=0;i<matrix.size() ; i++){
            for( int j=0; j<matrix[0].size() ; j++){
                int k = i ;
                sum[j] = 0 ;
                while( k>=0){
                    if(matrix[k][j]== '0'){
                        break;
                    }
                    sum[j]+= (matrix[k][j] - '0') ;
                    k--;
                }

            }
        
            int temp = largestRectangleArea(sum) ;
            maxi = (temp > maxi) ? temp : maxi; 
        }
        return maxi ;
    }
};